#ifndef CAGE_H
#define CAGE_H

#include <glm/gtc/type_ptr.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>
#include <utils.h>
#include <map>
// #include <utils/utils.hpp>
// #include <iostream>
using namespace std;
class Cage
{
private:
    GLfloat max_x_coord = INT_MIN;
    GLfloat max_y_coord = INT_MIN;
    GLfloat max_z_coord = INT_MIN;
    GLfloat min_x_coord = INT_MAX;
    GLfloat min_y_coord = INT_MAX;
    GLfloat min_z_coord = INT_MAX;

    GLfloat topboundayVertexX;
    GLfloat topboundayVertexY;
    GLfloat bottomboundayVertexX;
    GLfloat bottomboundayVertexY;

    map<int, vector<vector<float> > > harmonic;

public:
    float grid[101][101];
    std::vector<float> cage;
    std::vector<float> controlPoints;
    Cage(GLfloat max_x,
         GLfloat max_y,
         GLfloat min_x,
         GLfloat min_y,
         GLfloat min_z,
         GLfloat max_z)
    {
        max_x_coord = max_x;
        max_y_coord = max_y;
        min_x_coord = min_x;
        min_y_coord = min_y;
        min_z_coord = min_z;
        max_z_coord = max_z;

        topboundayVertexX = max_x_coord + 0.2;
        topboundayVertexY = max_y_coord + 0.2;

        bottomboundayVertexX = min_x_coord - 0.2;
        bottomboundayVertexY = min_y_coord - 0.2;

        for (int i = 0; i <= 100; i++)
        {
            for (int j = 0; j <= 100; j++)
            {
                grid[i][j] = 0;
            }
        }

        for (int i = 0; i < 4; i++)
        {
            vector<float> temp;
            for (int j = 0; j <= 100; j++)
            {
                vector<float> temp;
                for (int k = 0; k <= 100; k++)
                {
                    temp.push_back(0);
                }

                harmonic[i].push_back(temp);
            }
        }
    }
    int createCage(unsigned int &program, unsigned int &obj_VAO, vector<float> &points);

    void createGrid();

    bool RecomputeVertex(vector<GLfloat> &mesh);

    void handleEdge(int curr,int i,int j, float x, float y);
};
#endif
