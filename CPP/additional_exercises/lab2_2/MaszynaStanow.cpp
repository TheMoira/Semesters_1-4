#include "MaszynaStanow.h"

MaszynaStanow::MaszynaStanow()
{
    size = 0;
    wsk = 0;
    on = false;
}

MaszynaStanow::~MaszynaStanow()
{
    delete [] tabS;
}

MaszynaStanow& MaszynaStanow::operator+=(Stan* s)
{
    if(!size)
    {
        size++;
        tabS = new Stan[1];
        tabS[0] = *s;
    }
    else
    {
        Stan *temp = new Stan[size];

        for(int i=0;i<size;i++)
        {
            temp[i] = tabS[i];
        }

        size++;

        tabS = new Stan[size];
        for(int i=0;i<size-1;i++)
        {
            tabS[i] = temp[i];
        }

        tabS[size-1] = *s;

        delete [] temp;
    }

    return *this;
}

void MaszynaStanow::operator++()
{
    wsk++;
}

void MaszynaStanow::operator--()
{
    wsk--;
}

void MaszynaStanow::start()
{
    on = true;
}

MaszynaStanow& MaszynaStanow::operator()()
{
    if(on && wsk<size && wsk>=0)
    {
    std::cout<<"Wykonanie w stanie: "<<tabS[wsk]<<std::endl;
    }

    return *this;
}

std::ostream& operator<<(std::ostream& i, const MaszynaStanow& m)
{
    if(m.on)
    {
        std::cout<<"Maszyna stanow:\n";
        for(int j = 0; j<m.retsize(); j++)
        {
            i<<j<<" "<<m.tabS[j];
        
            if(j == m.retW())
            {
                i<<" <";
            }

            std::cout<<"\n";
        }
    }

    return i<<std::endl;
}
