#pragma once


template <int a, int b, bool neg, bool gr10>
class MyPower
{
    public:
    static const double value;
};


template <int a, int b>
class Power
{
    public:
        static const double value;
};

template <int a, int b, bool neg>
class MyPower<a, b, neg, true>
{
    public:
        static const double value;
};

template <int a, int b>
class MyPower<a, b, true, false>
{
    public:
        static const double value;
};

template <int a, int b>
class MyPower<a, b, false, false>
{
    public:
        static const double value;
};

template <int a>
class MyPower<a, 0, true, false>
{
    public:
        static const double value;
};

template <int a>
class MyPower<a, 0, false, false>
{
    public:
        static const double value;
};




template <int a, int b>
const double Power<a,b>::value = MyPower<a, b, (b < 0), (b > 10) || (b < -10)>::value;


template <int a, int b, bool neg, bool gr10>
const double MyPower<a,b,neg,gr10>::value =  a * MyPower<a,b-1,neg,gr10>::value; 

template <int a, int b, bool neg>
const double MyPower<a, b, neg, true>::value = 0/0;

template <int a, int b>
const double MyPower<a, b, true, false>::value = (1/a) * MyPower<a,b+1,true,false>::value;
//const double MyPower<a, b, true, false>::value = a;

template <int a, int b>
const double MyPower<a, b, false, false>::value = a * MyPower<a,b-1,false,false>::value;

template <int a>
const double MyPower<a, 0, true, false>::value = 1.0;

template <int a>
const double MyPower<a, 0, false, false>::value = 1.0;

/* 
template <int a, int b, bool neg>
const double MyPower<a,b,neg,true>::value = a * MyPower<

template <int a, int b, bool neg>
const double MyPower<a,b,neg,false>::value = a * MyPower<

template <int a, int b, bool gr10>
const double MyPower<a,b,false,gr10>::value = 

template <int a, int b, bool gr10>
const double MyPower<a,b,true,gr10>::value =  */

















/*
template <int N>
struct factor
{
    static const int value;
}
 
template <int N> ...
const int factor<N>::value = factor<N-1>::value; 

template <>
struct factor<0> 
{...}



template <int b, int e, bool neg, bool gr10>
struct MyPower {
    static const double value;
}

template<int b, int e>
struct Power{
    static
}

template<int b, int e>
const double Power<b,e> = MyPower

*/