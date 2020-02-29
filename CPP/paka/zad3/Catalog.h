#pragma once
#include "Book.h"

class Catalog
{
    friend void BCopy(Book** to, Book** from, int size);

public:

    Catalog(std::string name);

    ~Catalog();

    void AddBook(const Book*);

    void Print() const;

protected:

    Book** books;
    std::string title;
    int size;
};

void BCopy(Book** to, Book** from, int size);