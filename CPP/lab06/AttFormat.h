#pragma once

class AttFormat
{
public:

    enum Option {BOLD, DIM, UNDERLINED, RESET};

    AttFormat(Option o) : Fopt(o) {}
    virtual ~AttFormat() {}
    
    Option getFormat() const { return Fopt; }

protected:

    Option Fopt;

};