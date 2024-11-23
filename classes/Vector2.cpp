#include "Vector2.h"

Vector2 Vector2::operator+(Vector2 const& obj) {
    Vector2 res;
    res.x = this->x + obj.x;
    res.y = this->y + obj.y;
    return res;
}