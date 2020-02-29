// Nazwa pliku wykonywalnego: Punkt



// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal

// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego

// pliku.



// Tematem zadania sa szablony funkcji. Funkcje szablonowe moga byc metodami i moga byc statyczne.

// Prosze napisac klase Punkt która ma przechowywac dwa skladniki 

// (współrzędne punktu, typu int)

// Klasa ta posiada metode dostepowa wsp, ktora jest szablonowa i pozwala na dostanie sie

// do wsp. x lub y  przy arg szablonowy 0 i 1 odpowiednio.

// Dwa obiekty kl. Punkt mozna porownywac <. Najpierw porownywane sa wsp. x a wsp. y tylko gdy x-owe sa rowne.

// W sklad klasy wchodza tez metody statyczne min i max. Cala zabawa polega na tym zeby zaprogramowac je w sposob ogolny 

// tak by dzialaly dla klasy Punkt i dla typow prostych.

// Uwaga na poprawnosc const!



// Pliku Main.cpp, nie wolno modyfikowac.



// Ostateczny program powinien byc przyjazny dla programisty 

// (miec czytelny i dobrze napisany kod). 



// Program nalezy kompilowac z flagami -Wall -g.



// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki

// obiektowe i plik wykonywalny.



// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,

// ani zadnych innych materialow (w tym wlasnych wczesniej

// przygotowanych plikow oprocz makefile)



// Rozwiazanie (czyli dodane pliki, makefile i Main.cpp) nalezy

// wgrac do UPEL.



#include <iostream>

#include "Punkt.h"





int main() {



  const Punkt s1(0, 1);

  const Punkt s2(-5, 2);

  std::cout << "s1 " << s1.wsp<0>() <<  " " << s1.wsp<1>() << std::endl;

  std::cout << "s2 " << s2.wsp<0>() <<  " " << s2.wsp<1>() << std::endl;

  

  std::cout << Punkt::min(s1.wsp<0>(), s2.wsp<0>()) << " " << Punkt::min(s1.wsp<1>(), s2.wsp<1>()) << std::endl;

  std::cout << Punkt::max(s1.wsp<0>(), s2.wsp<0>()) << " " << Punkt::max(s1.wsp<1>(), s2.wsp<1>()) << std::endl;



  std::cout << Punkt::min(s1, s2).wsp<0>() << " " << Punkt::min(s1, s2).wsp<1>() << std::endl;

  std::cout << Punkt::max(s1, s2).wsp<0>() << " " << Punkt::max(s1, s2).wsp<1>() << std::endl;



  std::cout << "porownanie: " << (s1 < s2) << " " << (s2 < s1) << std::endl;  

}

/* wynik

s1 0 1

s2 -5 2

-5 1

0 2

-5 2

0 1

porownanie: 0 1

 */