#pragma once
#include "Motorower.h"


class Romet : public Motorower
{
friend std::ostream& operator<<(std::ostream& i, const Romet& r);

public:

    Romet(Silnik s, double licz) : 
    Motorower(s,"Czerwony metaliczny",licz), przebieg(licz) {}

    
    Romet(const Romet& m) : 
    Motorower(m.retS(), "Czerwony metaliczny", m.retP()), przebieg(m.retP()) {}

    double retP() const { return przebieg; }


    ~Romet() {}

protected:
    double przebieg;

};

std::ostream& operator<<(std::ostream& i, const Romet& r)
{
    return i<<"Liczba kol 2\nStan licznika "<<
    r.przebieg<<" [km]\nKolor "<<r.retK()<<std::endl;
}


