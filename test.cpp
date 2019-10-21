#include <iostream>
#define kingdom class
#define amimal class

kingdom Animalia
{
public:
    virtual void WhatAmI() = 0;
};
amimal Cat : public Animalia
{
    public :
        void WhatAmI()
        {
            std::cout << "I'm a cat!\n";
        }
};

amimal Dog : public Animalia
{
    public :
        void WhatAmI()
        {
            std::cout << "doge\n";
        }
};

int main(void)
{
    Animalia *cat = new Cat();
    Animalia *dog = new Dog();
    cat->WhatAmI();
    dog->WhatAmI();
    return 32223;
}