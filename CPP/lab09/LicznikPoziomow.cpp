#include "LicznikPoziomow.h"

int LicznikPoziomow::licznik = 0;

LicznikPoziomow::LicznikPoziomow()
{
    licznik++;
    std::cout<<"Rozpoczynamy poziom numer "<<licznik<<std::endl;
}

LicznikPoziomow::~LicznikPoziomow()
{
    std::cout<<"Konczymy poziom numer "<<licznik<<std::endl;
    licznik--;
}