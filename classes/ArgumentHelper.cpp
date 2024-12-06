#include "ArgumentHelper.h"
#include "typeDefinition.h"
#include <stdexcept>
#include <map>
#include <typeinfo>
#include <any>

ArgumentHelper::ArgumentHelper(int f_argc, char *f_argv[], std::map<std::string, const std::type_info&> flagmap) {
    for (int i = 0; i < f_argc; i++)
    {
        for (auto const [key, value]: flagmap)
        {   
            if(f_argv[i] == key) {
                // std::cout << "found argument " << key << " with value " << f_argv[i+1] <<"\n"; 
                typeDefinition type = {value, std::make_any<const char*>(f_argv[i+1])};
                // type.typeInfo = map.second;
                this->argValues.insert({key, type});
            }
        }
         
    }
}