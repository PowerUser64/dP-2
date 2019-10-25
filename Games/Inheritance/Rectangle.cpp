#include "Rectangle.h"

Rectangle::Rectangle(Point center_, unsigned int width_, unsigned int height_) : Shape_With_Vertices(center_, 4)
{
    width = width_, height = height_;
    vertices[0] = Point(center_.x - (width / 2.0f), center_.y + (height / 2.0f));
    vertices[1] = Point(center_.x + (width / 2.0f), center_.y + (height / 2.0f));
    vertices[2] = Point(center_.x - (width / 2.0f), center_.y - (height / 2.0f));
    vertices[3] = Point(center_.x + (width / 2.0f), center_.y - (height / 2.0f));
}
void Rectangle::Draw() const
{
    std::cout << "Drawing rectangle" << std::endl;
    for (unsigned int i = 0; i < number_of_vertices; ++i)
        std::cout << "Vertex " << i << " (" << vertices[i].x << ", " << vertices[i].y << ')' << std::endl;
}