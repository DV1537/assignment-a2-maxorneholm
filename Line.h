#ifndef LINE_H
#define LINE_H

#include "Shape.h"

class Line : public Shape{
protected:

public:
    void getType();
    void getArea(float*, float*);
    virtual ~Line() = default;
};


#endif