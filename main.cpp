#include <iostream>
#include <fstream>
#include <string>
#include "Shape.cpp"
#include "Triangle.cpp"
#include "Point.cpp"
#include "Line.cpp"


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
    float *kValue = new float[(*coordCounter/2)-1]; 


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

   for(int i = 0; i < (*coordCounter/2)-1; i++){

        float yV = (yCoords[i+1] - yCoords[i]);
        float xV = (xCoords[i+1] - xCoords[i]);
        float kV = (yV/xV);
        kValue[i] = kV;
    }

    bool isLine = false;
    bool isPolygon = false;

    for(int i=0; i < (*coordCounter/2)-1; i++){
        if(kValue[0] == kValue[i]){
            isLine = true;
        }else{
            isLine = false;
            isPolygon = true;
        }
    }

    if(isLine == true){
        Line line;
        line.getType();
        line.getArea(xCoords, yCoords);
    }

    if(isPolygon == true && *coordCounter/2 == 3){
        Triangle triangle;
        triangle.getType();
        triangle.getArea(xCoords, yCoords);
        triangle.circumference();
        triangle.position(xCoords, yCoords);
    }
    if(isPolygon == true && *coordCounter/2 > 3){
        std::cout << "\nPoly\n";
    }

    if(*coordCounter/2 == 1){
        Point point; 
        point.getType();
        point.getArea(xCoords, yCoords);
        point.position(xCoords, yCoords);
    }
    /*if(*coordCounter/2 == 3){
        Triangle triangle;
        triangle.getType();
        triangle.getArea(xCoords, yCoords);
        triangle.circumference();
        triangle.position(xCoords, yCoords);
    }

/*
   // Point

    // Triangle
    if(*coordCounter/2 == 3 && xCoords[0] > xCoords[1] || xCoords[1] > xCoords[0] || xCoords[0] > xCoords[2] || xCoords[2] > xCoords[0]){
        Triangle triangle;
        triangle.getType();
        triangle.getArea(xCoords, yCoords);
        triangle.circumference();
        triangle.position(xCoords, yCoords);
    }
    
    // Line
    if(*coordCounter/2 > 3){
        std::cout << "Polygon.";
    }
*/
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