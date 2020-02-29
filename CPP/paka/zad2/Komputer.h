#pragma once
#include "Source.h"

class Komputer : public Source
{
    public: 

    Komputer(char a) : Source(a,"Komputer"){}

    ~Komputer(){}

    std::string retN() const {return nazwa;}

};