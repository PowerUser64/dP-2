#include "Point.h"
#include "Shape.h"
#include "Shape_With_VerticesClass.h"
class Rectangle : public Shape_With_Vertices
{
public:
    Rectangle::Rectangle(Point center_, unsigned int width_, unsigned int height_);

private:
    unsigned int width;
    unsigned int height;
};