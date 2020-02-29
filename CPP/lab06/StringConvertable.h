#pragma once
#include <string>

//Maria Korkuc
//Wiktor Jasinski


class StringConvertable
{
public:

    virtual ~StringConvertable() {}

    virtual std::string rawString() const = 0;

    
};