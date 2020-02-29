#pragma once
#include "Ekran.h"
#include "util.h"

class TelewizorLCD : public Ekran
{

public:

    TelewizorLCD(int s, int w) : szer(s), wys(w){}

    ~TelewizorLCD(){};

    void Wyswietl(Source* s) const;

private:

    int szer;
    int wys;

};