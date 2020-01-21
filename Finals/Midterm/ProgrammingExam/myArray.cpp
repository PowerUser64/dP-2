#include "myArray.h"
#include <iostream>

// This methods adds an integer, represented by the value_parameter, to the end of the array.If the array does not have a place for the new integer, you will have to grow the array by 2 and then place the given integer value.
void myArray::push(int value_)
{
    if (size == capacity)
    {
        capacity *= 2;
        int *arrayPtr = new int[capacity * 2];
        for (int i = 0; i < size + 1; ++i)
            arrayPtr[i] = numbers[i];
        delete[] numbers;
        numbers = arrayPtr;
    }
    numbers[size] = value_;
    size++;
}

void myArray::pop()
{
    if (size)
        --size;
}

std::ostream &operator<<(std::ostream &creek, const myArray &that)
{
    for (int i = 0; that.get_size() > i; ++i)
        creek << that.numbers[i] << ' ';
    creek << std::endl;
    return creek;
}

myArray myArray::operator+(const myArray &that) const
{
    myArray other;
    int largerValue = that.size < size ? size : that.size;
    other.capacity = largerValue;
    other.size = largerValue;
    other.numbers = new int[largerValue];
    largerValue = that.size > size ? size : that.size;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    for (int i = 0; i < largerValue; ++i)
        other.numbers[i] = this->numbers[i] + that.numbers[i];
    return other;
}

myArray myArray::operator=(const myArray &that) const
{
    for (int i = 0; i < size; ++i)
        this->numbers[i] = that.numbers[i];
    return *this;
}

myArray &myArray::operator+=(const myArray &that)
{
    *this = *this + that;
    return *this;
}

// By default, the numbers array will be dynamically allocated and its size will be 1. Since no integers are stored in it yet, the size value will be 0 and the capacity will be 1.
myArray::myArray()
{
    size = 0;
    capacity = 1;
    numbers = new int[1];
}

myArray::myArray(const myArray &that)
{
    capacity = that.get_size();
    size = that.get_size();
    numbers = new int[size];
    for (int i = 0; i < size; ++i)
        numbers[i] = that.numbers[i];
}

myArray::~myArray()
{
    delete[] numbers;
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