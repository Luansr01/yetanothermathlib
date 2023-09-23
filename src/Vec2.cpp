#include "Vec2.h"
#include <cmath>
#include <stdexcept>

float& Vec2::operator[](int index){
    if(index >= 0 && index <= 2){
        return arr[index];
    }else{
        throw std::out_of_range("Index out of Range.");
    }
}

Vec2::Vec2(){
    for(int i = 0; i < 2; i++){
        arr[i] = 0;
    }
}
Vec2::Vec2(float vx, float vy){
    arr[0] = vx;
    arr[1] = vy;
}

bool Vec2::Equals(Vec2 vec){
    return ((x == vec.x) && (y == vec.y));
}

Vec2 Vec2::Add(Vec2 vec){
    return Vec2(x + vec.x, y + vec.y);
}
Vec2 Vec2::Add(float scalar){
    return Vec2(x + scalar, y + scalar);
}

Vec2 Vec2::Subtract(Vec2 vec){
    return Vec2(x - vec.x, y - vec.y);
}
Vec2 Vec2::Subtract(float scalar){
    return Vec2(x - scalar, y - scalar);
}

Vec2 Vec2::Multiply(Vec2 vec){
    return Vec2(x * vec.x, y * vec.y);
}
Vec2 Vec2::Multiply(float scalar){
    return Vec2(x * scalar, y * scalar);
}

Vec2 Vec2::Divide(Vec2 vec){
    return Vec2(x / vec.x, y / vec.y);
}
Vec2 Vec2::Divide(float scalar){
    return Vec2(x / scalar, y / scalar);
}

void Vec2::operator=(Vec2 val){
    (*this)[0] = val[0];
    (*this)[1] = val[1];
}

bool Vec2::operator==(Vec2 val){
    return (*this).Equals(val);
}