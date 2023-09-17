#pragma once
#include <cmath>
#define PI 3.14159265358979323846


enum Angle_Type {
    RADIANS,
    DEGREES,
    RAD,
    DEG
};

class Angle{
    float degrees; 
    float radians;
public:
    Angle(float val){
        radians = val;
        degrees = radians * (180/PI);
    }

    Angle(float val, Angle_Type type){
        if(type == RADIANS || type == RAD){
            radians = val;
            degrees = radians * 180/PI;
        }else if(type == DEGREES || type == DEG){
            degrees = val;
            radians = degrees * PI/180;
        }
    }

    float Radians(){
        return radians;
    }
    float Degrees(){
        return degrees;
    }
};


// Vec2 Definition
class Vec2{
public:
    float x;
    float y;

    Vec2(){
        x = 0;
        y = 0;
    }

    Vec2(float vX, float vY){
        x = vX;
        y = vY;
    }

    Vec2 Add(Vec2 v) const{
        return Vec2(x + v.x, y + v.y);
    }

    Vec2 Add(float v) const{
        return Vec2(x + v, y + v);
    }

    Vec2 Subtract(Vec2 v) const{
        return Vec2(x - v.x, y - v.y);
    }

    Vec2 Subtract(float v) const{
        return Vec2(x - v, y - v);
    }

    Vec2 Multiply(Vec2 v) const{
        return Vec2(x * v.x, y * v.y);
    }

    Vec2 Multiply(float v) const{
        return Vec2(x * v, y * v);
    }

    Vec2 Divide(Vec2 v) const{
        return Vec2(x / v.x, y / v.y);
    }

    Vec2 Divide(float v) const{
        return Vec2(x / v, y / v);
    }

    bool Equals(Vec2 v) const{
        return x == v.x && y == v.y;
    }


    // Operator Overloading
    template<typename type>
    Vec2 operator+(type v) const {
        return Add(v);
    }
    template<typename type>
    Vec2 operator-(type v) const{
        return Subtract(v);
    }
    template<typename type>
    Vec2 operator*(type v) const{
        return Multiply(v);
    }
    template<typename type>
    Vec2 operator/(type v) const{
        return Divide(v);
    }

    template<typename type>
    void operator+=(type v){
        *this = Add(v);
    }
    template<typename type>
    void operator-=(type v){
        *this = Subtract(v);
    }
    template<typename type>
    void operator*=(type v){
        *this = Multiply(v);      
    }
    template<typename type>
    void operator/=(type v){
        *this = Divide(v);
    }


    // (==) Operator Overloading
    bool operator==(Vec2 v) const{
        return Equals(v);
    }
    // (!=) Operator Overloading
    bool operator!=(Vec2 v) const{
        return !Equals(v);
    }

    // (++) Operator Overloading
    void operator++(){
        *this = Add(1);
    }
    // (--) Operator Overloading
    void operator--(){
        *this = Subtract(1);
    }

    void Rotate(Angle theta){
        float cosTheta = std::cos(theta.Radians());
        float sinTheta = std::sin(theta.Radians());

        float nX = (x * cosTheta) - (y * sinTheta);
        float nY = (x * sinTheta) + (y * cosTheta);

        x = nX;
        y = nY;
    }
};

// Vec3 Definition
class Vec3{
public:
    float x;
    float y;
    float z;

    Vec3(){
        x = 0;
        y = 0;
        z = 0;
    }

    Vec3(float vX, float vY, float vZ){
        x = vX;
        y = vY;
        z = vZ;
    }

    Vec3 Add(Vec3 v) const{
        return Vec3(x + v.x, y + v.y, z + v.z);
    }

    Vec3 Add(float v) const{
        return Vec3(x + v, y + v, z + v);
    }

    Vec3 Subtract(Vec3 v) const{
        return Vec3(x - v.x, y - v.y, z - v.z);
    }

    Vec3 Subtract(float v) const{
        return Vec3(x - v, y - v, z - v);
    }

    Vec3 Multiply(Vec3 v) const{
        return Vec3(x * v.x, y * v.y, z * v.z);
    }

    Vec3 Multiply(float v) const{
        return Vec3(x * v, y * v, z * v);
    }

    Vec3 Divide(Vec3 v) const{
        return Vec3(x / v.x, y / v.y, z / v.z);
    }

    Vec3 Divide(float v) const{
        return Vec3(x / v, y / v, z / v);
    }

    bool Equals(Vec3 v) const{
        return x == v.x && y == v.y && z == v.z;
    }

