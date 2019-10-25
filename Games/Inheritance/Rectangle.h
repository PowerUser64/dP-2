#pragma once
#include "Point.h"
#include "Shape.h"
#include "Shape_With_Vertices.h"
class Rectangle : public Shape_With_Vertices
{
public:
    Rectangle(Point center_, unsigned int width_, unsigned int height_);
    void Draw() const;

private:
    unsigned int width;
    unsigned int height;
};