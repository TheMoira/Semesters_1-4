#include "Book.h"
#include <iostream>

Book::Book(std::string who)
//Book::Book()
{
    author = who;
    header = "empty";
    title = "none";

    size = 0;
    count = 0;

}

Book::~Book()
{
    for(int i = 0;i<size;i++)
    {
        delete [] pages[i];
    }

    delete [] pages;
}


Page** PCopy(Page** tab, int size)
{
    Page** ptab = new Page*[size];

    for(int i =0;i<size;i++)
    {
        ptab[i] = tab[i]->Copy();
    }

    return ptab;
} 

void Book::AddPage(Page* p)
{
    Page** temp = PCopy(pages,size);
    size++;
    pages = new Page*[size];
    pages = PCopy(temp,size-1);
    pages[size-1] = p;

    delete [] temp;
}


Book* Book::Copy() const
{
    Book* nowa = new Book(author);
    nowa->AddTitle(title);
    nowa->AddHeader(header);

    for(int i=0;i<size;i++)
    {
        nowa->AddPage(pages[i]);
    }
    return nowa;
}

void Book::Copy(Book* b)
{
    author = b->retA();
    header = b->retH();
    title = b->retT();
    size = b->retS();

    pages = new Page*[size];

    for(int i=0; i<size; i++)
    {
        pages[i] = (b->retP(i)) -> Copy();
    }

    //this = b->Copy();

}

void Book::AddTitle(std::string tit)
{
    title = tit;
}

void Book::AddHeader(std::string h)
{
    for(int i=0; i<size; i++)
    {
        pages[i]->AddHeader(h);
    }
}

void Book::AddText(std::string txt)
{
    if(count>=size)
    {
        std::cout<<"[ERROR] Not enough pages in the book!"<<std::endl;
        count = 0;
    }
    else
    {
        pages[count]->AddText(txt);
        count++;
    }
}

void Book::Print() const
{
    std::cout<<"Book::Author "<<author<<std::endl;

    std::cout<<"Page(0)::text Title: "<<title<<"(header: ";
    std::cout<<header<<")\n";

    if(!size)
    {
        std::cout<<"Book is empty\n";
    }
    else
    {
        for(int i=0; i<size; i++)
        {
            std::cout<<"Page("<<i+1<<")::text "<<pages[i]->retTXT();
            std::cout<<"(header: "<<pages[i]->retH()<<std::endl;
        }
    }

}