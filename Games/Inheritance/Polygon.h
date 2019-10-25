#pragma once
#include "Point.h"
#include "Shape.h"
#include "Shape_With_Vertices.h"
class Polygon : public Shape_With_Vertices
{
public:
    Polygon(Point center_, unsigned int number_of_vertices_);
    Polygon(Point center_, const Point *points_, unsigned int number_of_vertices_);
    void SetVertex(unsigned int vertexIdx_, float x_, float y_);
    void Draw() const;

        private:
};