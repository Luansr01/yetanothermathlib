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
    float* x = &arr[0];
    float* y = &arr[1];
    
    float& operator[](int index){
        return arr[index];
    }

    Vec2(){
        for(int i = 0; i < 2; i++){
            (*this)[i] = 0;
        }
    }
    Vec2(float vx, float vy){
        (*this)[0] = vx;
        (*this)[1] = vy;
    }
};