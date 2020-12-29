#ifndef _RACIONAL_
#define _RACIONAL_

#include <istream>

class Racional{
private:
    int num_, denom_;
public:
    Racional(int arg1 = 0, int arg2 = 0);
    int getNum();
    int getDenom();
    friend bool operator==(const Racional &obj1, const Racional &rac);
    friend std::istream& operator>>(std::istream &stream_in, Racional &rac);
    friend std::ostream& operator<<(std::ostream &stream_out, const Racional &rac);
    Racional operator+(const Racional &rac) const;
    Racional operator-(const Racional &rac) const;
    Racional operator*(const Racional &rac) const;                                             
    Racional operator/(const Racional &rac) const;
};


#endif