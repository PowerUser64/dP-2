//------------------------------------------------------------------------------
//
// File Name:	Intersection2D.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		Project 7
// Course:		WANIC VGP2 2018-2019
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "Shapes2D.h"

//------------------------------------------------------------------------------

namespace Beta
{
	//------------------------------------------------------------------------------
	// Forward References:
	//------------------------------------------------------------------------------

	class Transform;
	class RigidBody; 

	namespace Intersection2D
	{
		//------------------------------------------------------------------------------
		// Public Function Declarations:
		//------------------------------------------------------------------------------

		// Check whether a point and rectangle intersect.
		// Params:
		//  point = The point in the intersection.
		//  rect  = The rectangle in the intersection.
		// Returns:
		//   True if intersection, false otherwise.
		BE_HL_API bool PointRectangleIntersection(const Vector2D& point, const BoundingRectangle& rect);

		// Check whether two rectangles intersect.
		// Params:
		//  rect1 = The first rectangle.
		//	rect2 = The second rectangle.
		// Returns:
		//   True if intersection, false otherwise.
		BE_HL_API bool RectangleRectangleIntersection(const BoundingRectangle& rect1, const BoundingRectangle& rect2);

		// Check whether a rectangle and circle intersect.
		// Params:
		//  rect = The rectangle.
		//  circle  = The circle.
		// Returns:
		//   True if intersection, false otherwise.
		BE_HL_API bool RectangleCircleIntersection(const BoundingRectangle& rect, const Circle& circle);

		// Check whether a rectangle and line intersect.
		// Params:
		//  first   = The rectangle.
		//  second  = Start and end of second line segment.
		//  t = T value of intersection (for checking closest intersection).
		// Returns:
		//   True if intersection, false otherwise.
		BE_HL_API bool RectangleLineIntersection(const BoundingRectangle& first, const LineSegment& second, float& t);

		// Check whether two circles intersect.
		// Params:
		//  circle1 = The first circle.
		//  circle2 = The second circle.
		// Returns:
		//   True if intersection, false otherwise.
		BE_HL_API bool CircleCircleIntersection(const Circle& circle1, const Circle& circle2);

		// Check whether a static circle and line intersect.
		// Params:
		//  line   = Start and end of first line segment.
		//  circle = Start and end of second line segment (can be moving point or circle).
		//  t = T value of intersection (for checking closest intersection).
		// Returns:
		//   True if intersection, false otherwise.
		BE_HL_API bool StaticCircleLineIntersection(const LineSegment& line, const Circle& circle, float& t);

		// Check whether a moving point and line intersect.
		// Params:
		//  staticLine   = Start and end of first line segment.
		//  movingCircle = Start and end of second line segment (can be moving point or circle).
		//  radius		 = Radius of the circle. (Use 0 for points.)
		//  intersection = Intersection point, if any.
		//  t = T value of intersection (for checking closest intersection).
		// Returns:
		//   True if intersection, false otherwise.
		BE_HL_API bool MovingCircleLineIntersection(const LineSegment& staticLine, const LineSegment& movingCircle,
			float radius, Vector2D& intersection, float& t);

		// Modifies object's position, velocity, and rotation using simple point-line reflection.
		// Params:
		//  transform = Transform of the object that is being reflected.
		//  physics   = Physics of the object being reflected.
		//  staticLine   = Start and end of first line segment.
		//  movingCircle = Start and end of second line segment (can be moving point or circle).
		//  radius		 = Radius of the circle. (Use 0 for points.)
		//  intersection = Intersection point of the line and circle. 
		BE_HL_API void MovingCircleLineReflection(Transform& transform, RigidBody& physics, const LineSegment& staticLine,
			const LineSegment& movingCircle, float radius, const Vector2D& intersection);

		// Check whether two line segments intersect.
		// Params:
		//  first   = Start and end of first line segment.
		//  second  = Start and end of second line segment.
		//  intersection = Intersection point, if any.
		//  t = T value of intersection (for checking closest intersection).
		// Returns:
		//   True if intersection, false otherwise.
		BE_HL_API bool LineLineIntersection(const LineSegment& first, const LineSegment& second, Vector2D& intersection, float& t);
	}
}

//------------------------------------------------------------------------------
