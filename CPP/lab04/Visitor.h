#pragma once

class Data;
class IntData;
class FloatData;

//klasa abstrakcyjna Visitor
class Visitor
{
public:

    Visitor() {}

    virtual ~Visitor() {}

    //dwie metody wirtualne odpowiednie dla kazdego typu Data
    virtual void visit( IntData* ) = 0 ;
    virtual void visit (FloatData* ) = 0;

/* protected:

    Data *m_d; */

};