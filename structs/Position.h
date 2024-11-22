#ifndef POSITION_H
#define POSITION_H

#include <iostream>

class Position{
    public:
    int x;
    int y;
    Position operator+(Position const& obj) {
        Position res;
        res.x = this->x + obj.x;
        res.y = this->y + obj.y;
        return res;
    }
};

#endif