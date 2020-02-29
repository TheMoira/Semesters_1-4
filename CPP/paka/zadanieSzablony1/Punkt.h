#pragma once

class Punkt
{
public:

    Punkt(int x, int y) : m_x(x), m_y(y) {}

    ~Punkt() = default;

    template <int T> int wsp() const
    {
        return (T==0)? m_x : m_y;
    }

    template <typename T> static T min(T t1, T t2)
    {
        return (t1<t2)? t1 : t2;
    }

    template <typename T> static T max(T t1, T t2)
    {
        return (t1<t2)? t2 : t1;
    }

    int retX() const {return m_x;}
    int retY() const {return m_y;}

private:
    int m_x;
    int m_y;

};


bool operator<(const Punkt& p1, const Punkt& p2)
{
    if(p1.retX() != p2.retX())
    {
        return p1.retX()<p2.retX();
    }
    else
    {
        return p1.retY()<p2.retY();
    }
}
