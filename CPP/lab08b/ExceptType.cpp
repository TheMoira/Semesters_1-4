#include "ExceptType.h"
#include <iostream>

ExceptType2::ExceptType2() : ExceptType(2), exp(new ExceptType4())
{
    std::cout<<"***konstruktor ExceptType2\n";
}

void ExceptType1::PrzedstawSie() const
{
    std::cout<<"Nazywam sie Except1\n";
}

void ExceptType2::PrzedstawSie() const
{
    std::cout<<"Nazywam sie Except2\n";
}

void ExceptType3::PrzedstawSie() const
{
    std::cout<<"Nazywam sie Except3\n";
}

void ExceptType4::PrzedstawSie() const
{
    std::cout<<"Nazywam sie Except4\n";
}

void HandleExcept(ExceptType * exp)
{
    std::cout<<"przetworz wyjatek ";
    switch(exp->getType())
    {
        case 1:
            std::cout<<" Except1 o adresie: "<<exp;
        case 2:
             std::cout<<" Except2 o adresie: "<<exp;
        default:
            std::cout<<" inny: ";
    }

    throw exp->getExp();
}