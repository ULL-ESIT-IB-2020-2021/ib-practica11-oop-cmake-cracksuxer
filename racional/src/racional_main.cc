#include <iostream>
#include <map>
#include "racional.h"
#include "tools.h"

int main(int argc, char *argv[]){
    InputHandler(argc, argv);
    std::string file_name = argv[1];
    Racional rac1(1,1), rac2(1, 1), rac3;
    std::cout << rac1 + rac2 << std::endl;   //First output
    std::cin >> rac1;                       
    std::cout << rac1 << std::endl;          //Second output
    rac3 = rac1 * (rac2 / rac2 + rac1);
    std::cout << rac3 << std::endl;          //Third output
    std::map<std::string, Racional*> rac_file_objs = ParseRacionalesText();
    Output_operats(file_name, rac_file_objs);
}

