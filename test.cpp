/*
 * Guess what? You get to review assignment operators and copy constructors yet again! 
 * (I will keep asking you to do this until I am confident nearly everyone can do it -- you'll also need to do this on exams, so extra practice never hurts.)
 * The following class represents a dynamically allocated array of floats. 
 * 
 * Implement the assignment operator and copy constructor so that they perform a proper deep copy and there are no memory leaks or other undefined behavior.
 */
#include "test.h"

class DynamicArray
{
public:
    // Default Constructor
    DynamicArray()
        : data(nullptr), size(0)
    {
    }

    DynamicArray(const DynamicArray &other)
        : data(nullptr), size(0)
    {
        float *data = new float[size];
    }

    // Destructor
    ~DynamicArray()
    {
        delete[] data;
    }

    // Other functions go here!
    // assignment operator
    DynamicArray& operator=(const DynamicArray array)
    {
        if (size = array.size)
            for (int i = 0; i < array.size; i++)
            {
            }
    }

private:
    float *data;
    unsigned size;
};

// Note that I have not given you the prototypes for these functions. You will have to figure out what the prototypes should be on your own.