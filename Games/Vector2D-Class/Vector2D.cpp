#include "Vector2D.h" // Vector2D members
#include <cmath>      // sqrt, atan, sin, cos

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
// Vector2D Midpoint(&source)
// {
//   return 
// }
    // Operators (9)
std::ostream &operator<<(std::ostream &os, const Vector2D &source)
{
  os << '('<< source.X() << ',' << source.Y() << ')';
  return os;
}

  ///////////////////////////////////////////////////////////////////////////////
  // 2 non-member, non-friend functions (operators)

} // namespace CS170
