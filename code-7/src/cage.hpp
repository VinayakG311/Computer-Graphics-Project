
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

    public :
     vector<float> cage;
     Cage();
     int createCage(unsigned int &program, unsigned int &VAO);
     
};
