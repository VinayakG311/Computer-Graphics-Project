#ifndef POINTS_H
#define POINTS_H

#include <glm/gtc/type_ptr.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>
#include <utils.h>
#include <map>

using namespace std;

class Points
{
public:
  float oldX;
  float oldY;
  float oldZ;

  float newX;
  float newY;
  float newZ;

  Points(float a,float b,float c){
    oldX = a;
    oldY = b;
    oldZ = c;
  }

  void updatePoints(float a,float b,float c);

  void updateFinish();
};

#endif