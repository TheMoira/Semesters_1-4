#pragma once
#include "Visitor.h"
#include "ElData.h"



class AccumulatingVisitor: public Visitor
{

public:

    AccumulatingVisitor() : Visitor(), empty(true) {}

    ~AccumulatingVisitor() {}

    //
    //metoda dodajaca do skladnika md wartosc skladnika m_d obiektu klasy IntData korzystajac z metody get();
    //(w sytuacji kiedy jest to pierwsze w obiekcie dodanie po prostu przypisuje md wartosc skladnika m_d obiektu klasy IntData)
    void visit( IntData* );


    //metoda dodajaca do skladnika md wartosc skladnika m_d obiektu klasy FloatData korzystajac z metody getFloat();
    //(w sytuacji kiedy jest to pierwsze w obiekcie dodanie po prostu przypisuje md wartosc skladnika m_d obiektu klasy FloatData)
    void visit (FloatData* );

    float getTotalSum() const { return md; }

private:

    float md;
    bool empty;


};