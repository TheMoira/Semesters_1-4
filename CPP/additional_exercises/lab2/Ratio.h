#pragma once
#include "Operations.h"


class Ratio : public Operations
{
public:
/* 
    Ratio(Primitive& a, Primitive& b) : uno(a), dos(b) {}
 */
    Ratio(Operations& a, Operations& b);

    ~Ratio() {}

    void PrintWithValue();

    double retV() const { return val; }


protected:

    Operations *uno;
    Operations *dos;
    double val;

};