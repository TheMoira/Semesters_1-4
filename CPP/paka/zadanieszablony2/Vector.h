#pragma once
#include "TestObject.h"

class Vector
{
public:

    template <typename T> static void Initialise(int size)
    {
        m_size = size;
        tab = new T[size];
    }

    template <typename T1, typename T2> static void Initialise(T1 size, T2 obj)
    {
        m_size = size;
        tab = new T2[m_size];

        for(int i=0; i<m_size; i++)
        {
            (static_cast<T2*>(tab))[i] = obj;
        }
    }

    template <typename T> static T& At(int index)
    {
        return (static_cast<T*>(tab))[index];
    }

    template <typename T> static void Reset()
    {
        if(m_size)
        {
            m_size = 0;
            delete static_cast<T*>(tab);
        }
        
    }
    
    static int Size() { return m_size; }


private:
    static int m_size;
    static void* tab;
};

int Vector::m_size = 0;
void* Vector::tab = nullptr;