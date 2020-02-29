#pragma once
#include "Samochod.h"


class Mercedes : public Samochod
{
friend std::ostream& operator<<(std::ostream& i, const Mercedes& mer);

public:

    Mercedes(Silnik s = Silnik(0,0.0,"X"), double licz = 0.0) : 
    Samochod(s,"Czarny metaliczny",licz), przebieg(licz) {}

    Mercedes(const Mercedes& m) : 
    Samochod(m.retS(), "Czarny metaliczny", m.retP()), przebieg(m.retP()) {}

    ~Mercedes() {}

    void Przebieg(double p) { przebieg = p; }
    double retP() const { return przebieg; }

protected:

    double przebieg;
};

std::ostream& operator<<(std::ostream& i, const Mercedes& mer)
{
    return i<<"Liczba kol 4\nStan licznika "<<
    mer.przebieg<<" [km]\nKolor "<<mer.retK()<<std::endl;   
}

