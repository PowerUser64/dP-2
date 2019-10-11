////////////////////////////////////////////////////////////////////////////////
#ifndef VECTOR2D_H
#define VECTOR2D_H
////////////////////////////////////////////////////////////////////////////////

#include <iostream> // istream, ostream

namespace CS170
{
class Vector2D
{
public:
	// Constructors (2)
	Vector2D(float x, float y);
	Vector2D();

	// Accessors (2)
	float X() const;
	float Y() const;

	// Mutators (2)
	void X(float num);
	void Y(float num);

	// Other functions (7)
	float Magnitude();
	float MagnitudeSquared();
	Vector2D Normalized();

	float Distance(Vector2D &source);
	float DistanceSquared(Vector2D &source);

	Vector2D Midpoint(Vector2D &source);
	float DotProduct(Vector2D &source);

	// Overloaded operators (9 member functions)
	Vector2D operator+(const Vector2D &source);
	Vector2D operator-(const Vector2D &source);
	Vector2D operator*(const Vector2D &source);
	Vector2D operator*(const float &source);
	Vector2D operator/(const Vector2D &source);
	Vector2D operator/(const float &source);

private:
	float x; // The x-coordinate of a Vector2D
	float y; // The y-coordinate of a Vector2D
};

// Overloaded operators (2 non-member, non-friend functions)
std::ostream &operator<<(std::ostream &os, const Vector2D &source);
Vector2D operator*(const float &floating, Vector2D &source);
} // namespace CS170

#endif
////////////////////////////////////////////////////////////////////////////////
