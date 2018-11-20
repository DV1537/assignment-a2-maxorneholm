#include "Line.h"
#include <iostream>

void Line::getType(){
    type = "Line";
    std::cout << "\nType: " << type << std::endl;
}
void Line::position(float* xCoords, float* yCoords){
    std::cout << "\nCenter coordinates: " << "(" << xCoords[0] << ", " << yCoords[0] << ")" << std::endl;
}

void Line::getArea(float* xCoords, float* yCoords){
    area = -1;
    std::cout << "Area: " << area << " l.e";
}

void Line::circumference(){}