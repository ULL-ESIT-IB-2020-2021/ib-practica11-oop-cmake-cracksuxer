#ifndef _RACIONAL_
#define _RACIONAL_

#include <istream>

class Racional{
private:
    double num_, denom_;
public:
    Racional(double arg1 = 0, double arg2 = 0);
    double getNum();
    double getDenom();
    friend bool operator==(const Racional &obj1, const Racional &rac);
    friend std::istream& operator>>(std::istream &stream_in, Racional &rac);
    friend std::ostream& operator<<(std::ostream &stream_out, const Racional &rac);
    Racional operator+(const Racional &rac) const;
    Racional operator-(const Racional &rac) const;
    Racional operator*(const Racional &rac) const;                                             
    Racional operator/(const Racional &rac) const;
};


#endif