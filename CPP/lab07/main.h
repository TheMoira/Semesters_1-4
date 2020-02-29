#pragma once
#include <iostream>
#include <iomanip>
#include <string>

//klasa przechowujaca numer indeksu Studenta i Dydaktyka
class NumerId
{
public:

    NumerId(int num) : numer(num) {}
    virtual ~NumerId() = default;
    int getNr() const { return numer; }


protected:

    int numer;
};

//klasa bazowa dla Studenta i Pracownika
class Osoba
{
public:

    Osoba(std::string name = "") : m_name(name){}
    virtual ~Osoba() = default;
    std::string getName() const { return m_name; }

    //wirtualna metoda, dzieki ktorej przeladowanie operatora << staje sie
    //prawie wirtualna
    virtual std::ostream& wypisz() const = 0;

protected:

    std::string m_name;

};

//klasa bazowa dla Dydaktyka i Woznego
class Pracownik : public virtual Osoba
{
public:

    Pracownik(std::string name) :
        Osoba(name) {}
    virtual std::ostream& wypisz() const = 0;

    virtual ~Pracownik() = default;
};

//klasa bazowa dla Doktoranta
class Student : public virtual Osoba
{
public:
    
    Student(std::string name, NumerId nr) : 
    Osoba(name), m_nr(nr) {}

    NumerId numId() const { return m_nr.getNr(); }

    virtual ~Student() = default;

    virtual std::ostream& wypisz() const { return std::cout<<m_name<<" - student"; }

protected:

    NumerId m_nr;

};

class Wozny : public Pracownik
{
    public:

    Wozny(const std::string name) : Osoba(name), Pracownik(name) {}
    ~Wozny() = default;

    std::ostream& wypisz() const { return std::cout<<m_name<<" - wozny"; }

};

//klasa bazowa dla Doktoranta
class Dydaktyk : public Pracownik
{
public:

    Dydaktyk(const std::string name, NumerId nr) : 
    Osoba(name), Pracownik(name), m_nr(nr) {}

    NumerId numId() const { return m_nr.getNr(); }

    virtual std::ostream& wypisz() const { return std::cout<<m_name<<" - dydaktyk"; }

    virtual ~Dydaktyk() {}

protected:

    NumerId m_nr;

};

class Doktorant : public Student, public Dydaktyk
{
public:

    Doktorant(std::string name, NumerId nrN, NumerId nrS) :
    Osoba(name), Student(name, nrS), Dydaktyk(name,nrN){}

    NumerId numId_nauczyciel() const { return Dydaktyk::numId(); }
    NumerId numId_uczen() const { return Student::numId(); }

    std::ostream& wypisz() const { return std::cout<<m_name<<" - doktorant"; }

    ~Doktorant() = default;
};




std::ostream& operator<<(std::ostream& o, const NumerId& nr)
{
    return o<<"<"<<std::setw(6)<<std::setfill('0')<<nr.getNr()<<">";
}

std::ostream& operator<<(std::ostream& o, const Osoba& os)
{
    return os.wypisz();
}

//std::cout<<std::setw(6)<<std::setfill('0')