#ifndef LINE_H
#define LINE_H
#include "Shape.h"
class Line : public Shape{
private:
    std::string type = "Line";
    float area = -1;
    float circum;
    float* xCoords;
    float* yCoords;
    int coordCounter;
public:
    Line();
    Line(float*, int);
    std::string getType();
    float getArea();
    float circumference();
    void position();
    bool isConvex();
};
#endif