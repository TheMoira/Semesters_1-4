#pragma once
#include "MalenstwoSamoSprzatacz.h"
#include <cstdlib>

class Malenstwo
{
    friend class MalenstwoSamoSprzatacz;
public:

    Malenstwo(int val = 0); 

    ~Malenstwo() {}

    static void* operator new(long unsigned int);

    static void* operator new[](long unsigned int);

    static void operator delete(void *, long unsigned int);

    static void operator delete[](void *, long unsigned int);

    Malenstwo* operator+(int);

    int& wartosc() { return value; }


private:

    int value;




};