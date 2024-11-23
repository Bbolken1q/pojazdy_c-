#ifndef VECTOR2_H
#define VECTOR2_H

#include <iostream>

class Vector2 {
    public:
    int x;
    int y;
    Vector2 operator+(Vector2 const& obj);
};

#endif