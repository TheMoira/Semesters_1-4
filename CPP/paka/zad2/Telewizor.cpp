#include "Telewizor.h"
#include <iostream>

/* void TelewizorLCD::Wyswietl(Source *s) const
{
    std::cout<<"Polaczono "<<s->nazwa<<" i telewizor\n";
    
    kreski('-','-',szer);

    for(int i = 0; i<wys; i++)
    {
        kreski(s->val,s->val,szer);
    }

    kreski('-',' ',szer);

    std::cout<<"\n";
} */

void TelewizorLCD::Wyswietl(Source *s) const
{
    std::cout<<"Polaczono "<<s->nazwa<<" i telewizor\n";
    
        for(int i = 0; i<szer/2; i++)
    {
        std::cout<<'-'<<'-';
    }

    std::cout<<"\n";

    for(int i = 0; i<wys; i++)
    {
            for(int i = 0; i<szer/2; i++)
    {
        std::cout<<s->val<<s->val;
    }

    std::cout<<"\n";
    }

        for(int i = 0; i<szer/2; i++)
    {
        std::cout<<'-'<<' ';
    }

    std::cout<<"\n";

    std::cout<<"\n";
}