    // Operator Overloading
    template<typename type>
    Vec3 operator+(type v) const {
        return Add(v);
    }
    template<typename type>
    Vec3 operator-(type v) const{
        return Subtract(v);
    }
    template<typename type>
    Vec3 operator*(type v) const{
        return Multiply(v);
    }
    template<typename type>
    Vec3 operator/(type v) const{
        return Divide(v);
    }

    template<typename type>
    void operator+=(type v){
        *this = Add(v);
    }
    template<typename type>
    void operator-=(type v){
        *this = Subtract(v);
    }
    template<typename type>
    void operator*=(type v){
        *this = Multiply(v);      
    }
    template<typename type>
    void operator/=(type v){
        *this = Divide(v);
    }


    // (==) Operator Overloading
    bool operator==(Vec3 v) const{
        return Equals(v);
    }
    // (!=) Operator Overloading
    bool operator!=(Vec3 v) const{
        return !Equals(v);
    }

    // (++) Operator Overloading
    void operator++(){
        *this = Add(1);
    }
    // (--) Operator Overloading
    void operator--(){
        *this = Subtract(1);
    }
};

class Mat2{
public:
    Vec2 x;
    Vec2 y;

    Mat2(){

    }

    Mat2(float x1, float y1, float x2, float y2){
        x.x = x1;
        y.x = x2;

        x.y = y1;
        y.y = y2;
    }

    Mat2 Add(Mat2 mat){
        return Mat2(
        x.x + mat.x.x, x.y + mat.x.y,
        y.x + mat.y.x, y.y + mat.y.y
        );
    }
    Mat2 Add(float scalar){
        return Mat2(
            x.x + scalar, x.y + scalar,
            y.x + scalar, y.y + scalar
        );
    }


    Mat2 Subtract(Mat2 mat){
        return Mat2(
        x.x - mat.x.x, x.y - mat.x.y,
        y.x - mat.y.x, y.y - mat.y.y
        );
    }
    Mat2 Subtract(float scalar){
        return Mat2(
            x.x - scalar, x.y - scalar,
            y.x - scalar, y.y - scalar
        );
    }


    Mat2 Multiply(Mat2 mat){
        return Mat2(
        (mat.x.x * x.x) + (mat.y.x * x.y), (mat.x.y * x.x) + (mat.y.y * x.y),
        (mat.x.x * y.x) + (mat.y.x * y.y), (mat.x.y * y.x) + (mat.y.y * y.y)
        );
    }
    Mat2 Multiply(float scalar){
        return Mat2(
            x.x * scalar, x.y * scalar,
            y.x * scalar, y.y * scalar
        );
    }
    Vec2 Multiply(Vec2 vec){
        return Vec2(
            (x.x * vec.x) + (x.y * vec.y),
            (y.x * vec.x) + (y.y * vec.y)
        );
    }

    Mat2 Divide(Mat2 mat){
        Mat2 inverseMat;
        if((mat.y.x < 0 && mat.x.y > 0) || (mat.y.x > 0 && mat.x.y < 0)){
            inverseMat = Mat2
            (
                mat.y.y, mat.x.y * -1,
                mat.y.x * -1, mat.x.x
            );
        }else{
            inverseMat = Mat2
            (
                mat.y.y, mat.x.y,
                mat.y.x, mat.x.x
            );
        }

        float determinant = (inverseMat.y.y * inverseMat.x.x) - (inverseMat.y.x * inverseMat.x.y);
        float scalar = 1.0/determinant;

        inverseMat = inverseMat.Multiply(scalar);
        return Multiply(inverseMat);
    }
    Mat2 Divide(float scalar){
        return Mat2(
            x.x / scalar, x.y / scalar,
            y.x / scalar, y.y / scalar
        );
    }


    bool Equals(Mat2 mat){
        return (
            (x.x == mat.x.x) && (x.y == mat.x.y) && 
            (y.x == mat.y.x) && (y.y == mat.y.y)
        );
    }


    template<typename type>
    Mat2 operator+(type v){
        return Add(v);
    }
    template<typename type>
    Mat2 operator-(type v){
        return Subtract(v);
    }
    template<typename type>
    Mat2 operator*(type v){
        return Multiply(v);
    }
    template<typename type>
    Mat2 operator/(type v){
        return Divide(v);
    }


    template<typename type>
    void operator+=(type v){
        *this = Add(v);
    }
    template<typename type>
    void operator-=(type v){
        *this = Subtract(v);
    }
    template<typename type>
    void operator*=(type v){
        *this = Multiply(v);
    }
    template<typename type>
    void operator/=(type v){
        *this = Divide(v);
    }


    bool operator==(Mat2 mat){
        return Equals(mat);
    }
    bool operator!=(Mat2 mat){
        return !Equals(mat);
    }
};

class Mat3{
public:
    Vec3 x;
    Vec3 y;
    Vec3 z;

