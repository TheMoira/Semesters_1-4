#include "Sum.h"
#include <iostream>


Sum::Sum(Operations& a, Operations& b)
{
    uno = &a;
    dos = &b;

    val = uno->retV() + dos->retV();
}


void Sum::PrintWithValue()
{
    val = uno->retV() + dos->retV();
    std::cout<<"(";
    uno->PrintWithValue();
    std::cout<<"+";
    dos->PrintWithValue();
    std::cout<<") = "<<val<<std::endl;
}