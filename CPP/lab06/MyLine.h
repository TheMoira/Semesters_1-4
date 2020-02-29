#pragma once
#include <string>
#include "AttColor.h"
#include "StringConvertable.h"


class MyLine : public StringConvertable, public AttColor
{
    public:

    MyLine(const char znak, int x, Option opC)
    : AttColor(opC), m_znak(znak), m_liczba(x) {}

    ~MyLine() {}

    std::string rawString() const { return std::string(m_liczba,m_znak); }


    void setColor(Option c) { Copt = c; }
    void setChar(char str) { m_znak = str; }
    void setLength(int l) { m_liczba = l; }


private:

    char m_znak;
    int m_liczba;
};
