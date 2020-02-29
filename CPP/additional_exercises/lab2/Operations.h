#pragma once


class Operations
{
public:

    Operations() {}
    
    virtual ~Operations() {}

    virtual void PrintWithValue() = 0;

    virtual double retV() const = 0;

};