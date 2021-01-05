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
    if(argc == 2 && strcmp(argv[1], "--Gestion_de_fechas") == 0){
        std::cout << "Modo de uso: ./fechas dd/mm/aa N fichero_salida.txt/n"
                     "Pruebe ./fechas - Gestion de fechas para más información;" << std::endl;
        exit(EXIT_SUCCESS);
    }
    if(argc != 4){
        std::cout << "Error en el numero de argumentos, pruebe - Gestion de fechas para mayor informacion\n";
        exit(EXIT_SUCCESS);
    }
}

void InputDateVerifier(const int day, const int month, const int year, std::map <int, int> &months_map){
    if(months_map[month] < day) {
        std::cout << "ERROR - Days input OUT_OF_RANGE - Exiting program" << std::endl;
        exit(EXIT_SUCCESS);
    }
    if(month > 12){
        std::cout << "ERROR - Month input OUT_OF_RANGE - Exiting program" << std::endl;
        exit(EXIT_SUCCESS);
    }
}

void NextDays(int N, int day, int month, int year, const std::string kFile_name){
    std::map<int, int> months_map = {
        {1, 31},
        {3, 31},
        {4, 30},
        {5, 31},
        {6, 30},
        {7, 31},
        {8, 31},
        {9, 30},
        {10, 31},
        {11, 30},
        {12, 31},
    };
    InputDateVerifier(day, month, year, months_map);  //Esto no deberia meterlo aqui porque la funcion NextDays no tiene nada que ver con verificar los inputs y tendria doble funcionalidad.
    std::ofstream output_file(kFile_name);
    for(int i = 0; i < N; i++){
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