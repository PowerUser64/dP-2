#pragma once
#include "Point.h"
#include "Shape.h"
/*
 * Circle(Point center_, unsigned int radius_);
 * Properties: unsigned int radius
 */
class Circle : public Shape
{
public:
    Circle(Point center_, unsigned int radius_);
    ~Circle();
    void Draw() const;

private:
    unsigned int radius;
};