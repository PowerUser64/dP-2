#pragma once
#include "Point.h"
#include <iostream>

class Shape
{
public:
    Shape(Point center_);
    virtual ~Shape();
    Point GetCenter() const;
    void SetCenter(float x_, float y_);
    virtual void Draw() const = 0;

private:
    Point center;
};