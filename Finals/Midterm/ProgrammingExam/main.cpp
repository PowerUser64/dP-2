#include "myArray.h"

static void PrintArrayWithStats(const char *array_name_, const myArray& a_)
{
    std::cout << array_name_ << "'s capacity = " << a_.get_capacity() << std::endl;
    std::cout << array_name_ << "'s size = " << a_.get_size() << std::endl;
    std::cout << a_;
}

void Test1(void)
{
    myArray a1;

    PrintArrayWithStats("a1", a1);
    std::cout << std::endl;

    a1.push(10);
    PrintArrayWithStats("a1", a1);
    std::cout << std::endl;

    a1.push(20);
    PrintArrayWithStats("a1", a1);
    std::cout << std::endl;

    a1.push(30);
    PrintArrayWithStats("a1", a1);
    std::cout << std::endl;

    for (int i = 0; i < 5; ++i)
    {
        a1.pop();
    }
    PrintArrayWithStats("a1", a1);
    std::cout << std::endl;

    for (int i = 0; i < 5; ++i)
    {
        a1.push(i);
    }
    PrintArrayWithStats("a1", a1);
    std::cout << std::endl;
}

void Test2(void)
{
    myArray a1;

    for (int i = 0; i < 5; ++i)
    {
        a1.push(i);
    }
    PrintArrayWithStats("a1", a1);
    std::cout << std::endl;

    myArray a2(a1);
    PrintArrayWithStats("a2", a2);
    std::cout << std::endl;

    a2.pop();
    PrintArrayWithStats("a1", a1);
    std::cout << std::endl;
    PrintArrayWithStats("a2", a2);
    std::cout << std::endl;

    myArray a3 = a1;
    PrintArrayWithStats("a3", a3);
    std::cout << std::endl;

    a3 = a2;
    PrintArrayWithStats("a3", a3);
    std::cout << std::endl;

    a3.pop();
    PrintArrayWithStats("a2", a2);
    std::cout << std::endl;
    PrintArrayWithStats("a3", a3);
    std::cout << std::endl;

    a3 = a3;
    PrintArrayWithStats("a3", a3);
    std::cout << std::endl;
}

void Test3(void)
{
    myArray a1;
    for (int i = 0; i < 5; ++i)
    {
        a1.push(i * 2);
    }
    PrintArrayWithStats("a1", a1);
    std::cout << std::endl;

    myArray a2;
    for (int i = 0; i < 7; ++i)
    {
        a2.push(i * 2 + 1);
    }
    PrintArrayWithStats("a2", a2);
    std::cout << std::endl;

    myArray a3;
    for (int i = 0; i < 3; ++i)
    {
        a3.push(i * 3 - 1);
    }
    PrintArrayWithStats("a3", a3);
    std::cout << std::endl;

    std::cout << "a4 = a1 + a2:" << std::endl;
    std::cout << "==============" << std::endl;
    myArray a4 = a1 + a2;
    PrintArrayWithStats("a4", a4);
    std::cout << std::endl;

    std::cout << "a5 = a1 + a3:" << std::endl;
    std::cout << "==============" << std::endl;
    const myArray a5 = a1 + a3;
    PrintArrayWithStats("a5", a5);
    std::cout << std::endl;


    std::cout << "a6 = a5 + a4:" << std::endl;
    std::cout << "==============" << std::endl;
    myArray a6 = a5 + a4;
    PrintArrayWithStats("a6", a6);
    std::cout << std::endl;

    std::cout << "Printing all arrays:" << std::endl;
    std::cout << "=====================" << std::endl;
    PrintArrayWithStats("a1", a1);
    std::cout << std::endl;
    PrintArrayWithStats("a2", a2);
    std::cout << std::endl;
    PrintArrayWithStats("a3", a3);
    std::cout << std::endl;
    PrintArrayWithStats("a4", a4);
    std::cout << std::endl;
    PrintArrayWithStats("a5", a5);
    std::cout << std::endl;
    PrintArrayWithStats("a6", a6);
    std::cout << std::endl;
}

// void Test4(void)
// {
//     myArray a1;
//     for (int i = 0; i < 5; ++i)
//     {
//         a1.push(i * 2);
//     }
//     PrintArrayWithStats("a1", a1);
//     std::cout << std::endl;

//     myArray a2;
//     for (int i = 0; i < 7; ++i)
//     {
//         a2.push(i * 2 + 1);
//     }
//     PrintArrayWithStats("a2", a2);
//     std::cout << std::endl;

//     myArray a3;
//     for (int i = 0; i < 3; ++i)
//     {
//         a3.push(i * 3 - 1);
//     }
//     PrintArrayWithStats("a3", a3);
//     std::cout << std::endl;

//     const myArray a4(a3);
//     PrintArrayWithStats("a4", a4);
//     std::cout << std::endl;


//     std::cout << "a1 += a3:" << std::endl;
//     std::cout << "==========" << std::endl;
//     a1 += a3;
//     PrintArrayWithStats("a1", a1);
//     std::cout << std::endl;

//     std::cout << "a1 += a2:" << std::endl;
//     std::cout << "==========" << std::endl;
//     a1 += a2;
//     PrintArrayWithStats("a1", a1);
//     std::cout << std::endl;

//     //Should not compile
//     //a4 += a2;


//     std::cout << "Printing all arrays:" << std::endl;
//     std::cout << "=====================" << std::endl;
//     PrintArrayWithStats("a1", a1);
//     std::cout << std::endl;
//     PrintArrayWithStats("a2", a2);
//     std::cout << std::endl;
//     PrintArrayWithStats("a3", a3);
//     std::cout << std::endl;
//     PrintArrayWithStats("a4", a4);
//     std::cout << std::endl;

// }

int main(void)
{
    // Test1();
    // Test2();
    Test3();
    //Test4();

    return 0;
}