#include "MovementVector.h"
#include "Vector2.h"
#include <cmath>

Vector2 MovementVector::getEndOfVectorAsInteger() {
    Vector2 integerPosition;
    integerPosition.x = cos(this->angle)*this->length;
    integerPosition.y = sin(this->angle)*this->length;
    return this->position + integerPosition;
}