#ifndef POINT_H
#define POINT_H
#include "Shape.h"

class Point : public Shape{
protected:

public:
    void getType();
    void getArea(float*, float*);
    void circumference();
    void position(float*, float*);
    virtual ~Point() = default;
};

#endif