#ifndef SHAPE_H
#define SHAPE_H

#include <string> 

class Shape{
protected:
    float area;
    std::string type;

public:
    virtual void getType() = 0;
    virtual void getArea(float*, float*) = 0;
    virtual void circumference() = 0;
    virtual void position(float*, float*) = 0;
};

#endif