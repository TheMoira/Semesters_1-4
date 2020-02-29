#pragma once

class MalenstwoSamoSprzatacz
{
public:

    MalenstwoSamoSprzatacz(Malenstwo* m) : mal(m) {}

    ~MalenstwoSamoSprzatacz() { delete mal; }

    int& wartosc() { return mal->wartosc(); }

    int operator++() { return mal->wartosc() + 1;}


private:

    Malenstwo* mal;

};