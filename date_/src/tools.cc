#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>
#include "tools.h"


void InputHandler(int argc, char *argv[]){
    if(argc == 2 && strcmp(argv[1], "- Gestion de fechas") == 0){
        std::cout << "Modo de uso: ./fechas dd/mm/aa N fichero_salida.txt/n"
                     "Pruebe ./fechas --help para más información;" << std::endl;
        exit(EXIT_SUCCESS);
    }
    if(argc != 4){
        std::cout << "Error en el numero de argumentos, pruebe --help para mayor informacion\n";
        exit(EXIT_SUCCESS);
    }
}
void NextDays(int N, int day, int month, int year, std::string file_name){
    std::map<int, int> months_map;  //Puedo utilizar multimap y tener menos lineas, pero se complicaria porque no tiene ningun operador para []
    months_map[1] = 31;
    months_map[3] = 31;
    months_map[4] = 30;
    months_map[5] = 31;
    months_map[6] = 30;
    months_map[7] = 31;
    months_map[8] = 31;
    months_map[9] = 30;
    months_map[10] = 31;
    months_map[11] = 30;
    months_map[12] = 31;
    std::ofstream output_file(file_name);
    for(int i = 0; i <= N; i++){
        day++;
        year % 4 == 0 ? months_map[2] = 29 : months_map[2] = 28; 
        if(months_map[month] < day){
            day = 1;
            month++;
        }
        if(month > 12){
            month = 1;
            year++;
        }
        output_file << day << "/" << month << "/" << year << std::endl;
    }
}
std::vector<int> ParseString(std::string date){
    std::vector <int> parsed_date;
    std::replace(date.begin(), date.end(), '/', ' ');
    std::stringstream ss(date);
    int day, month, year;
    while(ss >> day && ss >> month && ss >> year){
        std::cout << "Day: " << day << std::endl;
        std::cout << "Month: " << month << std::endl;
        std::cout << "Year: " << year << std::endl;
        parsed_date.emplace_back(day);
        parsed_date.emplace_back(month);
        parsed_date.emplace_back(year);
    }
    return parsed_date;
}