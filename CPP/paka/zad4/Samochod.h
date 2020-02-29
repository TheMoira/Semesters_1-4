#pragma once
#include "Pojazd.h"
#include <iostream>


class Samochod : public Pojazd
{
friend std::ostream& operator<<(std::ostream& i, const Samochod& s);

public:

    Samochod(Silnik s, std::string kolor, double l) : 
    Pojazd(s,kolor,l){}

    ~Samochod() {}

};

std::ostream& operator<<(std::ostream& i, const Samochod& s)
{
    return i<<"Liczba kol 4\nStan licznika "<<
    s.m_licznik<<" [km]\nKolor "<<s.m_kolor<<std::endl;
}

