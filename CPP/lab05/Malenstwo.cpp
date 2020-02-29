#include "Malenstwo.h"
#include <iostream>

//int Malenstwo::count = 0;

Malenstwo(int val)
{
    value = val;
    std::cout<<"Konstrukcja Malenstwa: wart = "<<value<<std::endl;
    MalenstwoMem::add(*this);
}


void* Malenstwo::operator new(unsigned int size)
{
    std::cout<<"Alokuje jeden obiekt: 1 ("<<size<<" bajtow)"<<std::endl;

    return new Malenstwo;
}

void* Malenstwo::operator new[](unsigned int size)
{
    
}

void Malenstwo::operator delete(void * ptr, unsigned int size)
{

}

void Malenstwo::operator delete[](void *, long unsigned int)
{

}

Malenstwo* Malenstwo::operator+(int x)
{

}