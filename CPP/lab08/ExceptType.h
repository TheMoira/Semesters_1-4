#pragma once
#include <string>


class ExceptType
{
    public:

    ExceptType(int t = 1) : type(t) {}
    virtual ~ExceptType() = default;

    virtual void PrzedstawSie() const = 0;

    int getType() const { return type; }
    virtual ExceptType* getExp() {}

    protected:

    int type;

}; 

class ExceptType1 : public ExceptType
{
public:

    ExceptType1() : exp(new ExceptType3()){}
    ~ExceptType1() { delete exp; }

    void PrzedstawSie() const;
    ExceptType* getExp() { return exp; }

private:

    ExceptType3 * exp;

};

class ExceptType2 : public ExceptType
{
public:

    ExceptType2() : ExceptType(2), exp(new ExceptType4()) {}
    ~ExceptType2() { delete exp; }

    void PrzedstawSie() const;
    ExceptType* getExp() { return exp; }

private:

    ExceptType4 * exp;

};

class ExceptType3 : public ExceptType
{
public:

    ExceptType3() {}
    ~ExceptType3() = default;

    void PrzedstawSie() const;

    
};

class ExceptType4 : public ExceptType
{
public:

    ExceptType4() {}
    ~ExceptType4() = default;

    void PrzedstawSie() const;
    /* std::string adres() const; */

};


void HandleExcept(const ExceptType * exp);