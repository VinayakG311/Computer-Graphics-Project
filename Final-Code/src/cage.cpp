#include "cage.hpp"
#include <fstream>
// References - Assignment 1 -> Piecewise Cubic bezier curve

/*To create a cage for 3d mesh
The control points are set as corner vertices
Piecewise cubic bezier is then calculated using the code in Assignment 1
*/
bool equal(float x, float y)
{
    if (abs(x - y) < pow(10, -1))
        return true;
    return false;
}
int Cage::createCage3d(unsigned int &program, unsigned int &obj_VAO, vector<float> &points)
{
    controlPoints.clear();
    // cout << min_x_coord << endl;
    cage.clear();
    // cage.push_back(min_x_coord - 0.2);
    //     cage.push_back(min_y_coord - 0.2);
    //     cage.push_back(min_z_coord - 0.2);

    //     cage.push_back(min_x_coord - 0.2);
    //     cage.push_back(max_y_coord + 0.2);
    //     cage.push_back(min_z_coord - 0.2);

    //     cage.push_back(min_x_coord - 0.2);
    //     cage.push_back(max_y_coord + 0.2);
    //     cage.push_back(min_z_coord - 0.2);

    //     cage.push_back(max_x_coord + 0.2);
    //     cage.push_back(max_y_coord + 0.2);
    //     cage.push_back(min_z_coord - 0.2);

    //     cage.push_back(max_x_coord + 0.2);
    //     cage.push_back(max_y_coord + 0.2);
    //     cage.push_back(min_z_coord - 0.2);

    //     cage.push_back(max_x_coord + 0.2);
    //     cage.push_back(min_y_coord - 0.2);
    //     cage.push_back(min_z_coord - 0.2);

    //     cage.push_back(max_x_coord + 0.2);
    //     cage.push_back(min_y_coord - 0.2);
    //     cage.push_back(min_z_coord - 0.2);

    //     cage.push_back(min_x_coord - 0.2);
    //     cage.push_back(min_y_coord - 0.2);
    //     cage.push_back(min_z_coord - 0.2);

    cage.push_back(min_x_coord - 0.2);
    cage.push_back(min_y_coord - 0.2);
    cage.push_back(max_z_coord + 0.2);

    cage.push_back(min_x_coord - 0.2);
    cage.push_back(max_y_coord + 0.2);
    cage.push_back(max_z_coord + 0.2);

    // cage.push_back(min_x_coord - 0.2);
    // cage.push_back(max_y_coord + 0.2);
    // cage.push_back(max_z_coord + 0.2);

    cage.push_back(max_x_coord + 0.2);
    cage.push_back(max_y_coord + 0.2);
    cage.push_back(max_z_coord + 0.2);

    // cage.push_back(max_x_coord + 0.2);
    // cage.push_back(max_y_coord + 0.2);
    // cage.push_back(max_z_coord + 0.2);

    cage.push_back(max_x_coord + 0.2);
    cage.push_back(min_y_coord - 0.2);
    cage.push_back(max_z_coord + 0.2);

    // cage.push_back(max_x_coord + 0.2);
    // cage.push_back(min_y_coord - 0.2);
    // cage.push_back(max_z_coord + 0.2);

    cage.push_back(min_x_coord - 0.2);
    cage.push_back(min_y_coord - 0.2);
    cage.push_back(max_z_coord + 0.2);

    // // cage.push_back(min_x_coord - 0.2);
    // // cage.push_back(min_y_coord - 0.2);
    // // cage.push_back(min_z_coord - 0.2);

    // cage.push_back(min_x_coord - 0.2);
    // cage.push_back(min_y_coord - 0.2);
    // cage.push_back(max_z_coord + 0.2);

    // // cage.push_back(min_x_coord - 0.2);
    // // cage.push_back(max_y_coord + 0.2);
    // // cage.push_back(min_z_coord - 0.2);

    // cage.push_back(min_x_coord - 0.2);
    // cage.push_back(max_y_coord + 0.2);
    // cage.push_back(max_z_coord + 0.2);

    // // cage.push_back(max_x_coord + 0.2);
    // // cage.push_back(min_y_coord - 0.2);
    // // cage.push_back(min_z_coord - 0.2);

    // cage.push_back(max_x_coord + 0.2);
    // cage.push_back(min_y_coord - 0.2);
    // cage.push_back(max_z_coord + 0.2);

    // // cage.push_back(max_x_coord + 0.2);
    // // cage.push_back(max_y_coord + 0.2);
    // // cage.push_back(min_z_coord - 0.2);

    // cage.push_back(max_x_coord + 0.2);
    // cage.push_back(max_y_coord + 0.2);
    // cage.push_back(max_z_coord + 0.2);

    std::vector<float> cubicBezier;

    bool first = true;
    int sz = cage.size(); // Contains 3 points/vertex. Ignore Z
    float x[4], y[4], z[4];
    float delta_t = 1.0 / (100.0 - 1.0);
    float t;
    float prevX, prevY;

    for (int i = 0; i < sz; i++)
    {

        cubicBezier.push_back(cage[i]);
        controlPoints.push_back(cage[i]);
    }
    // cout << controlPoints.size() << endl;
    // glGenVertexArrays(1, &obj_VAO);
    // glBindVertexArray(obj_VAO);
    // GLuint vertex_VBO;
    // // cout << v.size() << endl;

    // glGenBuffers(1, &vertex_VBO);
    // glBindBuffer(GL_ARRAY_BUFFER, vertex_VBO);
    // glBufferData(GL_ARRAY_BUFFER, cubicBezier.size() * sizeof(GLfloat), &cubicBezier[0], GL_STATIC_DRAW);
    // glEnableVertexAttribArray(0);
    // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    // glBindBuffer(GL_ARRAY_BUFFER, 0);
    // glBindVertexArray(0);
    if (firstRender)
    {
        for (auto i : controlPoints)
        {
            points.push_back(i);
        }
    }
    firstRender = false;
    return cubicBezier.size();
}

