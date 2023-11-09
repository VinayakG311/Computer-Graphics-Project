#ifndef CAGE_H
#define CAGE_H

#include <glm/gtc/type_ptr.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>
#include <utils.h>

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
        for (int i = 0; i <= 100; i++)
        {
            for (int j = 0; j <= 100; j++)
            {
                grid[i][j] = 0;
            }
        }
    }
    int createCage(unsigned int &program, unsigned int &obj_VAO, vector<float> &points);

    void createGrid();

    bool RecomputeVertex(vector<GLfloat> &mesh);
};
#endif
