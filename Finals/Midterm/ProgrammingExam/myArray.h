#pragma once
#include <iostream>

class myArray
{
public:
    // This methods adds an integer, represented by the value_parameter, to the end of the array.If the array does not have a place for the new integer, you will have to grow the array by 2 and then place the given integer value.
    void push(int value_);
    // This method removes an the last integer in the array. Removing an integer is done by simply decreasing the size value of the array.
    void pop();
    // This overloaded operator allows us to add two myArray instances. The result will contain the added value of the element of instance one with the elements of instance two respectively. The sizeand the capacity of the returned myArrayinstance will be the same as thesize of themyArrayinstance that has the largest size.
    myArray operator+(const myArray &that) const;
    //equals operator
    myArray operator=(const myArray &that) const;
    // This overloaded operator allows us to add the elements of the right hand side myArray instance to the elements of the left hand side myArrayinstance. If the right hand side's size is greater than the left hand side's size, you will need to resize your left hand side's array.
    myArray &
    operator+=(const myArray &that);
    friend std::ostream &operator<<(std::ostream &creek, const myArray &that);

    myArray(void);
    myArray(const myArray &that);

    ~myArray();

    int get_capacity(void) const;
    int get_size(void) const;

private:
    // Member array that will hold all the integers. This array will be managed by the class methods. The array will grow if needed.
    int *numbers;
    // This integer represents how many integers we currently have in the array.
    int size;
    // This integer represents the size of the array.In other words, how many integers we can totally hold before we have to grow our array. // PS: Every time we grow the array we will double its capacity.
    int capacity;
};