    Mat3(){

    }

    Mat3(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3){
        x.x = x1;
        y.x = x2;
        z.x = x3;

        x.y = y1;
        y.y = y2;
        z.y = y3;

        x.z = z1;
        y.z = z2;
        z.z = z3;
    }

    Mat3 Add(Mat3 mat){
        return Mat3(
        x.x + mat.x.x, x.y + mat.x.y, x.z + mat.x.z,
        y.x + mat.y.x, y.y + mat.y.y, y.z + mat.y.z,
        z.x + mat.z.x, z.y + mat.z.y, z.z + mat.z.z
        );
    }
    Mat3 Add(float scalar){
        return Mat3(
        x.x + scalar, x.y + scalar, x.z + scalar,
        y.x + scalar, y.y + scalar, y.z + scalar,
        z.x + scalar, z.y + scalar, z.z + scalar
        );
    }


    Mat3 Subtract(Mat3 mat){
        return Mat3(
     x.x - mat.x.x, x.y - mat.x.y, x.z - mat.x.z,
        y.x - mat.y.x, y.y - mat.y.y, y.z - mat.y.z,
        z.x - mat.z.x, z.y - mat.z.y, z.z - mat.z.z
        );
    }
    Mat3 Subtract(float scalar){
        return Mat3(
        x.x - scalar, x.y - scalar, x.z - scalar,
        y.x - scalar, y.y - scalar, y.z - scalar,
        z.x - scalar, z.y - scalar, z.z - scalar
        );
    }


    Mat3 Multiply(Mat3 mat){
        return Mat3(
        (x.x * mat.x.x) + (x.y * mat.y.x) + (x.z * mat.z.x), (x.x * mat.x.y) + (x.y * mat.y.y) + (x.z * mat.z.y), (x.x * mat.x.z) + (x.y * mat.y.z) + (x.z * mat.z.z),
        (y.x * mat.x.x) + (y.y * mat.y.x) + (y.z * mat.z.x), (y.x * mat.x.y) + (y.y * mat.y.y) + (y.z * mat.z.y), (y.x * mat.x.z) + (y.y * mat.y.z) + (y.z * mat.z.z),
        (z.x * mat.x.x) + (z.y * mat.y.x) + (z.z * mat.z.x), (z.x * mat.x.y) + (z.y * mat.y.y) + (z.z * mat.z.y), (z.x * mat.x.z) + (z.y * mat.y.z) + (z.z * mat.z.z)
        );
    }
    Mat3 Multiply(float scalar){
        return Mat3(
        x.x * scalar, x.y * scalar, x.z * scalar,
        y.x * scalar, y.y * scalar, y.z * scalar,
        z.x * scalar, z.y * scalar, z.z * scalar
        );
    }
    Vec3 Multiply(Vec3 vec){
        return Vec3(
        (x.x * vec.x) + (x.y * vec.y) + (x.y * vec.z),
        (y.x * vec.x) + (y.y * vec.y) + (y.y * vec.z),
        (z.x * vec.x) + (z.y * vec.y) + (z.y * vec.z)
        );
   }

   
    // I ain't writting matrix division for Mat3, hell no

    // Mat3 Divide(Mat3 mat){
    //
    // }

    Mat3 Divide(float scalar){
        return Mat3(
        x.x / scalar, x.y / scalar, x.z / scalar,
        y.x / scalar, y.y / scalar, y.z / scalar,
        z.x / scalar, z.y / scalar, z.z / scalar
        );
    }


    bool Equals(Mat3 mat){
        return (
            (x.x == mat.x.x) && (x.y == mat.x.y) && (x.z == mat.x.z) && 
            (y.x == mat.y.x) && (y.y == mat.y.y) && (y.z == mat.y.z) &&
            (z.x == mat.z.x) && (z.y == mat.z.y) && (z.z == mat.z.z)
        );
    }


    template<typename type>
    Mat3 operator+(type v){
        return Add(v);
    }
    template<typename type>
    Mat3 operator-(type v){
        return Subtract(v);
    }
    template<typename type>
    Mat3 operator*(type v){
        return Multiply(v);
    }
    template<typename type>
    Mat3 operator/(type v){
        return Divide(v);
    }


    template<typename type>
    void operator+=(type v){
        *this = Add(v);
    }
    template<typename type>
    void operator-=(type v){
        *this = Subtract(v);
    }
    template<typename type>
    void operator*=(type v){
        *this = Multiply(v);
    }
    template<typename type>
    void operator/=(type v){
        *this = Divide(v);
    }


    bool operator==(Mat3 mat){
        return Equals(mat);
    }
    bool operator!=(Mat3 mat){
        return !Equals(mat);
    }
};