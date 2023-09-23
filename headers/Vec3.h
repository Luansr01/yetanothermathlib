#pragma once
#include "Vec2.h"

class Vec3{
private:
    float arr[3];
public:
    float& x = arr[0];
    float& y = arr[1];
    float& z = arr[2];
    
    Vec3();
    Vec3(float vx, float vy, float vz);
    Vec3(Vec2 vecXY, float vz);

    bool Equals(Vec3 vec);

    Vec3 Add(Vec3 vec);
    Vec3 Add(float scalar);

    Vec3 Subtract(Vec3 vec);
    Vec3 Subtract(float scalar);

    Vec3 Multiply(Vec3 vec);
    Vec3 Multiply(float scalar);

    Vec3 Divide(Vec3 vec);
    Vec3 Divide(float scalar);

    bool operator==(Vec3 vec);
    bool operator!=(Vec3 vec);
    void operator=(Vec3 val);
    float& operator[](int index);


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
};