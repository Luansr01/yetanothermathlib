#pragma once

class Vec2{
private:
    float arr[2];
public:
    float& x = arr[0];
    float& y = arr[1];
    
    Vec2();
    Vec2(float vx, float vy);

    bool Equals(Vec2 vec);

    Vec2 Add(Vec2 vec);
    Vec2 Add(float scalar);

    Vec2 Subtract(Vec2 vec);
    Vec2 Subtract(float scalar);

    Vec2 Multiply(Vec2 vec);
    Vec2 Multiply(float scalar);

    Vec2 Divide(Vec2 vec);
    Vec2 Divide(float scalar);

    bool operator==(Vec2 vec);
    bool operator!=(Vec2 vec);
    void operator=(Vec2 val);
    float& operator[](int index);

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

};