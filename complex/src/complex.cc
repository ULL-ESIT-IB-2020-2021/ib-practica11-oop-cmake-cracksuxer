#include <iostream>
#include <math.h>
#include <map>
#include <limits>
#include "complex.h"

Complex::Complex(double real, double img) : real_(real), imag_(img){}             
Complex Complex::operator+(const Complex &obj) const { return Complex (real_ + obj.real_, imag_ + obj.imag_); }
Complex Complex::operator-(const Complex &obj) const { return Complex (real_ - obj.real_, imag_ - obj.imag_); }
Complex Complex::operator*(const Complex &obj) const { return Complex ((real_ * obj.real_ + -1 * (imag_ * obj.imag_)), (real_ * obj.imag_, imag_ * obj.real_ + real_ * obj.imag_)); }                                               
Complex Complex::operator/(const Complex &obj){
    Complex conjugate_comp(obj.real_, -1 * obj.imag_); 
    double denom_real_part = pow(obj.real_, 2) + pow(obj.imag_, 2);
    double denom_imag_part = pow(obj.real_, 2) + pow(obj.imag_, 2);
    if((denom_real_part || denom_imag_part) == 0) throw std::runtime_error("Math error in class Complejo2, method 'operator/' operation - Attempted to divide by 0");
    double real_part = real_ * conjugate_comp.real_ + -1 * (imag_ * conjugate_comp.imag_);
    double imag_part = imag_ * conjugate_comp.real_ + real_ * conjugate_comp.imag_;
    reduceFraction(real_part, denom_real_part);
    reduceFraction(imag_part, denom_imag_part);
    std::cout << real_part << "/" << denom_real_part << " + " << imag_part << "/" << denom_imag_part << "i" << " ~= "; 
    return Complex (real_part / denom_real_part, imag_part / denom_imag_part);
}
void Complex::reduceFraction (double &num_, double &denom_){
    std::map<int, std::string> number_sign;
    if(num_ < 0){ 
        number_sign[num_] = "Negative";
        num_ *= -1;
    } else {
        if(denom_ < 0){ 
            number_sign[denom_] = "Negative";
            denom_ *= -1;
        }
    }
    for (double i = denom_ * num_; i > 1; i--) {                 //Poco eficiente
        if ((fmod(denom_, i) == 0) && (fmod(num_, i) == 0)) {  
            num_ /= i;  
            denom_ /= i;  
        }        
    }
    while(fmod(num_, 10) == 0 && fmod(denom_, 10) == 0){
        num_ /= 10;
        denom_ /= 10;
    }
    if(number_sign[num_] == "Negative" || number_sign[denom_] == "Negative") num_*= -1;
}
bool operator==(const Complex &obj1, const Complex &obj2){ return (obj1.real_ == obj2.real_) && (obj1.imag_ == obj2.imag_);}
std::ostream& operator<<(std::ostream &stream_out, const Complex &obj){ return obj.imag_ < 0 ? stream_out << obj.real_ << obj.imag_ << "i" : stream_out << obj.real_ << " + " << obj.imag_ << "i"; }
std::istream& operator>>(std::istream &stream_in, Complex &obj){
    std::cout << "Real part: ";
    while(!(stream_in >> obj.real_)){
		stream_in.clear();
		stream_in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input.  Try again: ";
	}
    std::cout << "Imaginary part: ";
    while(!(stream_in >> obj.imag_)){
		stream_in.clear();
		stream_in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input.  Try again: ";
	}
    return stream_in;
}
