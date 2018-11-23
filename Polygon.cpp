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

    std::cout << "area: " << total << ".";
}

void Polygon::getArea(float*, float*){}
void Polygon::circumference(){}

void Polygon::position(float* xCoords, float* yCoords, int* coordCounter){
    int i=0;

    for (i=0; i < (*coordCounter/2)-1; ++i)
    {
        xCoord0 = xCoords[i];
        yCoord0 = yCoords[i];
        xCoord1 = xCoords[i+1];
        yCoord1 = yCoords[i+1];
        a = xCoord0*yCoord1 - xCoord1*yCoord0;
        currentArea += a;
        centroidX += (xCoord0 + xCoord1)*a;
        centroidY += (yCoord0 + yCoord1)*a;
    }

    xCoord0 = xCoords[i];
    yCoord0 = yCoords[i];
    xCoord1 = xCoords[0];
    yCoord1 = yCoords[0];
    a = xCoord0*yCoord1 - xCoord1*yCoord0;
    currentArea += a;
    centroidX += (xCoord0 + xCoord1)*a;
    centroidY += (yCoord0 + yCoord1)*a;

    currentArea *= 0.5;
    centroidX /= (6.0*currentArea);
    centroidY /= (6.0*currentArea);

    std::cout << "\n" << "Position: (" << centroidX << ", " << centroidY << ")\n";
   
   
   
   
   /* float cX = 0;
    float cY = 0;
    for(int i = 0; i < (*coordCounter/2)-1; i++){
	//ta fram x cord
	cX += (xCoords[i] + xCoords[i+1]) * (xCoords[i] * yCoords[i+1] - xCoords[i+1] + yCoords[i]);
	//ta fram y cord
	cY += (yCoords[i] + yCoords[i+1]) * (xCoords[i] * yCoords[i+1] - xCoords[i+1] + yCoords[i]);

    cX += (x0 + x1)*a;
    cY += (y0 + y1)*a;
    std::cout << "\nCenter coordinates: " << "(" << (0.01515151515*cX) << ", " << (0.01515151515*cY) << ")"; 
    }
*/
}
void Polygon::position(float* xCoords, float* yCoords){}
