#include "Point.h"

/*
 * Circle(Point center_, unsigned int radius_);
 * Properties: unsigned int radius
 */
class Circle : public Shape
{
public:
    Circle::Circle(Point center_, unsigned int radius_);

private:
    unsigned int radius;
};