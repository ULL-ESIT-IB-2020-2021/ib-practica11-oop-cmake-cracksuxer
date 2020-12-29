#ifndef _COMPLEX_
#define _COMPLEX_

#include <iostream>
#include <map>

class Complex{
private:
    double real_, imag_;
public:                                        
    Complex(double real = 0, double img = 0);
    friend std::istream& operator>>(std::istream &stream_in, Complex &obj);
    friend std::ostream& operator<<(std::ostream &stream_out, const Complex &obj);
    friend bool operator==(const Complex &obj1, const Complex &obj2);
    Complex operator+(const Complex &obj) const;
    Complex operator-(const Complex &obj) const;
    Complex operator*(const Complex &obj) const;                                             
    Complex operator/(const Complex &obj);
    void reduceFraction (double &num_, double &denom_);
};

#endif