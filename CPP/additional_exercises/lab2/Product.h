#pragma once
#include "Operations.h"


class Product : public Operations
{
public:
/* 
    Product(Primitive& a, Primitive& b) : uno(a), dos(b) {}
 */
    Product(Operations& a, Operations& b);

    ~Product() {}

    void PrintWithValue();

    double retV() const { return val; }


protected:

    Operations *uno;
    Operations *dos;
    double val;

};