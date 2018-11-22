#include <iostream>
#include <fstream>
#include <string>
#include "Shape.cpp"
#include "Triangle.cpp"
#include "Point.cpp"
#include "Line.cpp"
#include "Polygon.cpp"


int main(){
    std::cout.setf(std::ios::fixed,std::ios::floatfield);
    std::cout.precision(3);

    std::ifstream file;
    file.open("shape.txt");

    int *coordCounter = new int(0);
    float x = 0;

    if(file.is_open()){
        while(file >> x){
            *coordCounter += 1;
        }
    }else{
        std::cout << "No file could be found." << std::endl;
    }

    float *coords = new float[*coordCounter];
    float *xCoords = new float[*coordCounter/2];
    float *yCoords = new float[*coordCounter/2];
    float *kValue = new float[*coordCounter/2]; 


    file.close();
    file.open("shape.txt");

    for(int i = 0; i < *coordCounter; i++){
        file >> coords[i];
    }
    file.close();
    std::cout << "Raw input:" << std::endl;
    for(int i = 0; i < *coordCounter; i++){
        std::cout << coords[i] << " ";
    }

    int xK = 0;
    int yK = 1;
    for(int i=0; i < *coordCounter/2; i++){
        xCoords[i] = coords[xK];
        yCoords[i] = coords[yK];
        yK += 2;
        xK += 2;
    }

    std::cout << "\n\nCoordinates: \n";

    for(int i = 0; i < *coordCounter/2; i++){
        std::cout << " (" << xCoords[i] << "," << yCoords[i] << ") ";
    }

    std::cout << "\n\n";
    float kV = 0;
    float deltaY = 0;
    float deltaX = 0;
    int kCalc = 0;
    // Calculate incline
   for(int i = 0; i < (*coordCounter/2)-1; i++){
        deltaY = (yCoords[i+1] - yCoords[i]);
        deltaX = (xCoords[i+1] - xCoords[i]);
        kV = (deltaY/deltaX);
        kValue[i] = kV;
        kCalc++;
       // std::cout << kValue[i] << " ";
    }
    std::cout << kCalc;

    bool isLine = false;
    bool isPolygon = false;

    std::cout << '\n';

        // line
        if(kCalc == 1){
            isLine = true;
        }

        // line
        if(kCalc > 1){
            for(int i=0; i < kCalc; i++){
                if(kValue[1+i] == kValue[i] && kValue[0] == kCalc){
                    isLine = true;
                }else{
                    isPolygon = true;
                }
            }
        }

    if(*coordCounter/2 == 1){
        Point point; 
        point.getType();
        point.getArea(xCoords, yCoords);
        point.position(xCoords, yCoords);
    }

    //create new line object.
    if(isLine == true){
        Line line;
        line.getType();
        line.getArea(xCoords, yCoords);
    }
    //create new triangle object.
    if(isPolygon == true && *coordCounter/2 == 3 && isLine == false){
        Triangle triangle;
        triangle.getType();
        triangle.getArea(xCoords, yCoords);
        triangle.circumference();
        triangle.position(xCoords, yCoords);
    }
    //create new polygon object.
    if(isPolygon == true && *coordCounter/2 > 3 && isLine == false){
        Polygon polygon;
        polygon.getType();
        polygon.getArea(xCoords, yCoords, coordCounter);
    }

    delete[] coords;
    delete[] xCoords;
    delete[] yCoords;
    delete coordCounter;
    coords = NULL;
    xCoords = NULL;
    yCoords = NULL;
    coordCounter = NULL;
    
    std::cout << '\n';
    getchar();
    return 0;
}