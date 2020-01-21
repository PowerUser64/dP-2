#include <iostream>

class Foo
{
public:
    Foo();
    Foo(const Foo &copy_);
    Foo(int x_);
    ~Foo();
    void setX(int x_);
    int getX() const;

private:
    int x;
};

Foo::Foo()
{
    x = 0;
    std::cout << "Default Constructor Called" << std::endl;
}

Foo::Foo(const Foo &copy_)
{
    x = copy_.x;
    std::cout << "Copy Constructor Called" << std::endl;
}

Foo::Foo(int x_)
{
    x = x_;
    std::cout << "Conversion Constructor Called" << std::endl;
}
Foo::~Foo()
{
    std::cout << "Destructor Called" << std::endl;
}

void Foo::setX(int x_)
{
    x = x_;
}
int Foo::getX() const
{
    return x;
}

void Function1(Foo f_)
{
    f_.setX(10);
}

void Function2(Foo &f_)
{
    f_.setX(10);
}

int main(void)
{
    Foo f;
    std::cout << "x in f: " << f.getX() << std::endl;
    Function1(f);
    std::cout << "x in f: " << f.getX() << std::endl;
    Function2(f);
    std::cout << "x in f: " << f.getX() << std::endl;
    Foo f2(f);
    f.setX(10);
    std::cout << "x in f: " << f.getX() << std::endl;
    std::cout << "x in f2: " << f2.getX() << std::endl;
    Foo f3 = 5;
    std::cout << "x in f3: " << f3.getX() << std::endl;
    return 0;
}
