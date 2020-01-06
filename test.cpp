#include <iostream>
#define pr std::cout

int main()
{
    int input;
    pr << "int input = ";
    std::cin >> input;
    int i = 10, mod = input % i, modified = input;
    for (; modified != 0; modified -= mod)
    {
        pr << i << "'s:" << mod << ',';

        i *= 10;
        mod = input % i;
    }
    
}