#pragma once
#include <string>
#include "AttFormat.h"
#include "AttColor.h"
#include "StringConvertable.h"

//klasa MyText dziedziczaca po StringConvertable, AttFormat,AttColor
class MyText : public StringConvertable, public AttFormat, public AttColor
{
    public:
    //konstruktor MyText, konstruujacy obiekt AttFormat i AttColor
    MyText(const std::string str, AttFormat::Option opF, AttColor::Option opC)
    : AttFormat(opF), AttColor(opC), text(str) {}

    ~MyText() {}

    std::string rawString() const { return text; }

    void setFormat(AttFormat::Option f) { Fopt = f; }
    void setColor(AttColor::Option c) { Copt = c; }
    void setText(std::string str) { text = str; }

    




private:

    std::string text;
};