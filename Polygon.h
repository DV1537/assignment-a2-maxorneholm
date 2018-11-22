#ifndef POLYGON_H
#define POLYGON_H
#include "Shape.h"

class Polygon : public Shape{
private:

public:
    void getType();
    void circumference();
    void getArea(float*, float*, int*);
    void getArea(float*, float*);
    void position(float*, float*);
    virtual ~Polygon() = default;
};

#endif