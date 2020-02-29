#pragma once
#include <iostream>
#include <string>
#include <vector>

template <typename T>
class missing
{};

/* struct A;
struct B;
struct C; */


class Baza
{
public:

    virtual ~Baza() = default;

};

template <typename T>
class box : public Baza
{
public:

    box(T val = 0) : value(val) {}
    T value;

};




class ClonesF
{
public:

    ClonesF() {}
    ~ClonesF() { }//delete [] kont; }

    template<typename T>
    T add(const T& obj)
    {

        Baza *val = new box<T>(obj);
        tab.push_back(val);

        return obj;
    }

    template<typename T>
    T clone() const
    {
        for(unsigned int i=0; i<tab.size(); i++)
        {
            box<T>* val = dynamic_cast<box<T>*>(tab[i]);
            
            if(val)
            {
                return val->value;
            }
        }

        
        
        throw missing<T>();
    }


private:

    std::vector<Baza*> tab;

};

