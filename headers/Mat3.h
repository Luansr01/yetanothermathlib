#pragma once
#include "Vec3.h"
#include "Angle.h"

class Mat3{
private:
    Vec3 arr[3];
public:
    Vec3& x = arr[0];
    Vec3& y = arr[1];
    Vec3& z = arr[2];

    Vec3& operator[](int index);

    Mat3();

    Mat3(float xx, float xy, float xz, float yx, float yy, float yz, float zx, float zy, float zz);

    Mat3(Vec3 vx, Vec3 vy, Vec3 vz);

    Mat3(Angle ax, Angle ay, Angle az);

    bool Equals(Mat3 mat);

    Mat3 Add(Mat3 mat);
    Mat3 Add(float scalar);

    Mat3 Subtract(Mat3 mat);
    Mat3 Subtract(float scalar);

    Mat3 Multiply(Mat3 mat);
    Mat3 Multiply(float scalar);

    Mat3 Divide(Mat3 mat);
    Mat3 Divide(float scalar);

    template <typename T>
    Mat3 operator+(T val){
        return Add(val);
    }
    template <typename T>
    Mat3 operator-(T val){
        return Subtract(val);
    }
    template <typename T>
    Mat3 operator*(T val){
        return Multiply(val);
    }
    template <typename T>
    Mat3 operator/(T val){
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

    bool operator==(Mat3 mat);
    bool operator!=(Mat3 mat);

    void operator=(Mat3 mat);
};