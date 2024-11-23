#include <iostream>
#include <conio.h>
#include <map>
#include <typeinfo>
#include "classes/ArgumentHelper.h"

int main(int argc, char *argv[]) {

    std::map<std::string, const std::type_info&> flagmap;

    flagmap.insert({"quantity", typeid(int)});
    flagmap.insert({"points", typeid(int)});
    flagmap.insert({"debug", typeid(bool)});
    flagmap.insert({"max_simulations", typeid(int)});

    ArgumentHelper *args = new ArgumentHelper(argc, argv, flagmap);

    std::cout << "Running with " << std::to_string(argc-1) << " argument(s)";
    getch();
    return 0;
}