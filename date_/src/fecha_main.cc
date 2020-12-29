#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>
#include "fecha.h"
#include "tools.h"

int main(int argc, char *argv[]){
    InputHandler(argc, argv);
    std::string date = argv[1];
    const int kNumer_of_days = atoi(argv[2]);
    std::string file_name = argv[3];
    std::vector<int> date_vec = ParseString(date);
    NextDays(kNumer_of_days, date_vec[0], date_vec[1], date_vec[2], file_name);
}