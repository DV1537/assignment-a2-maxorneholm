#include <iostream>
#include <fstream>
#include "Shape.cpp"
#include "Point.cpp"
#include "Line.cpp"
#include "Triangle.cpp"
#include "Polygon.cpp"

int main(){
    float kV = 0;
    float deltaY = 0;
    float deltaX = 0;
    int kCalc = 0;
    int xK = 0;
    int yK = 1;
    float x = 0;
    int coordCounter = 0;
    bool isLine = false;
    bool isPolygon = false;

    //Used for 3 decimal places
    std::cout.setf(std::ios::fixed,std::ios::floatfield);
    std::cout.precision(3);

    std::ifstream file;
    file.open("shape.txt");

    if(file.is_open()){
        while(file >> x){
            coordCounter += 1;
        }
    }else{
        std::cout << "No file could be found." << std::endl;
    }

    float *coords = new float[coordCounter];
    float *xCoords = new float[coordCounter/2];
    float *yCoords = new float[coordCounter/2];
    float *kValue = new float[coordCounter/2]; 


    file.close();
    file.open("shape.txt");

    for(int i = 0; i < coordCounter; i++){
        file >> coords[i];
    }
    file.close();

    //std::cout << "Raw input:" << std::endl;
    for(int i = 0; i < coordCounter; i++){
        std::cout << coords[i] << " ";
    }

    //Split the coordinates into two seperate arrays
    for(int i=0; i < coordCounter/2; i++){
        xCoords[i] = coords[xK];
        yCoords[i] = coords[yK];
        yK += 2;
        xK += 2;
    }


    //Calculate incline
   for(int i = 0; i < (coordCounter/2)-1; i++){
        deltaY = (yCoords[i+1] - yCoords[i]);
        deltaX = (xCoords[i+1] - xCoords[i]);
        kV = (deltaY/deltaX);
        kValue[i] = kV;
        kCalc++;
    }


    //If there's only one k-value, it must be a line.
    if(kCalc == 1){
        isLine = true;
    }

    //Checks if incline-values are same. 
    //If they are, it's a line, else it's a polygon (or triangle).
    if(kCalc > 1){
        for(int i=0; i < kCalc-1; i++){
            if(kValue[i] == kValue[i+1]){
                isLine = true;
            }else{
                isLine = false;
                isPolygon = true;
            }
        }
    }
    std::cout << '\n';
    //create new point object.
    if(coordCounter/2 == 1){
        Point point(coords, coordCounter); 
        std::cout << "\nType: " << point.getType();
        std::cout << "\nArea: " << point.getArea();
        std::cout << "\nConvex: " << point.isConvex();
        point.position();
        point.~Point();
    }

    //create new line object.
    if(isLine == true){
        Line line(coords, coordCounter);
        std::cout << "\nType: " << line.getType();
        std::cout << "\nArea: " << line.getArea();
        std::cout << "\nConvex: " << line.isConvex();
        line.position();
        line.~Line();
    }
    //create new triangle object.
    if(isPolygon == true && coordCounter/2 == 3 && isLine == false){
        Triangle triangle(coords, coordCounter);
        std::cout << "\nType: " << triangle.getType();
        std::cout << "\nArea: " << triangle.getArea();
        std::cout << "\nCircumference: " << triangle.circumference();
        std::cout << "\nConvex: " << triangle.isConvex();
        triangle.position();
        triangle.~Triangle();
    }
    //create new polygon object.
    if(isPolygon == true && coordCounter/2 > 3 && isLine == false){
        Polygon polygon(coords, coordCounter);
        std::cout << "\nType: " << polygon.getType();
        std::cout << "\nArea: " << polygon.getArea();
        std::cout << "\nCircumference: " << polygon.circumference();
        polygon.position();
        polygon.~Polygon();
    }

    delete[] coords;
    delete[] xCoords;
    delete[] yCoords;
    delete[] kValue;

    coords = NULL;
    xCoords = NULL;
    yCoords = NULL;
    kValue = NULL;

    std::cout << '\n';
    getchar();
    return 0;
}