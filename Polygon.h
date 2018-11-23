#ifndef POLYGON_H
#define POLYGON_H
#include "Shape.h"

class Polygon : public Shape{
private:
//floats 
float currentArea = 0, centroidX = 0, centroidY = 0;
float xCoord0 = 0, yCoord0 = 0, xCoord1 = 0, yCoord1 = 0, a = 0;
public:
    void getType();
    void circumference();
    void getArea(float*, float*, int*);
    void position(float*, float*, int*);
    void getArea(float*, float*);
    void position(float*, float*);
    virtual ~Polygon() = default;
};

#endif