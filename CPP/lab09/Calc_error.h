#pragma once
#include <stdexcept>
#include <iostream>
#include <string>


class Calc_error : std::runtime_error
{
public:
    Calc_error(std::runtime_error* p, std::string name, std::string f, int l) : std::runtime_error(name)
    {
        std::cout<<"\nCreating "<<name<<std::endl;
    file = f;
    line = l;
    arg_name = name;

    prev = dynamic_cast<Calc_error*> (p);
    }

    virtual ~Calc_error();

    static void handler();

    virtual std::string what();

private:

    std::string file;
    int line;
    Calc_error * prev;
    std::string arg_name;

};