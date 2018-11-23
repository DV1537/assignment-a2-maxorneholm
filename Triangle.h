#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"

class Triangle : public Shape{
protected:
    float circum = 0, circumFormula = 0;
    float distanceAtoB = 0, distanceAtoC = 0, distanceBtoC = 0;
    float distance = 0;
    float hypo = 0, base = 0, height = 0, sumX = 0, sumY = 0;
    float xAtoB, yAtoB, xAtoC, yAtoC, xBtoC, yBtoc = 0;
public:
    void getType();
    void getArea(float*, float*);
    void circumference();
    void position(float*, float*);
    virtual ~Triangle() = default;
};

#endif