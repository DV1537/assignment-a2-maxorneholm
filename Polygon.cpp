#include "Polygon.h"
#include <iostream>
#include <cmath>
#include <string>

void Polygon::getType(){
    type = "Polygon";
    std::cout << "\nType: " << type << std::endl;
}

void Polygon::getArea(float* xCoords, float* yCoords, int* coordCounter){

    float current = 0;
    float last = 0;
    float total = 0;
    int lastCounter = 0;
    
    float *areaArray = new float[*coordCounter/2];

    for(int i = 0; i < (*coordCounter/2)-1; i++){
        current = ((xCoords[i] * yCoords[i+1]) - (yCoords[i] * xCoords[i+1]));
        areaArray[i] = current;
        lastCounter++;
    }
    
    last = ((xCoords[lastCounter] * yCoords[0]) - (yCoords[lastCounter] * xCoords[0]));
    areaArray[(*coordCounter/2)-1] = last;

    for (int i=0;i< (*coordCounter/2);i++)
    {
            total += (areaArray[i]);
    }
    total = abs(total);
    total = total/2;

    std::cout << "area: " << total << " l.e";
}

void Polygon::getArea(float*, float*){}
void Polygon::circumference(){}
void Polygon::position(float*, float*){}
