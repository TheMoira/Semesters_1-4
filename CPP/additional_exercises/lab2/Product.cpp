#include "Product.h"
#include <iostream>


Product::Product(Operations& a, Operations& b)
{
    uno = &a;
    dos = &b;

    val = uno->retV() * dos->retV();
}


void Product::PrintWithValue() 
{
    val = uno->retV() * dos->retV();
    std::cout<<"(";
    uno->PrintWithValue();
    std::cout<<"*";
    dos->PrintWithValue();
    std::cout<<") = "<<val<<std::endl;
}