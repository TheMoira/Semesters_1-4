#pragma once
#include "Source.h"

class OdtwarzaczDVD : public Source
{
    public:

    OdtwarzaczDVD(char a) : Source(a,"DVD"){}

    ~OdtwarzaczDVD(){}

    std::string retN() const {return nazwa;}

};