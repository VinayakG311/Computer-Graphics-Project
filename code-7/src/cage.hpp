
#include <glm/gtc/type_ptr.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>
#include <iostream>
using namespace std;
class Cage
{
private:
    int grid[100][100];

    GLfloat max_x_coord = INT_MIN;
    GLfloat max_y_coord = INT_MIN;

    GLfloat min_x_coord = INT_MAX;
    GLfloat min_y_coord = INT_MAX;

    GLfloat min_z_coord = INT_MAX;
    GLfloat max_z_coord = INT_MIN;

public:
    vector<float> cage;
    vector<float> controlPoints;
    Cage() {}
    int createCage(unsigned int &program, unsigned int &obj_VAO)
    {
        glUseProgram(program);

        // Bind shader variables
        int vVertex_attrib = glGetAttribLocation(program, "vVertex");
        if (vVertex_attrib == -1)
        {
            fprintf(stderr, "Could not bind location: vVertex\n");
            exit(0);
        }

        vector<float> v;
        cage.push_back(min_x_coord - 0.2);
        cage.push_back(min_y_coord - 0.2);
        cage.push_back(min_z_coord - 0.2);

        cage.push_back(min_x_coord - 0.2);
        cage.push_back(max_y_coord + 0.2);
        cage.push_back(min_z_coord - 0.2);

        cage.push_back(min_x_coord - 0.2);
        cage.push_back(max_y_coord + 0.2);
        cage.push_back(min_z_coord - 0.2);

        cage.push_back(max_x_coord + 0.2);
        cage.push_back(max_y_coord + 0.2);
        cage.push_back(min_z_coord - 0.2);

        cage.push_back(max_x_coord + 0.2);
        cage.push_back(max_y_coord + 0.2);
        cage.push_back(min_z_coord - 0.2);

        cage.push_back(max_x_coord + 0.2);
        cage.push_back(min_y_coord - 0.2);
        cage.push_back(min_z_coord - 0.2);

        cage.push_back(max_x_coord + 0.2);
        cage.push_back(min_y_coord - 0.2);
        cage.push_back(min_z_coord - 0.2);

        cage.push_back(min_x_coord - 0.2);
        cage.push_back(min_y_coord - 0.2);
        cage.push_back(min_z_coord - 0.2);

        cage.push_back(min_x_coord - 0.2);
        cage.push_back(min_y_coord - 0.2);
        cage.push_back(max_z_coord + 0.2);

        cage.push_back(min_x_coord - 0.2);
        cage.push_back(max_y_coord + 0.2);
        cage.push_back(max_z_coord + 0.2);

        cage.push_back(min_x_coord - 0.2);
        cage.push_back(max_y_coord + 0.2);
        cage.push_back(max_z_coord + 0.2);

        cage.push_back(max_x_coord + 0.2);
        cage.push_back(max_y_coord + 0.2);
        cage.push_back(max_z_coord + 0.2);

        cage.push_back(max_x_coord + 0.2);
        cage.push_back(max_y_coord + 0.2);
        cage.push_back(max_z_coord + 0.2);

        cage.push_back(max_x_coord + 0.2);
        cage.push_back(min_y_coord - 0.2);
        cage.push_back(max_z_coord + 0.2);

        cage.push_back(max_x_coord + 0.2);
        cage.push_back(min_y_coord - 0.2);
        cage.push_back(max_z_coord + 0.2);

        cage.push_back(min_x_coord - 0.2);
        cage.push_back(min_y_coord - 0.2);
        cage.push_back(max_z_coord + 0.2);

        cage.push_back(min_x_coord - 0.2);
        cage.push_back(min_y_coord - 0.2);
        cage.push_back(min_z_coord - 0.2);

        cage.push_back(min_x_coord - 0.2);
        cage.push_back(min_y_coord - 0.2);
        cage.push_back(max_z_coord + 0.2);

        cage.push_back(min_x_coord - 0.2);
        cage.push_back(max_y_coord + 0.2);
        cage.push_back(min_z_coord - 0.2);

        cage.push_back(min_x_coord - 0.2);
        cage.push_back(max_y_coord + 0.2);
        cage.push_back(max_z_coord + 0.2);

        cage.push_back(max_x_coord + 0.2);
        cage.push_back(min_y_coord - 0.2);
        cage.push_back(min_z_coord - 0.2);

        cage.push_back(max_x_coord + 0.2);
        cage.push_back(min_y_coord - 0.2);
        cage.push_back(max_z_coord + 0.2);

        cage.push_back(max_x_coord + 0.2);
        cage.push_back(max_y_coord + 0.2);
        cage.push_back(min_z_coord - 0.2);

        cage.push_back(max_x_coord + 0.2);
        cage.push_back(max_y_coord + 0.2);
        cage.push_back(max_z_coord + 0.2);
        int grid[100][100];
        int stepx = (max_x_coord - min_x_coord) / 100;
        int stepy = (max_y_coord - min_y_coord) / 100;
        // for (int i = min_x_coord; i <= max_x_coord; i += stepx)
        // {
        //     for (int j = min_y_coord; j <= max_y_coord; j += stepy)
        //     {
        //         if (i == max_x_coord || i == min_x_coord || j == min_y_coord || j == max_y_coord)
        //         {
        //             // Exterior/Boundary
        //             grid[i][j] = 1;
        //         }
        //         else
        //         {
        //             // Interior
        //             grid[i][j] = -1;
        //         }
        //     }
        // }
        vector<float> cubicBezier;

        bool first = true;
        int sz = cage.size(); // Contains 3 points/vertex. Ignore Z
        float x[4], y[4], z[4];
        float delta_t = 1.0 / (100.0 - 1.0);
        float t;
        float prevX, prevY;

        for (int i = 0; i < (sz - 3); i += 3)
        {
            x[0] = cage[i];
            y[0] = cage[i + 1];
            z[0] = cage[i + 2];
            x[3] = cage[i + 3];
            y[3] = cage[i + 4];
            z[3] = cage[i + 5];
            cubicBezier.push_back(x[0]);
            cubicBezier.push_back(y[0]);
            cubicBezier.push_back(z[0]);
            controlPoints.push_back(x[0]);
            controlPoints.push_back(y[0]);
            controlPoints.push_back(z[0]);
        }

        cubicBezier.push_back(x[3]);
        cubicBezier.push_back(y[3]);
        cubicBezier.push_back(z[3]);
        controlPoints.push_back(x[3]);
        controlPoints.push_back(y[3]);
        controlPoints.push_back(z[3]);

        glGenVertexArrays(1, &obj_VAO);
        glBindVertexArray(obj_VAO);
        GLuint vertex_VBO;
        // cout << v.size() << endl;

        glGenBuffers(1, &vertex_VBO);
        glBindBuffer(GL_ARRAY_BUFFER, vertex_VBO);
        glBufferData(GL_ARRAY_BUFFER, cubicBezier.size() * sizeof(GLfloat), &cubicBezier[0], GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

        min_x_coord = INT_MAX;
        min_y_coord = INT_MAX;
        min_z_coord = INT_MAX;

        max_x_coord = INT_MIN;
        max_y_coord = INT_MIN;
        max_z_coord = INT_MIN;

        return cubicBezier.size();
    }
};
