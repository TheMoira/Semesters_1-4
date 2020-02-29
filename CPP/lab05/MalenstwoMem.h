#pragma once
#include "Malenstwo.h"


class MalenstwoMem
{
    friend class Malenstwo;
public:

    static void add(Malenstwo);
    static Malenstwo& retM();

private:

    static Malenstwo tab[100];
    static int count = 0;
};