#pragma once
#include "Operations.h"
#include <iostream>


class Primitive : public Operations
{
public:

    Primitive(double a) : val(a) {}

    ~Primitive() {}

    void Set(double b) { val = b; }

    double retV() const { return val; }

    void PrintWithValue() { std::cout<<val; }

private:
    double val;
};