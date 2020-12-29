#include <iostream>
#include <cstring>
#include <map>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include "tools.h"

void InputHandler(int argc, char *argv[]){
    if(argc == 2 && strcmp(argv[1], "--NumerosRacionales") == 0){
        std::cout << "Modo de uso: ./racionales fichero_entrada fichero_salida\n"
                    "fichero_entrada: Fichero de texto conteniendo líneas con un par de números racionales: `a/b c/d` separados por un espacio\n"
                    "fichero_salida:  Fichero de texto que contendrá líneas con las operaciones realizadas: `a/b + c/d = n/m`\n" << std::endl;
        exit(EXIT_SUCCESS);
    }
    if(argc == 2 && strcmp(argv[1], "--help") == 0){
        std::cout << "Modo de uso: ./racionales fichero_entrada fichero_salida/n"
                     "Pruebe ./racionales --help para más información" << std::endl;
        exit(EXIT_SUCCESS);
    }
    if(argc != 2){
        std::cout << "Error en el numero de argumentos, pruebe --help para mayor informacion\n";
        exit(EXIT_SUCCESS);
    }
}

int GetTotalLines(){
    int number_of_lines{0};
    std::string line;
    std::ifstream myfile("rac.txt");
    while (std::getline(myfile, line)) number_of_lines++;
    myfile.close();
    return number_of_lines;
}

void Rac_map_objs(std::vector<std::string> num_denom, std::map<std::string, Racional*> &undefined_rac_objects, int &number){
    for (std::string element: num_denom){
        int num, denom;
        std::replace(element.begin(), element.end(), '/', ' ');
        std::stringstream ss(element);
        while(ss >> num && ss >> denom){
            std::ostringstream name;
            name << "Racional_obj" << number;
            undefined_rac_objects[name.str()] = new Racional(num, denom); 
            number++;
        }
    }
}

std::map<std::string, Racional*> ParseRacionalesText(){
    int count = GetTotalLines();
    int number{1};
    std::ifstream input_file_stream("rac.txt");
    std::map<std::string, Racional*> undefined_rac_objects;
    for(int i = 1; i < count + 1; i++){
        std::string line;
        std::getline(input_file_stream, line);
        std::istringstream line_stream(line);
        std::string rac1, rac2;
        std::getline(line_stream, rac1, ' ');
        std::getline(line_stream, rac2, ' ');

        std::vector<std::string> num_denom;
        num_denom.emplace_back(rac1);
        num_denom.emplace_back(rac2);
        Rac_map_objs(num_denom, undefined_rac_objects, number);
    }
    return undefined_rac_objects;
}

void Output_operats(std::string file_name, std::map<std::string, Racional*> rac_file_objs){
    std::ofstream myfile(file_name);
    for(std::map<std::string, Racional*>::iterator itr = rac_file_objs.begin(); itr != rac_file_objs.end(); itr++){
        std::cout << itr->first << std::endl;
        std::map<std::string, Racional*>::iterator paired_itr = rac_file_objs.find(itr->first);
        paired_itr++;
        std::cout << paired_itr->first << std::endl;
        double rac1_num = rac_file_objs[itr->first]->getNum();
        double rac1_denom = rac_file_objs[itr->first]->getDenom();
        double rac2_num = rac_file_objs[paired_itr->first]->getNum();
        double rac2_denom = rac_file_objs[paired_itr->first]->getDenom();
        myfile << rac1_num << "/" << rac1_denom << " + " << rac2_num << "/" << rac2_denom << " = " << rac_file_objs[itr->first]->operator+(*rac_file_objs[paired_itr->first]) << std::endl;
        myfile << rac1_num << "/" << rac1_denom << " - " << rac2_num << "/" << rac2_denom << " = " << rac_file_objs[itr->first]->operator-(*rac_file_objs[paired_itr->first]) << std::endl;
        myfile << rac1_num << "/" << rac1_denom << " * " << rac2_num << "/" << rac2_denom << " = " << rac_file_objs[itr->first]->operator*(*rac_file_objs[paired_itr->first]) << std::endl;
        myfile << rac1_num << "/" << rac1_denom << " / " << rac2_num << "/" << rac2_denom << " = " << rac_file_objs[itr->first]->operator/(*rac_file_objs[paired_itr->first]) << std::endl;
        itr++;
    }
}