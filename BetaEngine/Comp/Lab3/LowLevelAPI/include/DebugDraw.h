//------------------------------------------------------------------------------
//
// File Name:	DebugDraw.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		BetaEngine
// Course:		VGP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "Array.h"

#include "Shapes2D.h"
#include "Color.h"

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Forward References:
//------------------------------------------------------------------------------

namespace Beta
{
	class Vector2D;
	class Mesh;
	class MeshFactory;
	class Camera;

	//------------------------------------------------------------------------------
	// Class Definition:
	//------------------------------------------------------------------------------

	class DebugDraw
	{
	public:
		//------------------------------------------------------------------------------
		// Public Functions
		//------------------------------------------------------------------------------

		// Constructor
		BE_API DebugDraw();

		// Destroy debug draw meshes.
		BE_API ~DebugDraw();

		// Create debug draw meshes
		BE_API void Initialize();

		// Draw all debug objects. Should only be called by existing Low-Level API systems.
		BE_API void Draw();

		// Add a line to the list of lines to be drawn. Note that actual drawing does not occur 
		// unless EndLineList is called.
		// Params:
		//   start = The start point of the line segment.
		//   end   = The end point of the line segment.
		//   color = The color of the line. Defaults to white.
		BE_API void AddLineToList(const Vector2D& start, const Vector2D& end, const Color& color = Colors::White);

		// End the line strip formed using previous calls to AddLineToList.
		// Params:
		//   zDepth = Depth of the object (when using a perspective camera).
		BE_API void EndLineList(float zDepth = 0.0f);

		// Add a circle primitive to the list of circles to be drawn this frame.
		// Params:
		//   center = The center point of the circle.
		//   radius = The radius of the circle.
		//   color  = The color of the circle. Defaults to white.
		//   zDepth = Depth of the object (when using a perspective camera).
		BE_API void AddCircle(const Vector2D& center, float radius,
			const Color& color = Colors::White, float zDepth = 0.0f);

		// Add a rectangle primitive to the list of rectangles to be drawn this frame.
		// Params:
		//   center  = The center point of the rectangle.
		//   extents = The extents (half-width, half-height) of the rectangle.
		//   color   = The color of the circle. Defaults to white.
		//   zDepth = Depth of the object (when using a perspective camera).
		BE_API void AddRectangle(const Vector2D& center, const Vector2D& extents,
			const Color& color = Colors::White, float zDepth = 0.0f);

		// Set the camera used for debug drawing. Any shapes added before the next
		// call to SetCamera will use the provided camera.
		// Params:
		//   camera = The camera used to determine where debug objects will be drawn.
		BE_API void SetCamera(Camera& camera);

		// Enable or disable debug drawing. 
		// Note that debug drawing is only possible in debug mode.
		BE_API void SetEnabled(bool enabled);

		// Return a boolean value that indicates whether debug drawing is enabled.
		BE_API bool IsEnabled() const;

	private:
		//------------------------------------------------------------------------------
		// Private Functions:
		//------------------------------------------------------------------------------

		// Disable copy and assign to prevent accidental copies
		DebugDraw(const DebugDraw&) = delete;
		DebugDraw& operator=(const DebugDraw&) = delete;

		//------------------------------------------------------------------------------
		// Private Structures:
		//------------------------------------------------------------------------------

		struct DebugCircle
		{
			DebugCircle() = default;
			DebugCircle(const Vector2D& center, float radius, const Color& color,
				Camera* camera, float zDepth);

			Circle shape;	// Shape info

			Color color;	// Color for drawing

			Camera* camera;	// Camera to use for drawing

			float zDepth;	// Depth of object (when using perspective camera)
		};

		struct DebugRectangle
		{
			DebugRectangle() = default;
			DebugRectangle(const Vector2D& center, const Vector2D& extents, const Color& color,
				Camera* camera, float zDepth);

			BoundingRectangle shape; // Shape info

			Color color;	// Color for drawing

			Camera* camera; // Camera to use for drawing

			float zDepth;	// Depth of object (when using perspective camera)
		};

		struct DebugLineSegment
		{
			DebugLineSegment() = default;
			DebugLineSegment(const Vector2D& start, const Vector2D& end, const Color& color);

			Vector2D start; // First point of line segment
			Vector2D end;   // Second point of line segment

			Color color;	// Color of the segment
		};

		struct DebugLineList
		{
			DebugLineList() = default;
			DebugLineList(const Array<DebugLineSegment>& segments, Camera* camera, float zDepth);

			Mesh* mesh;     // The mesh used when drawing this line strip
			Camera* camera; // Camera to use for drawing

			float zDepth;	// Depth of object (when using perspective camera)
		};

		//------------------------------------------------------------------------------
		// Private Variables:
		//------------------------------------------------------------------------------

		// Arrays of debug draw objects
		Array<DebugRectangle> rectangles;
		Array<DebugCircle> circles;
		Array<DebugLineList> lineLists;

		// Used when constructing line strips.
		Array<DebugLineSegment> tempLines;

		// Meshes to use for rectangles and circles
		Mesh* circleMesh;
		Mesh* rectangleMesh;

		// Enables/disables debug drawing
		bool enabled;

		// Camera used for debug drawing
		Camera* camera;
	};
}

//------------------------------------------------------------------------------
