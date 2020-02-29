// Nazwa pliku wykonywalnego: mobile



// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal

// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego

// pliku.



// Prosze napisac klasy reprezentujace:

// Silnik

// Pojazd

// Samochod

// Motorower

// Mercedes

// Romet

// Odpowiednie zależności dziedziczenia lub zawierania proszę

// wywnioskować z treści main().



// W zadaniu mozna korzystac z elementow bilbioteki standardowej

// zwlaszcza klasy std::string, ktora jest dostepna w pliku o nazwie

// "string".



// Pliku Main.cpp, nie wolno modyfikowac.



// Ostateczny program powinien byc przyjazny dla programisty (miec

// czytelny i dobrze napisany kod).



// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny

// o nazwie mobile. Program nalezy kompilowac z flagami -Wall -g.



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

   Silnik diesel(115,1.8,"ON");                 // moc, pojemnosc, paliwo

   Samochod samochod(diesel, "Czarny", 0.);     // silnik, kolor, stan licznika



   Mercedes mercedes(diesel,999.);              // silnik, stan licznika

   Mercedes KlasaA;

   Mercedes Muzealny;

   KlasaA = Muzealny = mercedes;



   std::cout<<"**** AUTOMOBILE ****" << std::endl;

   std::cout<<"Ogolny typ samochod:" << samochod << std::endl;

   std::cout<<"Mercedes:" << mercedes << std::endl;



   Muzealny.Przebieg(4321);

   std::cout<<"Muzealny:" << Muzealny << std::endl;

   std::cout<<"KlasaA:" << KlasaA << std::endl;



   std::cout<<"**** MOTOCYKLE ****" << std::endl;

   Silnik benzyna(10,0.5,"Pb95");             // moc, pojemnosc, paliwo

   Motorower motorower(benzyna,"Czarny",0.);  // silnik, kolor, stan licznika

   Romet romet(benzyna,1001);                 // silnik, stan licznika



   Romet unikat = romet;



   std::cout<<"Ogolny typ motorower:" << motorower << std::endl;

   std::cout<<"Romet:" << romet << std::endl;

   std::cout<<"Unikat:" << unikat << std::endl;



    return 0;

}



/*

**** AUTOMOBILE ****

Ogolny typ samochod:

Liczba kol 4

Stan licznika 0 [km]

Kolor Czarny



Mercedes:

Liczba kol 4

Stan licznika 999 [km]

Kolor czarny metalic



Muzealny:

Liczba kol 4

Stan licznika 4321 [km]

Kolor czarny metalic



KlasaA:

Liczba kol 4

Stan licznika 0 [km]

Kolor czarny metalic



**** MOTOCYKLE ****

Ogolny typ motorower:

Liczba kol 2

Stan licznika 0 [km]

Kolor Czarny



Romet:

Liczba kol 2

Stan licznika 1001 [km]

Kolor czerwony metalic



Unikat:

Liczba kol 2

Stan licznika 0 [km]

Kolor czerwony metalic



*/