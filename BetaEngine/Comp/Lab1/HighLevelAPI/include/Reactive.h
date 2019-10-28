//------------------------------------------------------------------------------
//
// File Name:	Reactive.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		BetaFramework
// Course:		WANIC VGP2 2018-2019
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "Component.h"

//------------------------------------------------------------------------------

namespace Beta
{
	//------------------------------------------------------------------------------
	// Forward References:
	//------------------------------------------------------------------------------

	class GameObject;
	class Vector2D;

	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	typedef void(*MouseEventHandler)(GameObject& gameObject1);

	class Reactive : public Component
	{
	public:
		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		// Allocate a new Reactive component.
		BE_HL_API Reactive();

		// Check if the mouse is currently intersecting with this object.
		BE_HL_API void Update(float dt);

		// Obtains the mouse's position in world coordinates.
		// Returns:
		//   The position of the mouse as a vector.
		BE_HL_API Vector2D GetMouseWorldPosition() const;

		// Save object data to file.
		// Params:
		//   stream = The stream object used to save the object's data.
		BE_HL_API void Serialize(FileStream& stream) const;

		// Load object data from file
		// Params:
		//   stream = The stream object used to load the object's data.
		BE_HL_API void Deserialize(FileStream& stream);

	private:
		//------------------------------------------------------------------------------
		// Private Variables:
		//------------------------------------------------------------------------------

		// Whether the mouse button is currently down.
		bool mouseIsDown;

		// Whether the mouse is currently over the object.
		bool mouseIsOver;

		// RTTI
		COMPONENT_SUBCLASS_DECLARATION(Reactive)
	};
}

//------------------------------------------------------------------------------
