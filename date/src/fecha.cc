#include <iostream>
#include "fecha.h"

Date::Date(int arg1, int arg2, int arg3) 
    : day_{arg1}, month_{arg2}, year_{arg3} {}
void Date::setDay(int input) { day_ = input; }
void Date::setMonth(int input) { month_ = input; }
void Date::setYear(int input) { year_ = input; }
void Date::printYear() { std::cout << day_ << '/' << month_ << '/' << year_ << std::endl; }
void Date::isBisiesto() { !(year_ % 4) ? std::cout << "Es bisiesto\n" : std::cout << "No es bisiesto\n"; }