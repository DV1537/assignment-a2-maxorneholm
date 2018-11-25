#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"

class Triangle : public Shape{
private:
    std::string type = "Triangle";
    float area = 0;
    float circum;
    float* xCoords;
    float* yCoords;
    float distanceAtoB = 0, distanceAtoC = 0, distanceBtoC = 0;
    float hypo = 0, base = 0, height = 0, circumFormula = 0;

public:
    Triangle();
    Triangle(float*, int);
    std::string getType();
    float getArea();
    float circumference();
    void position();
    bool isConvex();
    ~Triangle();
};
#endif