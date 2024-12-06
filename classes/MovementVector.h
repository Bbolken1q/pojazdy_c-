#ifndef MOVEMENT_VECTOR_H
#define MOVEMENT_VECTOR_H
#pragma once

#include <iostream>
#include "Vector2.h"

class MovementVector {
    public:
        Vector2 position;
        int length;
        float angle;
        Vector2 getEndOfVectorAsInteger();
};

#endif