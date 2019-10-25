#include "Polygon.h"

Polygon::Polygon(Point center_, unsigned int number_of_vertices_) : Shape_With_Vertices(center_, number_of_vertices_)
{
    
}
Polygon::Polygon(Point center_, const Point *points_, unsigned int number_of_vertices_) : Shape_With_Vertices(center_, number_of_vertices_)
{
    for (int i = 0; i < number_of_vertices_; ++i)
        vertices[i] = points_[i];
}
void Polygon::SetVertex(unsigned int vertexIdx_, float x_, float y_)
{
}

void Polygon::Draw() const
{
    std::cout << "Drawing a polygon at x = " << GetCenter().x << " y = " << GetCenter().y << std::endl;
    for(int i = 0; i < number_of_vertices; ++i)
        std::cout << "Vertex " << i << " (" << GetCenter().x << ", " << GetCenter().y << ')' << std::endl;
}