#ifndef _FECHA_
#define _FECHA_

class Date{
private:
    int day_, month_, year_;
public:
    Date(int arg1, int arg2, int arg3);
    void setDay(int input);
    void setMonth(int input);
    void setYear(int input);
    void printYear();
    void isBisiesto();
};


#endif
