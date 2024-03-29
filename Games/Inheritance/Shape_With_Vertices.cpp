#include "Shape_With_Vertices.h"
Shape_With_Vertices::Shape_With_Vertices(Point center_, unsigned int number_of_vertices_) : Shape(center_)
{
    vertices = new Point[number_of_vertices_];
    number_of_vertices = number_of_vertices_;
    // translate old points by where the new and old centers are
}
Shape_With_Vertices::Shape_With_Vertices(Shape_With_Vertices &from) : Shape(GetCenter())
{
    number_of_vertices = from.number_of_vertices;
    vertices = new Point[number_of_vertices];
    for (size_t i = 0; i < number_of_vertices; ++i)
        vertices[i] = from.vertices[i];
}
Shape_With_Vertices::~Shape_With_Vertices()
{
    delete[] vertices;
}
void Shape_With_Vertices::SetCenter(float x_, float y_)
{
    Shape::SetCenter(x_, y_);
}