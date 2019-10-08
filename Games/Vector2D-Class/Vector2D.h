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
	void X(float num);
	void Y(float num);

	// Mutators (2)

	// Other functions (7)

	// Overloaded operators (9 member functions)

private:
	float x; // The x-coordinate of a Vector2D
	float y; // The y-coordinate of a Vector2D
};

// Overloaded operators (2 non-member, non-friend functions)
std::ostream &operator<<(std::ostream &os, const Vector2D &source);

} // namespace CS170

#endif
////////////////////////////////////////////////////////////////////////////////