/*To create a cage for 3d mesh
The control points are set as corner vertices
Piecewise cubic bezier is then calculated using the code in Assignment 1
*/

int Cage::createCage(unsigned int &program, unsigned int &obj_VAO, vector<float> &points)
{
    glUseProgram(program);

    // Bind shader variables
    int vVertex_attrib = glGetAttribLocation(program, "vVertex");
    if (vVertex_attrib == -1)
    {
        fprintf(stderr, "Could not bind location: vVertex\n");
        exit(0);
    }

    if (firstRender)
    {

        std::vector<float> v;
        cage.push_back(min_x_coord - 0.2);
        cage.push_back(min_y_coord - 0.2);
        cage.push_back(0.0);

        cage.push_back(min_x_coord - 0.2);
        cage.push_back(max_y_coord + 0.2);
        cage.push_back(0.0);

        cage.push_back(min_x_coord - 0.2);
        cage.push_back(max_y_coord + 0.2);
        cage.push_back(0.0);

        cage.push_back(max_x_coord + 0.2);
        cage.push_back(max_y_coord + 0.2);
        cage.push_back(0.0);

        cage.push_back(max_x_coord + 0.2);
        cage.push_back(max_y_coord + 0.2);
        cage.push_back(0.0);

        cage.push_back(max_x_coord + 0.2);
        cage.push_back(min_y_coord - 0.2);
        cage.push_back(0.0);

        cage.push_back(max_x_coord + 0.2);
        cage.push_back(min_y_coord - 0.2);
        cage.push_back(0.0);

        cage.push_back(min_x_coord - 0.2);
        cage.push_back(min_y_coord - 0.2);
        cage.push_back(0.0);

        cage.push_back(min_x_coord - 0.2);
        cage.push_back(min_y_coord - 0.2);
        cage.push_back(0.0);

        cage.push_back(min_x_coord - 0.2);
        cage.push_back(max_y_coord + 0.2);
        cage.push_back(0.0);

        cage.push_back(max_x_coord + 0.2);
        cage.push_back(min_y_coord - 0.2);
        cage.push_back(0.0);
        std::vector<float> cubicBezier;

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

        // glGenVertexArrays(1, &obj_VAO);
        // glBindVertexArray(obj_VAO);
        // GLuint vertex_VBO;
        // // cout << v.size() << endl;

        // glGenBuffers(1, &vertex_VBO);
        // glBindBuffer(GL_ARRAY_BUFFER, vertex_VBO);
        // glBufferData(GL_ARRAY_BUFFER, cubicBezier.size() * sizeof(GLfloat), &cubicBezier[0], GL_STATIC_DRAW);
        // glEnableVertexAttribArray(0);
        // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        // glBindBuffer(GL_ARRAY_BUFFER, 0);
        // glBindVertexArray(0);
        for (auto i : controlPoints)
        {
            points.push_back(i);
        }
        firstRender = false;
        return cubicBezier.size();
    }

    else
    {

        cage.clear();
        cage.push_back(min_x_coord - 0.2);
        cage.push_back(min_y_coord - 0.2);
        cage.push_back(0.0);

        cage.push_back(min_x_coord - 0.2);
        cage.push_back(max_y_coord + 0.2);
        cage.push_back(0.0);

        cage.push_back(min_x_coord - 0.2);
        cage.push_back(max_y_coord + 0.2);
        cage.push_back(0.0);

        cage.push_back(max_x_coord + 0.2);
        cage.push_back(max_y_coord + 0.2);
        cage.push_back(0.0);

        cage.push_back(max_x_coord + 0.2);
        cage.push_back(max_y_coord + 0.2);
        cage.push_back(0.0);

        cage.push_back(max_x_coord + 0.2);
        cage.push_back(min_y_coord - 0.2);
        cage.push_back(0.0);

        cage.push_back(max_x_coord + 0.2);
        cage.push_back(min_y_coord - 0.2);
        cage.push_back(0.0);

        cage.push_back(min_x_coord - 0.2);
        cage.push_back(min_y_coord - 0.2);
        cage.push_back(0.0);

        cage.push_back(min_x_coord - 0.2);
        cage.push_back(min_y_coord - 0.2);
        cage.push_back(0.0);

        cage.push_back(min_x_coord - 0.2);
        cage.push_back(max_y_coord + 0.2);
        cage.push_back(0.0);

        cage.push_back(max_x_coord + 0.2);
        cage.push_back(min_y_coord - 0.2);
        cage.push_back(0.0);
        std::vector<float> cubicBezier;

        bool first = true;
        // int sz = ca.size(); // Contains 3 points/vertex. Ignore Z
        float x[4], y[4], z[4];
        float delta_t = 1.0 / (100.0 - 1.0);
        float t;
        float prevX, prevY;

        for (int i = 0; i < (cage.size() - 3); i += 3)
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
            // controlPoints.push_back(x[0]);
            // controlPoints.push_back(y[0]);
            // controlPoints.push_back(z[0]);
        }

        cubicBezier.push_back(x[3]);
        cubicBezier.push_back(y[3]);
        cubicBezier.push_back(z[3]);
        // controlPoints.push_back(x[3]);
        // controlPoints.push_back(y[3]);
        // controlPoints.push_back(z[3]);

        // glGenVertexArrays(1, &obj_VAO);
        // glBindVertexArray(obj_VAO);
        // GLuint vertex_VBO;
        // // cout << v.size() << endl;

        // glGenBuffers(1, &vertex_VBO);
        // glBindBuffer(GL_ARRAY_BUFFER, vertex_VBO);
        // glBufferData(GL_ARRAY_BUFFER, cubicBezier.size() * sizeof(GLfloat), &cubicBezier[0], GL_STATIC_DRAW);
        // glEnableVertexAttribArray(0);
        // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        // glBindBuffer(GL_ARRAY_BUFFER, 0);
        // glBindVertexArray(0);
        // for (auto i : controlPoints)
        // {
        //     points.push_back(i);
        // }
        // firstRender = false;
        return cubicBezier.size();
    }
}

