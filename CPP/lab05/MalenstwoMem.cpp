#include "MalenstwoMem.h"

void add(Malenstwo m)
{
     if(!count)
    {
        std::cout<<"Pierwszy obiekt na stercie - prealokuje skladowisko na 100 elementow"<<std::endl;
    }

    tab[count] = m;
    count++;
}

Malenstwo& MalenstwoMem::retM(Malenstwo m)
{
    for(int i=0; i<count; i++)
    {
        if(m.wartosc() == tab[i].wartosc())
        {
            return tab[i+1];
        }
    }
}