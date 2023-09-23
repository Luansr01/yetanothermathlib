#pragma once
#include "Vec2.h"
#include "Angle.h"

class Mat2{
private:
    Vec2 arr[2];
public:
    Vec2& x = arr[0];
    Vec2& y = arr[1];

    Vec2& operator[](int index);

    Mat2();

    Mat2(float xx, float xy, float yx, float yy);

    Mat2(Vec2 vecX, Vec2 vecY);

    Mat2(Angle theta);

    bool Equals(Mat2 mat);

    Mat2 Add(Mat2 mat);
    Mat2 Add(float scalar);

    Mat2 Subtract(Mat2 mat);
    Mat2 Subtract(float scalar);

    Mat2 Multiply(Mat2 mat);
    Mat2 Multiply(float scalar);

    Mat2 Divide(Mat2 mat);
    Mat2 Divide(float scalar);

    template <typename T>
    Mat2 operator+(T val){
        return Add(val);
    }
    template <typename T>
    Mat2 operator-(T val){
        return Subtract(val);
    }
    template <typename T>
    Mat2 operator*(T val){
        return Multiply(val);
    }
    template <typename T>
    Mat2 operator/(T val){
        return Divide(val);
    }

    template <typename T>
    void operator+=(T val){
        *this = Add(val);
    }
    template <typename T>
    void operator-=(T val){
        *this = Subtract(val);
    }
    template <typename T>
    void operator*=(T val){
        *this = Multiply(val);
    }
    template <typename T>
    void operator/=(T val){
        *this = Divide(val);
    }

    bool operator==(Mat2 mat);

    bool operator!=(Mat2 mat);

    void operator=(Mat2 mat);
};