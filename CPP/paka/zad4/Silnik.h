#pragma once
#include <string>


class Silnik
{
public:

    Silnik(int moc, double pojemnosc, std::string paliwo) :
    m_moc(moc), m_paliwo(paliwo), m_pojemnosc(pojemnosc) {}

    ~Silnik() {}

protected:

    int m_moc;
    double m_pojemnosc;
    std::string m_paliwo;
    
};