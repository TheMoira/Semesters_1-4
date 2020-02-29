#pragma once

class Visitor;

//klasa abstrakcyjna Data
class Data
{
public:

    Data() {}

    virtual ~Data() {}

    //wirtualna metoda uaktywniajaca dzialanie odpowiednich visitorow
    virtual void acceptVisitor( Visitor& v) = 0;


};