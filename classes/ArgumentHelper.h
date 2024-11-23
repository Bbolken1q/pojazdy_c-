#include <map>
#include <typeinfo>

#ifndef MOVEMENT_VECTOR_H
#define MOVEMENT_VECTOR_H

class ArgumentHelper
{
private:
    int argc;
    char *argv[];
public:
    ArgumentHelper(int f_argc, char *f_argv[], std::map<std::string, const std::type_info&> flagmap);
};




#endif