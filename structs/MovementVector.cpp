#include "MovementVector.h"
#include "Position.h"
#include <cmath>

Position MovementVector::getEndOfVectorAsInteger() {
    Position integerPosition;
    integerPosition.x = cos(this->angle)*this->length;
    integerPosition.y = sin(this->angle)*this->length;
    return this->
}