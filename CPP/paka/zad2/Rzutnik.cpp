#include "Rzutnik.h"
#include <iostream>
//#include "util.h"

/* 
void Rzutnik::Wyswietl(Source *s) const
{
    std::cout<<"Polaczono "<<s->nazwa<<" i rzutnik\n";
    
    kreski('_','_',szer);

    for(int i = 0; i<wys; i++)
    {
        kreski(s->val,s->val,szer);
    }

    kreski('_',' ',szer);

    std::cout<<"\n";
} */

void Rzutnik::Wyswietl(Source *s) const
{
    std::cout<<"Polaczono "<<s->nazwa<<" i rzutnik\n";
    
        for(int i = 0; i<szer/2; i++)
    {
        std::cout<<'_'<<'_';
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
        std::cout<<'_'<<' ';
    }

    std::cout<<"\n";

    std::cout<<"\n";
}