#pragma once
#include "Ekran.h"
#include "util.h"

class Rzutnik : public Ekran
{

public:

    Rzutnik(int s, int w) : szer(s), wys(w){}

    ~Rzutnik(){};

    void Wyswietl(Source* s) const;

private:

    int szer;
    int wys;

};