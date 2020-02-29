#include "Page.h"
#include <iostream>

void Page::AddHeader(std::string txt)
{
    header = txt;
}

void Page::AddText(std::string txt)
{
    text = txt;
}

Page* Page::Copy() const
{
    Page* nowa = new Page(header);
    nowa->text = text;

    return nowa;
}

void Page::Print() const
{
    std::cout<<"Page::header "<<header<<std::endl;
    std::cout<<"Page::text "<<text<<std::endl;
}