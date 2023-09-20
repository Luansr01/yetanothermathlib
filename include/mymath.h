#pragma once
#include <cmath>

#define PI 3.14159265358979323846
#define RAD_DEG 0.01745329251
#define DEG_RAD 57.2957795131

enum Angle_Unit {
    RADIANS,
    DEGREES,
};

class Angle{
    float rad;
public:
    float& Rad(){
        return rad; 
    }
    float Deg(){
        return rad * DEG_RAD;
    }
    
    Angle(float val){
        Rad() = val;
    }
    
    Angle(float val, Angle_Unit unit){
        if(unit == RADIANS){
            Rad() = val;
        }else if(unit == DEGREES){
            Rad() = val * RAD_DEG;
        }
    }
};


class Vec2{
private:
    float arr[2];
public:
    float& x = arr[0];
    float& y = arr[1];
    
    float& operator[](int index){
        if(index >= 0 && index <= 2){
            return arr[index];
        }else{
            throw std::out_of_range("Index out of Range.");
        }
    }

    Vec2(){
        for(int i = 0; i < 2; i++){
            arr[i] = 0;
        }
    }
    Vec2(float vx, float vy){
        arr[0] = vx;
        arr[1] = vy;
    }

    Vec2 Add(Vec2 vec){
        return Vec2(x + vec.x, y + vec.y);
    }
    Vec2 Add(float scalar){
        return Vec2(x + scalar, y + scalar);
    }

    Vec2 Subtract(Vec2 vec){
        return Vec2(x - vec.x, y - vec.y);
    }
    Vec2 Subtract(float scalar){
        return Vec2(x - scalar, y - scalar);
    }

    Vec2 Multiply(Vec2 vec){
        return Vec2(x * vec.x, y * vec.y);
    }
    Vec2 Multiply(float scalar){
        return Vec2(x * scalar, y * scalar);
    }

    Vec2 Divide(Vec2 vec){
        return Vec2(x / vec.x, y / vec.y);
    }
    Vec2 Divide(float scalar){
        return Vec2(x / scalar, y / scalar);
    }

    template <typename T>
    Vec2 operator+(T val){
        return Add(val);
    }
    template <typename T>
    Vec2 operator-(T val){
        return Subtract(val);
    }
    template <typename T>
    Vec2 operator*(T val){
        return Multiply(val);
    }
    template <typename T>
    Vec2 operator/(T val){
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

    void operator=(Vec2 val){
        (*this)[0] = val[0];
        (*this)[1] = val[1];
    }
};

class Mat2{
private:
    Vec2 arr[2];
public:
    Vec2& x = arr[0];
    Vec2& y = arr[1];

    Vec2& operator[](int index){
        if(index >= 0 && index <= 2){
            return arr[index];
        }else{
            throw std::out_of_range("Index out of Range.");
        }
    }

    Mat2(){
        x = Vec2();
        y = Vec2();
    }

    Mat2(float xx, float xy, float yx, float yy){
        x = Vec2(xx, xy);
        y = Vec2(yx, yy);
    }

    Mat2(Vec2 vecX, Vec2 vecY){
        arr[0] = vecX;
        arr[1] = vecX;
    }

    Mat2 Add(Mat2 mat){
        return Mat2(x + mat.x, y + mat.y);
    }
    Mat2 Add(float scalar){
        return Mat2(x + scalar, y + scalar);
    }

    Mat2 Subtract(Mat2 mat){
        return Mat2(x - mat.x, y - mat.y);
    }
    Mat2 Subtract(float scalar){
        return Mat2(x - scalar, y - scalar);
    }

    Mat2 Multiply(Mat2 mat){
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
    Mat2 Multiply(float scalar){
        return Mat2(x * scalar, y * scalar);
    }

    Mat2 Divide(Mat2 mat){
        return Mat2(x / mat.x, y / mat.y);
    }
    Mat2 Divide(float scalar){
        return Mat2(x / scalar, y / scalar);
    }

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

    void operator=(Mat2 mat){
        x = mat.x;
        y = mat.y;
    }
};

class Vec3{
private:
    float arr[3];
public:
    float& x = arr[0];
    float& y = arr[1];
    float& z = arr[2];

