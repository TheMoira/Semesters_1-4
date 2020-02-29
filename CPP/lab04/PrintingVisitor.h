#pragma once
#include "Visitor.h"
#include "ElData.h"



class PrintingVisitor: public Visitor
{

public:

    PrintingVisitor() : Visitor() {}

    ~PrintingVisitor() {}

    //metoda wypisujaca na ekran wartosc skladnika m_d obiektu klasy IntData
    void visit( IntData* );


    //metoda wypisujaca na ekran wartosc skladnika m_d obiektu klasy FloatData
    void visit (FloatData* );


};