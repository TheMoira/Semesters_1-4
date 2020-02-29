#include "Calc_error.h"
#include <iostream>

/* Calc_error::Calc_error(std::runtime_error* p, std::string name, std::string f, int l) : std::runtime_error(name)
{
    std::cout<<"\nCreating "<<name<<std::endl;
    file = f;
    line = l;
    arg_name = name;

    prev = dynamic_cast<Calc_error*> (p);
} */

Calc_error::~Calc_error()
{
    std::cout<<"\nDestructor "<<arg_name<<std::endl;
    delete prev;
}

std::string Calc_error::what()
{
    std::cout<<"-- z powodu: ";
    std::cout<<arg_name<<"[plik = "<<file<<", linia = "<<line<<"]\n";
    prev->what();
    delete prev;
    prev = nullptr;
    return arg_name;
}



void Calc_error::handler()
{
    std::cout<<"Zlapano wyjatek:\n";
    
    try
    {
        throw;
    }
    catch(std::runtime_error* err)
    {
        std::cout<<"\nHandler: runtime_error\n";
        err->what();
        //delete err;
    }
    catch(Calc_error* err)
    {
        std::cout<<"\nHandler: calc_error\n";
        err->what();
        //delete err;
    }
    
}