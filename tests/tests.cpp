#include <iostream>
#include "Vec2.h"
#include "Mat2.h"
#include "Vec3.h"
#include "Mat3.h"

void printMem(void* ptr){
    std::cout << "\t" << ptr << "\n";
}

template <typename T>
void printType(T a){
    std::cout << typeid(T).name();
}

void printVec2(Vec2 vec){
    std::cout << "[" << vec.x << ", " << vec.y << "]" << "\n";
}

void printMat2(Mat2 mat){
    printVec2(mat.x);
    printVec2(mat.y);
}

void printVec3(Vec3 vec){
    std::cout << "[" << vec.x << ", " << vec.y << ", " << vec.z << "]" << "\n";
}

void printMat3(Mat3 mat){
    printVec3(mat.x);
    printVec3(mat.y);
    printVec3(mat.z);
}

void printAngle(Angle a){
    std::cout << "Degrees: " << a.Deg() << "\n" << "Radians: " << a.Rad() << "\n";
}

void newline(){
    std::cout << "\n";
}

int main(){
    newline();

    Angle ang(5, DEGREES);
    printType(ang);
    printMem(&ang);
    printAngle(ang);

    newline();

    Vec2 v2(1, 2);
    printType(v2);
    printMem(&v2);
    printVec2(v2);

    newline();

    Vec3 v3(1, 2, 3);
    printType(v3);
    printMem(&v3);
    printVec3(v3);

    newline();

    Mat2 m2(1, 2, 3, 4);
    printType(m2);
    printMem(&m2);
    printMat2(m2);

    newline();

    Mat3 m3(1, 2, 3, 4, 5, 6, 7, 8, 9);
    printType(m3);
    printMem(&m3);
    printMat3(m3);
}