#include "Shape.h"
/* 
 * Description:
 * Abstract class that serves as the parent of all shapes.
 * In it you will find all properties and methods that belong in all shapes (Center, Draw, etc...)
 * 
 * Methods:
 * Shape(Point center_);
 * ~Shape();
 * Point GetCenter();
 * void SetCenter(float x_, float y_);
 * void Draw();
 * 
 * Properties
 * Point center;
 */

Shape::Shape(Point center_)
{
    Point center = Point();
}

Shape::~Shape()
{
}

Point Shape::GetCenter()
{
    return center;
}

void Shape::SetCenter(float x_, float y_)
{
    center.x = x_, center.y = y_;
}