// // 3_________________2
// // |                |
// // |                |
// // |                |
// // |                |
// // |                |
// // |                |
// // |________________|
// // 0                1

// // To handle edges while computing harmonic coordinates
void Cage::handleEdge(int currEdge, int i, int j, float x, float y)
{
    float valy, valx;
    float dfx = max_x_coord - min_x_coord;
    float dfy = max_y_coord - min_y_coord;

    if (currEdge == 0)
    {

        // previos edge
        if (x == min_x_coord && y < max_y_coord)
        {
            harmonic[currEdge][i][j] = (100 - j) * 0.01;
        }

        // next edge
        if (y == min_y_coord && x < max_x_coord)
        {

            harmonic[currEdge][i][j] = (100 - i) * 0.01;
        }
    }

    else if (currEdge == 1)
    {

        if (y == min_y_coord && x < max_x_coord)
        {
            harmonic[currEdge][i][j] = (i) * 0.01;
        }

        // next edge
        if (x == max_x_coord && y < max_y_coord)
        {
            harmonic[currEdge][i][j] = (100 - j) * 0.01;
        }
    }

    else if (currEdge == 2)
    {
        // prev edge

        if (x == max_x_coord && y < max_y_coord)
        {
            harmonic[currEdge][i][j] = (j) * 0.01;
        }

        // next edge
        if (equal(y, max_y_coord) && x < max_x_coord)
        {
            harmonic[currEdge][i][j] = (i) * 0.01;
        }
    }

    else if (currEdge == 3)
    {
        // prev edge
        if (equal(y, max_y_coord) && x != min_x_coord && x != max_x_coord)
        {
            harmonic[currEdge][i][j] = (100 - i) * 0.01;
        }

        // next edge
        if (x == min_x_coord && y != min_y_coord && y != max_y_coord)
        {
            harmonic[currEdge][i][j] = (j) * 0.01;
        }
    }

    // cout<<harmonic[currEdge][x][y]<<endl;
}

