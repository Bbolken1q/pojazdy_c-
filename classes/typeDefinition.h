#ifndef TYPE_DEFINITION_H
#define TYPE_DEFINITION_H

#include <iostream>
#include <typeinfo>
#include <any>

struct typeDefinition {
    const std::type_info& typeInfo;
    std::any value;
};

#endif