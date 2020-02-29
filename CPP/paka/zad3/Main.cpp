// Nazwa pliku wykonywalnego: bib



// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal

// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego

// pliku.



// Prosze napisac klasy reprezentujace page, book oraz catalog.

// Page zawiera w sobie naglowek (header) oraz bufor na tekst.

// Odpowiednie zależności dziedziczenia lub zawierania proszę

// wywnioskować z treści main().



// W zadaniu mozna korzystac z elementow bilbioteki standardowej

// zwlaszcza klasy std::string, ktora jest dostepna w pliku o nazwie

// "string".



// Pliku Main.cpp, nie wolno modyfikowac.



// Ostateczny program powinien byc przyjazny dla programisty (miec

// czytelny i dobrze napisany kod). 



// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny

// o nazwie bib. Program nalezy kompilowac z flagami -Wall -g.



// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki

// obiektowe i plik wykonywalny.



// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,

// ani zadnych innych materialow (w tym wlasnych wczesniej

// przygotowanych plikow oprocz makefile)



// Rozwiazanie (archiwum bib.tar.gz zawierajace dodane pliki, makefile i Main.cpp)

// nalezy wgrac do UPEL.



#include "Main.h"



 

int main()

{

    Page* a = new Page();

    a->AddHeader("template header");

    Page* b = a->Copy();



    Page* c = new Page();

    c->AddText("Text example added to the dummy page");

    c->Print();

        

    Book* Template = new Book();

    Template->AddPage(a);           

    Template->AddPage(a);           

    Template->AddPage(b);

    Template->AddPage(b);

    Template->Print();

    

    delete a;

    delete b;

    delete c;



    Book* Poem = new Book();



    Poem->Copy(Template);

    Poem->Print();

    

    // Ustawianie tytulu na 1 stronie;

    Poem->AddTitle("Swierszcze");

    // Ustawianie naglowku na wszystkich stronach oprocz pierwszej (tytulowej)                           

    Poem->AddHeader("Poem:Swierszcze");                     

    

    // Kazde wywołanie AddText() to pisanie na kolejnej stronie 

    // Uwaga: do dysposzycje są te strony które zostały jawnie dodane poprzez AddPage()

    Poem->AddText("Text example added to the poem book");   

    Poem->AddText("Text example added to the poem book");

    Poem->AddText("Text example added to the poem book");

    Poem->AddText("Text example added to the poem book");

    Poem->AddText("Text example added to the poem book");

    Poem->Print();



    Catalog* AllBooks = new Catalog("MyCatalog");

    

    AllBooks->AddBook(Poem);

    AllBooks->AddBook(Template);

    AllBooks->AddBook(new Book("Slonie"));

    AllBooks->AddBook(new Book("Zyrafy"));

    AllBooks->Print();



    delete AllBooks;

 

    return 0;

}





/*

Page::header empty

Page::text Text example added to the dummy page



Book::autor anonym

Page(0)::text Title page(header: empty)

Page(1)::text empty(header: template header)

Page(2)::text empty(header: template header)

Page(3)::text empty(header: template header)

Page(4)::text empty(header: template header)



Book::autor (copy) anonym

Page(0)::text Title page(header: empty)

Page(1)::text empty(header: template header)

Page(2)::text empty(header: template header)

Page(3)::text empty(header: template header)

Page(4)::text empty(header: template header)



[ERROR]:: No enough pages in the book!



Book::autor (copy) anonym

Page(0)::text Title: Swierszcze(header: empty)

Page(1)::text Text example added to the poem book(header: Poem:Swierszcze)

Page(2)::text Text example added to the poem book(header: Poem:Swierszcze)

Page(3)::text Text example added to the poem book(header: Poem:Swierszcze)

Page(4)::text Text example added to the poem book(header: Poem:Swierszcze)



Catalog::name MyCatalog

Catalog::book(0) Swierszcze

Catalog::book(1) dummy

Catalog::book(2) Slonie

Catalog::book(3) Zyrafy

*/