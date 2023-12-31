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

/*Cage class. Each mesh will have a separate cage with corner vertices computed by adding an offset to min,max coordinates
Grid is created for each cage to compute harmonic coordinates with respect to each cornet vertex
*/

class Cage
{
private:
    GLfloat topboundayVertexX;
    GLfloat topboundayVertexY;
    GLfloat bottomboundayVertexX;
    GLfloat bottomboundayVertexY;
    bool toggle = true;

    int startInd;

    bool firstRender;

    map<int, vector<vector<float> > > harmonic;

public:
    GLfloat max_x_coord = INT_MIN;
    GLfloat max_y_coord = INT_MIN;
    GLfloat max_z_coord = INT_MIN;
    GLfloat min_x_coord = INT_MAX;
    GLfloat min_y_coord = INT_MAX;
    GLfloat min_z_coord = INT_MAX;
    vector<vector<GLfloat> > Boundary;

    float grid[101][101];
    std::vector<float> cage;
    std::vector<float> controlPoints;
    Cage(){};
    Cage(GLfloat max_x,
         GLfloat max_y,
         GLfloat min_x,
         GLfloat min_y,
         GLfloat min_z,
         GLfloat max_z, int startInd)
    {
        max_x_coord = max_x ;
        max_y_coord = max_y ;
        min_x_coord = min_x;
        min_y_coord = min_y ;
        min_z_coord = min_z;
        max_z_coord = max_z;
        vector<GLfloat> temp(3);
        temp[0] = min_x_coord;
        temp[1] = min_y_coord;
        temp[2] = 0.0f;

        Boundary.push_back(temp);

        temp[0] = min_x_coord;
        temp[1] = max_y_coord;
        temp[2] = 0.0f;

        Boundary.push_back(temp);

        temp[0] = max_x_coord;
        temp[1] = max_y_coord;
        temp[2] = 0.0f;

        Boundary.push_back(temp);

        temp[0] = max_x_coord;
        temp[1] = min_y_coord;
        temp[2] = 0.0f;

        Boundary.push_back(temp);

        firstRender = true;
        startInd = startInd;

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
            for (int j = 0; j <= 128; j++)
            {
                vector<float> temp;
                for (int k = 0; k <= 128; k++)
                {
                    temp.push_back(0);
                }

                harmonic[i].push_back(temp);
            }
        }

  
    }
    int createCage(unsigned int &program, unsigned int &obj_VAO, vector<float> &points);
    int createCage3d(unsigned int &program, unsigned int &obj_VAO, vector<float> &points);
    void createGrid();

    bool RecomputeVertex(vector<GLfloat> &mesh, unsigned int &program, unsigned int &obj_VAO, int index,bool isin);

    void handleEdge(int curr, int i, int j, float x, float y);
};
#endif