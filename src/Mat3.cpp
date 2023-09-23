#include "Mat3.h"
#include <cmath>
#include <stdexcept>

Vec3& Mat3::operator[](int index){
    if(index >= 0 && index <= 2){
        return arr[index];
    }else{
        throw std::out_of_range("Index out of Range.");
    }
}

Mat3::Mat3(){
    for(int i = 0; i < 3; i++){
        arr[i] = Vec3();
    }
}

Mat3::Mat3(float xx, float xy, float xz, float yx, float yy, float yz, float zx, float zy, float zz){
    x = Vec3(xx, xy, xz);
    y = Vec3(yx, yy, yz);
    z = Vec3(zx, zy, zz);
}

Mat3::Mat3(Vec3 vx, Vec3 vy, Vec3 vz){
    x = vx;
    y = vy;
    z = vz;
}

Mat3::Mat3(Angle ax, Angle ay, Angle az){
    float axcos = std::cos(ax.Rad());
    float aycos = std::cos(ay.Rad());
    float azcos = std::cos(az.Rad());

    float axsin = std::sin(ax.Rad());
    float aysin = std::sin(ay.Rad());
    float azsin = std::sin(az.Rad());


    (*this) = 
    Mat3(
        1., 0., 0.,
        0., axcos, -axsin,
        0., axsin, axcos
    )*
    Mat3(
        aycos, 0., aysin,
        0., 1., 0.,
        -aysin, 0, aycos
    )*
    Mat3(
        azcos, -azsin, 0,
        azsin, azcos, 0,
        0, 0, 1
    );
        
}

bool Mat3::Equals(Mat3 mat){
    return ((x == mat.x) && (y == mat.y) && (z == mat.z));
}

Mat3 Mat3::Add(Mat3 mat){
    return Mat3(x + mat.x, y + mat.y, z + mat.z);
}
Mat3 Mat3::Add(float scalar){
    return Mat3(x + scalar, y + scalar, z + scalar);
}

Mat3 Mat3::Subtract(Mat3 mat){
    return Mat3(x - mat.x, y - mat.y, z - mat.z);
}
Mat3 Mat3::Subtract(float scalar){
    return Mat3(x - scalar, y - scalar, z - scalar);
}

Mat3 Mat3::Multiply(Mat3 mat){
    Mat3 newMat = Mat3();
    for(int m = 0; m < 3; m++){
        for(int r = 0; r < 3; r++){
            for(int k = 0; k < 3; k++){
                newMat[m][r] += arr[m][k] * mat[k][r];
            }
        }
    }
    return newMat;
}
Mat3 Mat3::Multiply(float scalar){
    return Mat3(x * scalar, y * scalar, z * scalar);
}

Mat3 Mat3::Divide(Mat3 mat){
    return Mat3(x / mat.x, y / mat.y, z / mat.z);
}
Mat3 Mat3::Divide(float scalar){
    return Mat3(x / scalar, y / scalar, z / scalar);
}

bool Mat3::operator==(Mat3 mat){
    return Equals(mat);
}
bool Mat3::operator!=(Mat3 mat){
    return !Equals(mat);
}

void Mat3::operator=(Mat3 mat){
    x = mat.x;
    y = mat.y;
    z = mat.z;
}