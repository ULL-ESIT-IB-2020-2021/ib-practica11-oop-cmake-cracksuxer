#include <iostream>
#include <exception>
#include <cmath>
#include <limits>
#include <string>
#include <map>
#include <fstream>
#include <cstring>
#include "racional.h"

Racional::Racional(int arg1, int arg2) : num_(arg1), denom_(arg2) {}
int Racional::getNum() { return num_; }
int Racional::getDenom() { return denom_; }
Racional Racional::operator+(const Racional &rac) const {
    int num = rac.denom_ * num_ + denom_ * rac.num_;
    int denom = denom_ * rac.denom_;
    return Racional(num, denom);
}
Racional Racional::operator-(const Racional &rac) const {
    int num = rac.denom_ * num_ - denom_ * rac.num_;
    int denom = denom_ * rac.denom_;
    return Racional(num, denom);
}
Racional Racional::operator*(const Racional &rac) const {
    int num = num_ * rac.num_;
    int denom = denom_ * rac.denom_;
    return Racional(num, denom);
}
Racional Racional::operator/(const Racional &rac) const {
    if (denom_ == 0 || rac.denom_ == 0)
        throw std::runtime_error("Math error in class Complejo2, method 'operator/' operation - Attempted to divide by 0");
    int num = num_ * rac.denom_;
    int denom = denom_ * rac.num_;
    return Racional(num, denom);
}
bool operator==(const Racional &obj1, const Racional &obj2) { return (obj1.num_ == obj2.num_) && (obj1.denom_ == obj2.denom_); }
std::istream &operator>>(std::istream &stream_in, Racional &obj) {
    std::cout << "Numerador: ";
    while (!(stream_in >> obj.num_)) {
        stream_in.clear();
        stream_in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input.  Try again: ";
    }
    std::cout << "Denominador: ";
    while (!(stream_in >> obj.denom_)) {
        stream_in.clear();
        stream_in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input.  Try again: ";
    }
    return stream_in;
}
std::ostream &operator<<(std::ostream &stream_out, const Racional &obj) {
    int rac1_num = obj.num_;
    int rac1_denom = obj.denom_;
    std::map<std::string, int> test;
    rac1_num > rac1_denom ? test["Greater"] = rac1_num : test["Greater"] = rac1_denom;
    while ((rac1_num % 10 == 0) && (rac1_denom % 10) == 0) {
        rac1_num /= 10;
        rac1_denom /= 10;
    }
    for (int i = test["Greater"]; i > 1; i--) {
        if ((rac1_num % i == 0) && (rac1_denom % i) == 0)
        {
            //std::cout << "fmod(" << rac1_num << "," << i << ") == 0)" << " == " << "(fmod(" << rac1_denom << "," << i << ") == 0  ->  num_ = " << rac1_num / i << " | " << "denom_ = " << rac1_denom / i << std::endl;  [Only debug]
            rac1_num /= i;
            rac1_denom /= i;
        } // else std::cout << "fmod(" << rac1_num << "," << i << ") == 0)" << " != " << "(fmod(" << rac1_denom << "," << i << ") == 0" << std::endl;  [Only Debug]
    }
    return stream_out << rac1_num << "/" << rac1_denom;
};

void Racional::meanNum(const Racional &rac){
    double mean_num = (num_ + rac.num_) / 2;
    std::cout << "Numerator  mean is: " << mean_num << std::endl;
}
void Racional::meanDenom(const Racional &rac){
    double mean_denom = (denom_ + rac.denom_) / 2;
    std::cout << "Denominator mean is: " << mean_denom << std::endl;
}

double Racional::fileRacsMean(){
    std::ifstream intput_file("rac.txt");
    std::string line;
    double media{0};

    int lines{0};
    while(getline(intput_file, line)){
        std::string rac1_file = line.substr(0, 3);
        std::string rac2_file = line.substr(4, 10);
        double rac1_num = std::atoi(&rac1_file[0]);
        double rac1_denom = std::atoi(&rac1_file[2]);
        double rac2_num = std::atoi(&rac2_file[0]);
        double rac2_denom = std::atoi(&rac2_file[2]);
        std::cout << media << " += " << rac1_num << "/" << rac1_denom << " + " << rac2_num << "/" << rac2_denom << std::endl;

        media += (rac1_num / rac1_denom) + (rac2_num / rac2_denom);
        std::cout << "Media: " << media << std::endl;
        lines++;
    }
    return media / lines;
}
