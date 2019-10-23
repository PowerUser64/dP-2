#include "Point.h"
class Shape
{
public:
    Shape(Point center_);
    ~Shape();
    Point GetCenter();
    void SetCenter(float x_, float y_);
    virtual void Shape::Draw() = 0;
private:
    Point center;
};