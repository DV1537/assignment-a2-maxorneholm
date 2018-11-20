#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape{
protected:
    float circum;
    float distanceAtoB, distanceAtoC, distanceBtoC;
    float hypo, base, height, sumX, sumY;
public:
    void getType();
    void getArea(float*, float*);
    void circumference();
    void position(float*, float*);
};

#endif