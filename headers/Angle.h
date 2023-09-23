#pragma once

enum Angle_Unit {
    RADIANS,
    DEGREES,
};

class Angle{
    float rad;
public:
    float& Rad(){ return rad; }
    float Deg();
    
    Angle(float val);
    Angle(float val, Angle_Unit unit);
};