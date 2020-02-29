#pragma once
#include "Page.h"

class Book
{
    friend Page** PCopy(Page**, int);
public:

    Book(std::string who = "anonym");
    ////Book();

    ~Book();

    void AddPage(Page*);

    Book* Copy() const;

    void Copy(Book*);

    void Print() const;

    void AddTitle(std::string);

    void AddHeader(std::string);

    void AddText(std::string);

    std::string retA() const { return author; }
    std::string retH() const { return header; }
    std::string retT() const { return title; }
    Page* retP(int i) const {return pages[i]; }
    int retS() const { return size; }

protected:

    std::string author;
    std::string header;
    std::string title;

    Page** pages;
    int size;
    int count;

};


Page** PCopy(Page**, int);