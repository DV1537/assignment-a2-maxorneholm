#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape{
private:
    std::string type;
    float area;
    float circum;

public:
    virtual std::string getType() = 0;
    virtual float getArea() = 0;
    virtual float circumference() = 0;
    virtual void position() = 0;
    virtual bool isConvex() = 0;

};
#endif