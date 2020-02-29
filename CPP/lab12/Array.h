#pragma once
#include <iostream>

//Maria Korkuc
//Mariusz Niwinski


class Array
{
public:

    Array(int a)
    {
        m_size = a;
        tab = new int[m_size];
    }

    ~Array()
    {
        //std::cout<<"delete\n";
        delete [] tab;
    }

    int size() const
    {
        return m_size;
    }

    //przeladowanie operatora [] zwracajacego referencje do odpowiedniego elementu tablicy
    int& operator[](int index)
    {
        return tab[index];
    }



private:

    int *tab;
    int m_size;



};

/* int sizeof(const Array& a)
{
    return a.size() * sizeof(Array);
} */