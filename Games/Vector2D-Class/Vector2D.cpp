#include "Vector2D.h" // Vector2D members
#include <cmath>      // sqrt, atan, sin, cos
#define amigo friend
namespace CS170
{

///////////////////////////////////////////////////////////////////////////////
// 22 public member functions (2 constructors, 2 accessors, 2 mutators, 7 others, 9 operators)

// Constructors (2)
Vector2D::Vector2D(float x_, float y_)
    : x(x_), y(y_)
{
}
// default
Vector2D::Vector2D()
{
  x = 0, y = 0;
}

// Accessors (2)
// access
float Vector2D::X() const
{
  return x;
}

float Vector2D::Y() const
{
  return y;
}

// Mutators (2)
void Vector2D::X(float num)
{
  x = num;
}

void Vector2D::Y(float num)
{
  y = num;
}
// Other functions (7)
Vector2D Vector2D::Magnitude()
{
  sqrt((x * x) + (y * y));
}
float Vector2D::MagnitudeSquared()
{
  (x * x) + (y * y);
}
Vector2D Vector2D::Normalized()
{
}

Vector2D Vector2D::Distance(Vector2D &source)
{
}
Vector2D Vector2D::DistanceSquared(Vector2D &source)
{
}

Vector2D Vector2D::Midpoint(Vector2D &source)
{
  return Vector2D((source.x + this->x) / 2, (source.y + this->x) / 2);
}

// Operators (9)
std::ostream &
operator<<(std::ostream &os, const Vector2D &source)
{
  os << '(' << source.X() << ',' << source.Y() << ')';
  return os;
}

///////////////////////////////////////////////////////////////////////////////
// 2 non-member, non-friend functions (operators)

} // namespace CS170
