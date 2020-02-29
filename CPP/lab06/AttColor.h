#pragma once

class AttColor
{
public:

    enum Option {BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, GRAY, WHITE, RESET};

    AttColor(Option o) : Copt(o) {}
    virtual ~AttColor() {}
    
    Option getColor() const { return Copt; }

protected:

    Option Copt;

};