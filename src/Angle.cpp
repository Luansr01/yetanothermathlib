#include "Angle.h"
#define PI 3.14159265358979323846
#define RAD_DEG 0.01745329251
#define DEG_RAD 57.2957795131
    

float Angle::Deg(){ return rad * DEG_RAD; }
    
Angle::Angle(float val){
    Rad() = val;
}

Angle::Angle(float val, Angle_Unit unit){
    if(unit == RADIANS){
        Rad() = val;
    }else if(unit == DEGREES){
        Rad() = val * RAD_DEG;
    }
}