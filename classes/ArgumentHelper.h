#include <map>
#include <typeinfo>
#include <any>
#include "typeDefinition.h"

#ifndef MOVEMENT_VECTOR_H
#define MOVEMENT_VECTOR_H

class ArgumentHelper {
public:
    std::map<std::string, typeDefinition> argValues;
    ArgumentHelper(int f_argc, char *f_argv[], std::map<std::string, const std::type_info&> flagmap);
};




#endif