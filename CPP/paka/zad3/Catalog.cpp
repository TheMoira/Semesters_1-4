#include "Catalog.h"
#include <iostream>

Catalog::Catalog(std::string name)
{
    title = name;
    size = 0;
}

Catalog::~Catalog()
{
    delete [] books;
}

void BCopy(Book** to, Book** from, int size)
{
    for(int i=0; i<size; i++)
    {
        to[i] = from[i]->Copy();
    }
}

void Catalog::AddBook(const Book* b)
{
    if(!size)
    {
        size++;
        books = new Book*[size];
        books[0] = b->Copy();
    }
    else
    {
        Book *temp[size+1];
        BCopy(temp,books,size++);
        books = new Book*[size];
        BCopy(books, temp, size);
        books[size-1] = b->Copy();
        delete [] temp;
    }
}

void Catalog::Print() const
{
    std::cout<<"Catalog::name "<<title<<std::endl;

    for(int i=0; i<size; i++)
    {
        std::cout<<"Catalog::book("<<i<<") "<<books[i]->retT()<<std::endl;
    }
}