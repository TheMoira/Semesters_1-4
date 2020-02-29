#pragma once
#include <string>


class Page{

public:

    Page(std::string head = "empty") : header(head), text("") {}

    ~Page() {}

    void AddHeader(std::string);

    void AddText(std::string);

    Page* Copy() const;

    void Print() const;

    std::string retTXT() const { return text; }
    std::string retH() const { return header; }

protected:

    std::string header;
    std::string text;

};