#include "Circle.h"

Circle::Circle(Point center_, unsigned int radius_) : Shape(center_)
{
    radius = radius_, SetCenter(center_.x, center_.y);
}
Circle::~Circle()
{
}
void Circle::Draw() const
{
    std::cout << "Drawing a circle at x = " << GetCenter().x << " y = " << GetCenter().y << " and radius " << radius << std::endl              << std::endl;
}