// /* To create a grid around each cage
// Harmonic coordinates are calculated with respect to each control point of the cage
// Computation stratergy defined in the paper according to boundary, interior, exterior points
// */

// void Cage::handleEdge(int currEdge, int i, int j, float x, float y)
// {
//     float valy, valx;
//     float dfx = max_x_coord - min_x_coord;
//     float dfy = max_y_coord - min_y_coord;

//     if (currEdge == 0)
//     {

//         // previos edge
//         if (x == min_x_coord && y < max_y_coord)
//         {
//             harmonic[currEdge][i][j] = (100 - j) * 0.01;
//         }

//         // next edge
//         if (y == min_y_coord && x < max_x_coord)
//         {

//             harmonic[currEdge][i][j] = (100 - i) * 0.01;
//         }
//     }

//     else if (currEdge == 1)
//     {

//         if (y == min_y_coord && x < max_x_coord)
//         {
//             harmonic[currEdge][i][j] = (i) * 0.01;
//         }

//         // next edge
//         if (x == max_x_coord && y < max_y_coord)
//         {
//             harmonic[currEdge][i][j] = (100 - j) * 0.01;
//         }
//     }

//     else if (currEdge == 2)
//     {
//         // prev edge

//         if (x == max_x_coord && y < max_y_coord)
//         {
//             harmonic[currEdge][i][j] = (j) * 0.01;
//         }

//         // next edge
//         if (equal(y, max_y_coord) && x < max_x_coord)
//         {
//             harmonic[currEdge][i][j] = (i) * 0.01;
//         }
//     }

//     else if (currEdge == 3)
//     {
//         // prev edge
//         if (equal(y, max_y_coord) && x != min_x_coord && x != max_x_coord)
//         {
//             harmonic[currEdge][i][j] = (100 - i) * 0.01;
//         }

//         // next edge
//         if (x == min_x_coord && y != min_y_coord && y != max_y_coord)
//         {
//             harmonic[currEdge][i][j] = (j) * 0.01;
//         }
//     }

//     // cout<<harmonic[currEdge][x][y]<<endl;
// }

// /* To create a grid around each cage
// Harmonic coordinates are calculated with respect to each control point of the cage
// Computation stratergy defined in the paper according to boundary, interior, exterior points
// */

