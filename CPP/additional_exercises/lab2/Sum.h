#pragma once
#include "Operations.h"


class Sum : public Operations
{
public:
/* 
    Sum(Primitive& a, Primitive& b) : uno(a), dos(b) {}
 */
    Sum(Operations& a, Operations& b);

    ~Sum() {}

    void PrintWithValue();

    double retV() const { return val; }


protected:

    Operations * uno;
    Operations * dos;
    double val;

};