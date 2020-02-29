#pragma once
#include <iostream>

template <typename T>
class Iter
{
public:



    Iter(T* value)
    {
        val = value;
    }

    Iter operator++()
    {
        val++;
        return *this;
    }

    T operator*()
    {
        return *val;
    }

    /* void append(T v)
    {
        *val += v;
    } */

    bool operator!=(T* value) const
    {
        return *val != *value;
        std::cout<<"jest\n";
    }

    T* operator->()
    {
        return val;
    }



private:

    T* val;

};




template <typename T>
class DynArray
{
public:

    DynArray(int val)
    {
         m_size = val;
        tab = new T[m_size];
    }

    DynArray(const DynArray <T>& arr)
    {
        m_size = arr.size();
        tab = new T[m_size];

        for(int i=0; i<m_size; i++)
        {
            tab[i] = arr[i];
        }
    }

    DynArray(int val, const T* arr)
    {
        m_size = val;
        tab = new T[m_size];

        for(int i=0; i<m_size;i++)
        {
            tab[i] = arr[i];
        }
    }

    ~DynArray()
    {
        if(m_size)
        {
            delete [] tab;
        }
    }

    int size() const
    {

        return m_size;
    }

    T& operator[](int index)
    {
        return tab[index];
    }

    T operator[](int index) const
    {
        return tab[index];
    }

    T* begin() {return tab;}
    T* end() { return tab+m_size;}

    typedef Iter<T> Iterator;

private:

    T *tab;
    int m_size;

};




std::ostream& operator<<(std::ostream& out, DynArray <int>& arr)
{
    std::cout<<"{";
    for(int i=0; i<arr.size(); i++)
    {
        std::cout<<"\""<<arr[i]<<"\",";
    }
    return out<<"}"<<std::endl;
}


std::ostream& operator<<(std::ostream& out, DynArray <std::string>& arr)
{
    std::cout<<"{";
    for(int i=0; i<arr.size(); i++)
    {
        std::cout<<"\""<<arr[i]<<"\",";
    }
    return out<<"}"<<std::endl;
}


/* template <typename T>
DynArray::DynArray(int val)
{
    m_size = val;
    tab = new T[m_size];
} */

/* 
template <typename T>
DynArray::DynArray(const DynArray <T>& arr)
{
    m_size = arr.size();
    tab = new T[m_size];

    for(int i=0; i<m_size; i++)
    {
        tab[i] = arr[i];
    }
}

template <typename T>
DynArray::DynArray(int val, T* arr)
{
    m_size = val;
    tab = new T[size];

    for(int i=0; i<m_size;i++)
    {
        tab[i] = arr[i];
    }
}

template <typename T>
DynArray::~DynArray()
{
    if(m_size)
    {
        delete [] tab;
    }
}

template <typename T>
int DynArray::size() const
{
    return m_size;
}

template <typename T>
T& DynArray::operator[](int index)
{
    return tab[index];
}

template <typename T>
T* DynArray::begin()
{
    return tab;
}

template <typename T>
T* DynArray::end()
{
    return tab + m_size;
} */