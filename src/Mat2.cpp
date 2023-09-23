#include "Mat2.h"
#include <cmath>
#include <stdexcept>

Vec2& Mat2::operator[](int index){
    if(index >= 0 && index <= 2){
        return arr[index];
    }else{
        throw std::out_of_range("Index out of Range.");
    }
}

Mat2::Mat2(){
    x = Vec2();
    y = Vec2();
}

Mat2::Mat2(float xx, float xy, float yx, float yy){
    x = Vec2(xx, xy);
    y = Vec2(yx, yy);
}

Mat2::Mat2(Vec2 vecX, Vec2 vecY){
    arr[0] = vecX;
    arr[1] = vecX;
}

Mat2::Mat2(Angle theta){
    (*this) = Mat2(
        std::cos(theta.Rad()), -std::sin(theta.Rad()),
        std::sin(theta.Rad()), std::cos(theta.Rad())
    );
}

bool Mat2::Equals(Mat2 mat){
    return ((x == mat.x) && (y == mat.y));
}

Mat2 Mat2::Add(Mat2 mat){
    return Mat2(x + mat.x, y + mat.y);
}
Mat2 Mat2::Add(float scalar){
    return Mat2(x + scalar, y + scalar);
}

Mat2 Mat2::Subtract(Mat2 mat){
    return Mat2(x - mat.x, y - mat.y);
}
Mat2 Mat2::Subtract(float scalar){
    return Mat2(x - scalar, y - scalar);
}

Mat2 Mat2::Multiply(Mat2 mat){
    Mat2 newMat = Mat2();
    for(int m = 0; m < 2; m++){
        for(int r = 0; r < 2; r++){
            for(int k = 0; k < 2; k++){
                newMat[m][r] += arr[m][k] * mat[k][r];
            }
        }
    }
    return newMat;
}
Mat2 Mat2::Multiply(float scalar){
    return Mat2(x * scalar, y * scalar);
}

Mat2 Mat2::Divide(Mat2 mat){
    return Mat2(x / mat.x, y / mat.y);
}
Mat2 Mat2::Divide(float scalar){
    return Mat2(x / scalar, y / scalar);
}

bool Mat2::operator==(Mat2 mat){
    return Equals(mat);
}

bool Mat2::operator!=(Mat2 mat){
    return !Equals(mat);
}

void Mat2::operator=(Mat2 mat){
    x = mat.x;
    y = mat.y;
}