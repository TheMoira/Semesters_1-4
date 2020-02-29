#include "Ratio.h"
#include <iostream>


Ratio::Ratio(Operations& a, Operations& b)
{
    uno = &a;
    dos = &b;

    val = uno->retV() / dos->retV();
}


void Ratio::PrintWithValue() 
{
    val = uno->retV() / dos->retV();
    std::cout<<"(";
    uno->PrintWithValue();
    std::cout<<"/";
    dos->PrintWithValue();
    std::cout<<") = "<<val<<std::endl;
}