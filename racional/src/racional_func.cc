#include <iostream>
#include <exception>
#include <cmath>
#include <limits>
#include "racional_func.h"

Racional::Racional(double arg1, double arg2) : num_(arg1), denom_(arg2){}
double Racional::getNum(){ return num_; }
double Racional::getDenom(){ return denom_; }
Racional Racional::operator+(const Racional &rac){
    num_ = rac.denom_ * num_ + denom_ * rac.num_;
    denom_ = denom_ * rac.denom_;
    reduceFraction(num_, denom_);
    return Racional(num_, denom_);
}
Racional Racional::operator-(const Racional &rac){
    num_ = rac.denom_ * num_ - denom_ * rac.num_;
    denom_ = denom_ * rac.denom_;
    reduceFraction(num_, denom_);
    return Racional(num_, denom_);
}
Racional Racional::operator*(const Racional &rac){
    num_ = num_ * rac.num_;
    denom_ = denom_ * rac.denom_;
    reduceFraction(num_, denom_);
    return Racional(num_, denom_);
}
Racional Racional::operator/(const Racional &rac){
    if((denom_ || rac.denom_) == 0) throw std::runtime_error("Math error in class Complejo2, method 'operator/' operation - Attempted to divide by 0");
    num_ = num_ * rac.denom_;
    denom_ = rac.num_ * denom_;
    reduceFraction(num_, denom_);
    return Racional(num_, denom_);
}
void Racional::reduceFraction (double &num_, double &denom_){
    while(fmod(num_, 10) == 0 && fmod(denom_, 10) == 0){
        num_ /= 10;
        denom_ /= 10;
    }
    for (double i = denom_ * num_; i > 1; i--) {
        if ((fmod(denom_, i) == 0) && (fmod(num_, i) == 0)){ 
            //std::cout << "fmod(" << num_ << "," << i << ") == 0)" << " == " << "(fmod(" << denom_ << "," << i << ") == 0  ->  num_ = " << num_ / i << " | " << "denom_ = " << denom_ / i << std::endl; 
            num_ /= i;  
            denom_ /= i;  
        } //else std::cout << "fmod(" << num_ << "," << i << ") == 0)" << " != " << "(fmod(" << denom_ << "," << i << ") == 0" << std::endl;
    }
}
bool operator==(const Racional &obj1, const Racional &obj2){ return (obj1.num_ == obj2.num_) && (obj1.denom_ == obj2.denom_); }
std::istream& operator>>(std::istream &stream_in, Racional &obj){
    std::cout << "Numerador: ";
    while(!(stream_in >> obj.num_)){
		stream_in.clear();
		stream_in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input.  Try again: ";
	}
    std::cout << "Denominador: ";
    while(!(stream_in >> obj.denom_)){
		stream_in.clear();
		stream_in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input.  Try again: ";
	}
    return stream_in;
}
std::ostream& operator<<(std::ostream &stream_out, const Racional &obj){ return stream_out << obj.num_ << "/" << obj.denom_; };
