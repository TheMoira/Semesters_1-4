#pragma once
#include "Silnik.h"
#include "util.h"

class Pojazd
{
    friend class Silnik;

public:

    Pojazd(Silnik s, std::string kolor, double licznik) :
    m_s(s), m_kolor(kolor), m_licznik(licznik) {}

    ~Pojazd(){}

    std::string retK() const { return m_kolor; }
    Silnik retS() const {return m_s; }

protected:

    Silnik m_s;
    std::string m_kolor;
    double m_licznik;

};