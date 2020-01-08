#include "myArray.h"
#include "main.cpp"

// This methods adds an integer, represented by the value_parameter, to the end of the array.If the array does not have a place for the new integer, you will have to grow the array by 2 and then place the given integer value.
void myArray::push(int value_)
{
    int *retna = new int[capacity * 2];
    for(int i = 0; i < size + 1; ++i)
        retna->numbers[i] = numbers[i];
    retna->numbers[size + 1] = value_;
}
void myArray::pop()
{
    // fdsa
}
myArray myArray::operator+(myArray &that)
{
    myArray Arie;
    for(int i = 0; i < size; )
        Arie->numbers + that.numbers;
    return ;
}
myArray &myArray::operator+=(myArray &that)
{
    return this->numbers + that;
}

// By default, the numbers array will be dynamically allocated and its size will be 1. Since no integers are stored in it yet, the size value will be 0 and the capacity will be 1.
myArray::myArray()
{
    size = 0;
    capacity = 1;
    numbers = new int[1];
}
// returns the capacity value
int myArray::get_capacity(void) const
{
    return capacity;
}
// returns the size value.
int myArray::get_size(void) const
{
    return size;
}