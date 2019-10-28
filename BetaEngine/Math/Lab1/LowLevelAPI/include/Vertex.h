//------------------------------------------------------------------------------
//
// File Name:	Vertex.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		Beta Engine
// Course:		WANIC VGP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "Vector2D.h"
#include "Color.h"

//------------------------------------------------------------------------------

namespace Beta
{
	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	struct BE_API Vertex
	{
		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		Vertex();
		Vertex(const Vector2D& position, const Color& color); // Colored vertex 2D
		Vertex(const Vector2D& position, const Vector2D& textureCoords); // Textured vertex 2D
		Vertex(const Vector2D& position, const Color& color, const Vector2D& textureCoords); // Complete vertex 2D

		//------------------------------------------------------------------------------
		// Public Variables:
		//------------------------------------------------------------------------------

		Vector2D position;
		Color color;
		Vector2D textureCoords;
	};
}

//------------------------------------------------------------------------------
