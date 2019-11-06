#include <iostream>
class ABC
{
public:
    ABC(int x = 0)
    {
        a_ = x;
    }
    void f1(void)
    {
        std::cout << "ABC1";
    }

    void f2(void)
    {
        std::cout << "ABC2";
    }

    void f3(int)
    {
        std::cout << "ABC3";
    }

private:
    int a_;
};

class X : public ABC
{
public:
    X(int x)
    {
        a_ = x;
    }

    void f1(int)
    {
        std::cout << "X1";
    }

    void f3(void)
    {
        std::cout << "X3";
    }

private:
    int a_;
};

X x(5);
ABC abc(6);
x.f1();   // a  NV
abc.f1(); // b  ABC1
x.f2();   // c  ABC2
abc.f2(); // d  ABC2
abc.f3(); // e  NV
x.f3();   // f  X3
x.f1(5);  // g  X1
x.f3(5);  // h  NV