    float& operator[](int index){
        if(index >= 0 && index <= 2){
            return arr[index];
        }else{
            throw std::out_of_range("Index out of Range.");
        }
    }
    Vec3(){
        for(int i = 0; i < 3; i++){
            arr[i] = 0;
        }
    }

    Vec3(float vx, float vy, float vz){
        arr[0] = vx;
        arr[1] = vy;
        arr[2] = vz;
    }

    Vec3(Vec2 vecXY, float vz){
        arr[0] = vecXY.x;
        arr[1] = vecXY.y;
        arr[2] = vz;
    }


    Vec3 Add(Vec3 vec){
        return Vec3(x + vec.x, y + vec.y, z + vec.z);
    }
    Vec3 Add(float scalar){
        return Vec3(x + scalar, y + scalar, z + scalar);
    }

    Vec3 Subtract(Vec3 vec){
        return Vec3(x - vec.x, y - vec.y, z - vec.z);
    }
    Vec3 Subtract(float scalar){
        return Vec3(x - scalar, y - scalar, z - scalar);
    }

    Vec3 Multiply(Vec3 vec){
        return Vec3(x * vec.x, y * vec.y, z * vec.z);
    }
    Vec3 Multiply(float scalar){
        return Vec3(x * scalar, y * scalar, z * scalar);
    }

    Vec3 Divide(Vec3 vec){
        return Vec3(x / vec.x, y / vec.y, z / vec.z);
    }
    Vec3 Divide(float scalar){
        return Vec3(x / scalar, y / scalar, z / scalar);
    }

    template <typename T>
    Vec3 operator+(T val){
        return Add(val);
    }
    template <typename T>
    Vec3 operator-(T val){
        return Subtract(val);
    }
    template <typename T>
    Vec3 operator*(T val){
        return Multiply(val);
    }
    template <typename T>
    Vec3 operator/(T val){
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

    void operator=(Vec3 val){
        arr[0] = val[0];
        arr[1] = val[1];
        arr[2] = val[2];
    }  
};

class Mat3{
private:
    Vec3 arr[3];
public:
    Vec3& x = arr[0];
    Vec3& y = arr[1];
    Vec3& z = arr[2];

    Mat3(float xx, float xy, float xz, float yx, float yy, float yz, float zx, float zy, float zz){
        x = Vec3(xx, xy, xz);
        y = Vec3(yx, yy, yz);
        z = Vec3(zx, zy, zz);
    }

    Mat3(Vec3 vx, Vec3 vy, Vec3 vz){
        x = vx;
        y = vy;
        z = vz;
    }

    Mat3 Add(Mat3 mat){
        return Mat3(x + mat.x, y + mat.y, z + mat.z);
    }
    Mat3 Add(float scalar){
        return Mat3(x + scalar, y + scalar, z + scalar);
    }

    Mat3 Subtract(Mat3 mat){
        return Mat3(x - mat.x, y - mat.y, z - mat.z);
    }
    Mat3 Subtract(float scalar){
        return Mat3(x - scalar, y - scalar, z - scalar);
    }

    Mat3 Multiply(Mat3 mat){
        return Mat3(x * mat.x, y * mat.y, z * mat.z);
    }
    Mat3 Multiply(float scalar){
        return Mat3(x * scalar, y * scalar, z * scalar);
    }

    Mat3 Divide(Mat3 mat){
        return Mat3(x / mat.x, y / mat.y, z / mat.z);
    }
    Mat3 Divide(float scalar){
        return Mat3(x / scalar, y / scalar, z / scalar);
    }

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

    void operator=(Mat3 mat){
        x = mat.x;
        y = mat.y;
        z = mat.z;
    }
};