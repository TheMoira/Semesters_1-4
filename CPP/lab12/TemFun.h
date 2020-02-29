#pragma once
#include <iostream>
#include "Array.h"

//klasa pomocnicza num
namespace num
{

    //szablon funkcji wypisujacej wartosci tablicy lub stringa lub tablicy w klasie Array
    template <typename T>
    void print(T& tab, int size)
    {
        for(int i=0; i<size; i++)
        {
            std::cout<<tab[i]<<", ";
        }
        std::cout<<std::endl;
    }
    

   /*  void print(Array& T)
    {
        for(int i=0; i < T.size(); i++)
        {
            std::cout<<T[i]<<", ";
        }

        std::cout<<std::endl;
    }

    void print(std::string T)
    {
        for(unsigned int i=0; i < T.size(); i++)
        {
            std::cout<<T[i]<<", ";
        }

        std::cout<<std::endl;
    } */


    //szablon funkcji wypisujacy to co pierwsza funkcja print, jednak bez argumentu rozmiaru
    template <typename T, int C>
    void print(T (&tab)[C])
    {

        for(unsigned int i=0; i < C; i++)
        {
            std::cout<<tab[i]<<", ";
        }

        std::cout<<std::endl;
        
    }

    template <typename T>
    void print(T& tab)
    {
      //std::cout<<"Uzywam tego tu\n"<<std::endl;
        
        for(int i=0; i < tab.size(); i++)
        {
            std::cout<<tab[i]<<", ";
        }

        std::cout<<std::endl;
        
    }
    
    template <typename T>
    void print(T *tab)
    {
      std::cout<<"Uzywam tego tu\n"<<std::endl;
        
        for(int i=0; i < sizeof(tab)/sizeof(T); i++)
        {
            std::cout<<tab[i]<<", ";
        }

        std::cout<<std::endl;
        
    }
    
    //szablon funkcji sortujacej wykorzystujacej bubble sort
    template <typename T>
    void bubble_sort(T& tab, int size)
    {
        for(int i = 0; i < size; ++i)
        {
            for(int j = i+1; j < size; ++j)
            {
                if( tab[i] > tab[j])
                {
                    std::swap(tab[i], tab[j]);
                }
				
            }
			
        }
		
    }

    //szablon funkcji sprawdzajacej czy w podanym zakresie tablicy sa same liczby pierwsze
    template <int t1, int t2> bool all_primes(int *tab)
    {
        for(int i=t1; i < t2; ++i){

            for(int j = 2; j<tab[i]; j++)
            {
                if(tab[i]%j == 0)
                {
                    return false;
                }
            }
        }

        return true;
    }


};
