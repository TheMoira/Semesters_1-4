#pragma once
#include <iostream>

class TestObject
{
public:

    TestObject(int val = 0) : id(val) {}
    ~TestObject() = default;

    void Print() const { std::cout<<"Object with ID="<<id<<std::endl;} 
    void Set(int val) { id = val; }

private:
    int id;
};