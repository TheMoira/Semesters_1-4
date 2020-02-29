#pragma once
#include "Pojazd.h"
#include <iostream>


class Motorower : public Pojazd
{
friend std::ostream& operator<<(std::ostream& i, const Motorower& m);

public:

    Motorower(Silnik s, std::string kolor, double l) : 
    Pojazd(s,kolor,l){}

    ~Motorower() {}

};

std::ostream& operator<<(std::ostream& i, const Motorower& m)
{
    return i<<"Liczba kol 2\nStan licznika "<<m.m_licznik<<
    " [km]\nKolor "<<m.m_kolor<<std::endl;
}