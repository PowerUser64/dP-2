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
float Vector2D::Magnitude()
{
  return sqrt((x * x) + (y * y));
}
float Vector2D::MagnitudeSquared()
{
  return (x * x) + (y * y);
}
Vector2D Vector2D::Normalized()
{
  return Vector2D(x / Magnitude(), y / Magnitude());
}

float Vector2D::Distance(Vector2D &var)
{
  return sqrt(((var.x - x) * (var.x - x)) + ((var.y - y) * (var.y - y)));
}
float Vector2D::DistanceSquared(Vector2D &var)
{
  return ((var.x - x) * (var.x - x)) + ((var.y - y) * (var.y - y));
}

Vector2D Vector2D::Midpoint(Vector2D &var)
{
  return Vector2D((var.x + this->x) / 2, (var.y + this->y) / 2);
}
float Vector2D::DotProduct(Vector2D &var)
{
  return (var.x * x) + (var.y * y);
}

// Operators (9)
Vector2D Vector2D::operator+(const Vector2D &var)
{
  return Vector2D(x + var.x, y + var.y);
}
Vector2D Vector2D::operator-(const Vector2D &var)
{
  return Vector2D(x - var.x, y - var.y);
}

Vector2D Vector2D::operator*(const float &var)
{
  return Vector2D(var * x, var * y);
}

Vector2D Vector2D::operator/(const float &var)
{
  return Vector2D(x / var, y / var);
}
/* 
 */
Vector2D Vector2D::operator+=(const Vector2D &var)
{
  x += var.x;
  y += var.y;
  return *this;
}
Vector2D Vector2D::operator-=(const Vector2D &var)
{
  x -= var.x;
  y -= var.y;
  return *this;
}
Vector2D Vector2D::operator*=(const Vector2D &var)
{
  x *= var.x;
  y *= var.y;
  return *this;
}
Vector2D Vector2D::operator*=(const float &var)
{
  x *= var.x;
  y *= var.y;
  return *this;
}
Vector2D Vector2D::operator/=(const Vector2D &var)
{
  x += var.x;
  y += var.y;
  return *this;
}
Vector2D Vector2D::operator/=(const float &var)
{
  x += var.x;
  y += var.y;
  return *this;
}

///////////////////////////////////////////////////////////////////////////////
// 2 non-member, non-friend functions (operators)
std::ostream &operator<<(std::ostream &os, const Vector2D &var)
{
  os << '(' << var.X() << ", " << var.Y() << ')';
  return os;
}

Vector2D operator*(const float &floating, Vector2D &var)
{
  return Vector2D(floating * var.X(), floating * var.Y());
}

} // namespace CS170
