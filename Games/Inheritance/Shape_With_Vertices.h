#pragma once
#include "Point.h"
#include "Shape.h"
class Shape_With_Vertices : public Shape
{
public:
    // T means top, B means bottom, R means right, L means left
    Shape_With_Vertices(Point center_, unsigned int number_of_vertices_);
    Shape_With_Vertices(Shape_With_Vertices&);
    ~Shape_With_Vertices();
    void SetCenter(float x_, float y_);

protected:
    unsigned int number_of_vertices;
    Point *vertices;
};