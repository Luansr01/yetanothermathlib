#include "Vec3.h"
#include <stdexcept>

float& Vec3::operator[](int index){
    if(index >= 0 && index <= 2){
        return arr[index];
    }else{
        throw std::out_of_range("Index out of Range.");
    }
}
Vec3::Vec3(){
    for(int i = 0; i < 3; i++){
        arr[i] = 0;
    }
}

Vec3::Vec3(float vx, float vy, float vz){
    arr[0] = vx;
    arr[1] = vy;
    arr[2] = vz;
}

Vec3::Vec3(Vec2 vecXY, float vz){
    arr[0] = vecXY.x;
    arr[1] = vecXY.y;
    arr[2] = vz;
}

bool Vec3::Equals(Vec3 vec){
    return ((x == vec.x) && (y = vec.y) && (z == vec.z));
}

Vec3 Vec3::Add(Vec3 vec){
    return Vec3(x + vec.x, y + vec.y, z + vec.z);
}
Vec3 Vec3::Add(float scalar){
    return Vec3(x + scalar, y + scalar, z + scalar);
}

Vec3 Vec3::Subtract(Vec3 vec){
    return Vec3(x - vec.x, y - vec.y, z - vec.z);
}
Vec3 Vec3::Subtract(float scalar){
    return Vec3(x - scalar, y - scalar, z - scalar);
}

Vec3 Vec3::Multiply(Vec3 vec){
    return Vec3(x * vec.x, y * vec.y, z * vec.z);
}
Vec3 Vec3::Multiply(float scalar){
    return Vec3(x * scalar, y * scalar, z * scalar);
}

Vec3 Vec3::Divide(Vec3 vec){
    return Vec3(x / vec.x, y / vec.y, z / vec.z);
}
Vec3 Vec3::Divide(float scalar){
    return Vec3(x / scalar, y / scalar, z / scalar);
}


bool Vec3::operator==(Vec3 vec){
    return Equals(vec);
}
bool Vec3::operator!=(Vec3 vec){
    return !Equals(vec);
}

void Vec3::operator=(Vec3 val){
    arr[0] = val[0];
    arr[1] = val[1];
    arr[2] = val[2];
}  