void Cage::createGrid()
{
    float stepx = (max_x_coord - min_x_coord) / 100;
    float stepy = (max_y_coord - min_y_coord) / 100;

    float changeInval = 0;
    int numOfcoord = 0;

    for (int k = 0; k < 4; k++)
    {
        for (int i = 0; i <= 100; i++)
        {
            for (int j = 0; j <= 100; j++)
            {
                float coord_x = (min_x_coord + i * stepx);
                float coord_y = (min_y_coord + j * stepy);
                if ((equal(coord_x, max_x_coord) && equal(coord_y, max_y_coord) && k == 2) || (equal(coord_x, max_x_coord) && equal(coord_y, min_y_coord) && k == 1) || (equal(coord_x, min_x_coord) && equal(coord_y, max_y_coord) && k == 3) || (equal(coord_x, min_x_coord) && equal(coord_y, min_y_coord) && k == 0))
                {

                    harmonic[k][i][j] = 1.0f;
                }
                else if (equal(coord_x, max_x_coord) || equal(coord_x, min_x_coord) || equal(coord_y, min_y_coord) || equal(coord_y, max_y_coord))
                {
                    handleEdge(k, i, j, coord_x, coord_y);
                }
            }
        }
    }

    for (int k = 0; k < 4; k++)
    {
        int c = 0;
        bool breaker = false;
        while (true)
        {
            c++;
            // cout<<c<<endl;
            if (breaker)
            {
                break;
            }
            changeInval = 0.0f;
            numOfcoord = 0;
            for (int i = 0; i <= 100; i++)
            {
                for (int j = 0; j <= 100; j++)
                {
                    float coord_x = (min_x_coord + i * stepx);
                    float coord_y = (min_y_coord + j * stepy);
                    if ((equal(coord_x, max_x_coord) && equal(coord_y, max_y_coord) && k == 2) || (equal(coord_x, max_x_coord) && equal(coord_y, min_y_coord) && k == 1) || (equal(coord_x, min_x_coord) && equal(coord_y, max_y_coord) && k == 3) || (equal(coord_x, min_x_coord) && equal(coord_y, min_y_coord) && k == 0))
                    {

                        continue;
                    }
                    else if (equal(coord_x, max_x_coord) || equal(coord_x, min_x_coord) || equal(coord_y, min_y_coord) || equal(coord_y, max_y_coord))
                    {
                        continue;
                    }
                    else
                    {
                        // Interior
                        numOfcoord++;
                        float prev = harmonic[k][i][j];

                        float check = 0;
                        int neighbors = 0;
                        if (i > 0)
                        {
                            check += harmonic[k][i - 1][j];
                            neighbors++;
                        }
                        if (j > 0)
                        {
                            check += harmonic[k][i][j - 1];
                            neighbors++;
                        }
                        check += (harmonic[k][i][j + 1] + harmonic[k][i + 1][j]);
                        neighbors += 2;

                        // grid[i][j] = (grid[i - 1][j] + grid[i][j - 1] + grid[i + 1][j] + grid[i][j + 1]) / 4;

                        harmonic[k][i][j] = check / (float)neighbors;

                        // std::cout<<grid[i][j]<<" ";
                        changeInval += abs(harmonic[k][i][j] - prev);
                    }
                }
            }
            // std::cout<<changeInval<<" ";
            if (((changeInval) / (float)numOfcoord) < 0.001f)
            {
                // for(int i = 0;i<=100;i++){
                //     std::cout<<harmonic[0][i][0]<<" ";
                // }
                breaker = true;
                break;
            }
        }
    }
    ofstream Myfile("Data.txt");

    for (int i = 0; i <= 100; i++)
    {
        for (int j = 0; j <= 100; j++)
        {
            Myfile << harmonic[3][i][j];
            Myfile << " ";
        }
        Myfile << "\n";
    }
}

// /*
// To recompute the mesh vertices after cage deformation
// First the grid coordinates are mapped to mesh coordinates
// Then using the formula in the paper, new coordinates are calculated

// */

bool Cage::RecomputeVertex(vector<GLfloat> &mesh, unsigned int &program, unsigned int &obj_VAO, int index)
{

    glUseProgram(program);

    // Bind shader variables
    int vVertex_attrib = glGetAttribLocation(program, "vVertex");
    if (vVertex_attrib == -1)
    {
        fprintf(stderr, "Could not bind location: vVertex\n");
        exit(0);
    }

    int sz = mesh.size();

    for (int i = 0; i < mesh.size() / 3; i += 3)
    {
        float stepx = 100 / (max_x_coord - min_x_coord);
        float stepy = 100 / (max_y_coord - min_y_coord);
        GLfloat old_x = mesh[i * 3];
        GLfloat old_y = mesh[i * 3 + 1];

        int map_x = (old_x - min_x_coord) / stepx;
        int map_y = (old_y - min_y_coord) / stepy;
        float ox = min_x_coord + 0.1;
        int mx = (ox - min_x_coord) / stepx;
        // cout << map_x << " " << map_y << endl;
        if (map_x < 0 || map_x >= 128 || map_y < 0 || map_y >= 128)
        {
            continue;
        }
        GLfloat new_x = 0, new_y = 0;
        // for (int j = 0; j < controlPoints.size() / 3; j++)
        // {
        for (int k = 0; k < 4; k++)
        {

            new_x += (harmonic[k][map_x][map_y]) * (controlPoints[index * 3]);
            new_y += (harmonic[k][map_x][map_y]) * (controlPoints[index * 3 + 1]);
            // cout << old_x << " " << new_x << endl;
        }
        //  }
        mesh[i * 3] = new_x;
        mesh[i * 3 + 1] = new_y;
    }

    glGenVertexArrays(1, &obj_VAO);
    glBindVertexArray(obj_VAO);

    GLuint vertex_VBO;
    glGenBuffers(1, &vertex_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_VBO);
    glBufferData(GL_ARRAY_BUFFER, mesh.size() * sizeof(GLfloat), &mesh[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(vVertex_attrib);
    glVertexAttribPointer(vVertex_attrib, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0); // Unbind the VAO to disabl

    return true;
}

