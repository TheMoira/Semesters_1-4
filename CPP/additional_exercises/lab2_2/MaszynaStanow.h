#pragma once
#include <iostream>
#include "Stan.h"

class MaszynaStanow
{
    friend std::ostream& operator<<(std::ostream& i, const MaszynaStanow& m);
public:
    
    MaszynaStanow();

    ~MaszynaStanow();

    MaszynaStanow& operator+=(Stan*);

    void operator++();

    void operator--();

    void start();

    int retsize() const { return size; }
    int retW() const { return wsk; }

    MaszynaStanow& operator()();

private:

    Stan* tabS;
    int size;
    int wsk;
    bool on;




};


std::ostream& operator<<(std::ostream& i, const MaszynaStanow& m);