#ifndef POLYGON_H
#define POLYGON_H
#include "Shape.h"

class Polygon : public Shape{
protected:

public:
    void getType();
    void getArea(float*, float*);
    void circumference();
    void position(float*, float*);
    virtual ~Polygon() = default;
};

#endif