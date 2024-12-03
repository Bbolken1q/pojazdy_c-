#include <iostream>
#include <conio.h>
#include <map>
#include <typeinfo>
#include "classes/ArgumentHelper.h"
#include <any>

int main(int argc, char *argv[]) {

    std::map<std::string, const std::type_info&> flagmap;

    flagmap.insert({"--quantity", typeid(int)});
    flagmap.insert({"--points", typeid(int)});
    flagmap.insert({"--debug", typeid(bool)});
    flagmap.insert({"--max_simulations", typeid(int)});

    ArgumentHelper *args = new ArgumentHelper(argc, argv, flagmap);

    for(const auto& elem : args->argValues)
    {
        std::cout << elem.first << " " << elem.second.typeInfo.name() << " " << std::any_cast<const char*>(elem.second.value) << "\n";
    }

    std::cout << "Running with " << std::to_string(argc-1) << " argument(s)";
    // getch();
    return 0;
}