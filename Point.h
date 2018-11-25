#ifndef POINT_H
#define POINT_H

#include "Shape.h"
class Point : public Shape{
private:
    std::string type = "Point";
    float area = -1;
    float circum;
    float* xCoords;
    float* yCoords;
public:
    Point();
    Point(float*, int);
    std::string getType();
    float getArea();
    float circumference();
    void position();
    bool isConvex();
};

#endif