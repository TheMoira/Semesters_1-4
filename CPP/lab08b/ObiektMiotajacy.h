#pragma once
#include "ExceptType.h"
#include <iostream>


class ObiektMiotajacy
{
public:

    ObiektMiotajacy(ExceptType * e = new ExceptType2()) : exp(e) {}
    ~ObiektMiotajacy() 
    { 
        std::cout<<"**destruktor OM\n";
        delete exp; }

    void Rzuc() const
    {
        switch(exp->getType())
        {
            case 1:
                throw dynamic_cast<ExceptType1*> (exp);
            case 2:
                throw dynamic_cast<ExceptType2*> (exp);
        }
        std::cout<<"***throwing in Rzuc()\n";
    }

private:

    ExceptType * exp;
    
};