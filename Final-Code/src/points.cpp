#include "points.hpp"

void Points::updatePoints(float a,float b,float c){
    newX = a;
    newY = b;
    newZ = c;
}

void Points::updateFinish(){
    oldX = newX;
    oldY = newY;
    oldZ = newZ;
  }


