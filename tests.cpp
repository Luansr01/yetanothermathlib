#include <iostream>
#include <mymath.h>

void printVec2(Vec2 vec){
    std::cout << "[" << vec.x << ", " << vec.y << "]" << "\n";
}

void printMat2(Mat2 mat){
    printVec2(mat.x);
    printVec2(mat.y);
}

int main(){
    Vec2 vec(1.0, 2.0);
    printVec2(vec);

    std::cout << "\n";

    Mat2 mat(1, 1, 0, 1);
    mat *= Mat2(2, 5, 6, 7);
    printMat2(mat);
}