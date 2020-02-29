#include <iostream>

void fun(int t[3]);

int main()
{

    int tab[] = {1,2,3};

    for(int i=0;i<3;i++)
    {
        std::cout<<tab[i]<<std::endl;
    }

    std::cout<<std::endl;

    fun(tab);
    
    for(int i=0;i<3;i++)
    {
        std::cout<<tab[i]<<std::endl;
    }


    return 0;
}


void fun(int t[3])
{
    t[0] += 1;
    t[1] += 1;
    t[2] += 1;
}