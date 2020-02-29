#pragma once
#include <string>

class Source
{
    public:

    Source(char v, std::string n) : val(v), nazwa(n) {}

    virtual std::string retN() const = 0;

    char val;
    std::string nazwa;

};