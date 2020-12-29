#ifndef _FECHA_
#define _FECHA_

class Date{
private:
    int day_, month_, year_;
public:
    Date(int arg1 = 0, int arg2 = 0, int arg3 = 0);
    void setDay(int input);
    void setMonth(int input);
    void setYear(int input);
    void printYear();
    void isBisiesto();
};


#endif
