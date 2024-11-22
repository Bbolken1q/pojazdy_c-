#ifndef MOVEMENT_VECTOR_H
#define MOVEMENT_VECTOR_H

#include <iostream>
#include "Position.h"

class MovementVector {
    public:
        Position position;
        int length;
        float angle;
        Position getEndOfVectorAsInteger();
};

#endif