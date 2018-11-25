#ifndef POLYGON_H
#define POLYGON_H
#include "Shape.h"

class Polygon : public Shape{
private:
    std::string type = "Polygon";
    float area = 0;
    float circum;
    int coordCounter;
    float* xCoords;
    float* yCoords;

public:
    Polygon();
    Polygon(float*, int);
    std::string getType();
    float getArea();
    float circumference();
    void position();
    bool isConvex();
    ~Polygon();    
};
#endif