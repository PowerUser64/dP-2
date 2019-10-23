#include "Point.h"
class Shape
{
public:
    Shape(Point center_);
    ~Shape();
    Point GetCenter();
    void SetCenter(float x_, float y_);
    void Draw();
private:
    Point center;
};