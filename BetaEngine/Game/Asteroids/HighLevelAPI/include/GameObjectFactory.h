//------------------------------------------------------------------------------
//
// File Name:	GameObjectFactory.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		BetaFramework
// Course:		CS230
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include <BetaObject.h>
#include <cassert>
//#include <Array.h>

//------------------------------------------------------------------------------

namespace Beta
{
	//------------------------------------------------------------------------------
	// Forward References:
	//------------------------------------------------------------------------------

	class Space;
	class GameObject;
	class Component;

	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	class GameObjectFactory : public BetaObject
	{
	public:
		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		// Register core components
		BE_HL_API GameObjectFactory();

		// Delete all registered components
		BE_HL_API ~GameObjectFactory();

		// Create a single instance of the specified game object.
		// Loads the object from a text file (if it exists).
		// Params:
		//   name = The name of the object.
		//   ignoreUnregisteredComponents = Whether to return the object even if it contains unregistered components.
		// Returns:
		//	 If the object file exists and can be loaded, then return a pointer to a new instance 
		//    of the specified game object type, else nullptr.
		BE_HL_API GameObject* CreateObject(const std::string& name, bool ignoreUnregisteredComponents = false);

		// Create a single instance of the specified component.
		// Params:
		//   name = The name of the component.
		// Returns:
		//	 If the component exists, then return a pointer to a new instance 
		//    of the specified component, else nullptr.
		BE_HL_API Component* CreateComponent(const std::string& componentName);

		// Saves an object to an archetype file so it can be loaded later.
		// Params:
		//   object = The object being saved to a file. Filename is based on object name.
		BE_HL_API void SaveObjectToFile(const GameObject* object);

		// Register a component so it can be created on the fly.
		// Template parameters:
		//   ComponentType = The type of the component to be registered.
		template <class ComponentType>
		void RegisterComponent()
		{
			Component* component = new ComponentType();
			assert(registeredComponents.find(component->GetName()) == registeredComponents.end());
			registeredComponents.emplace(component->GetName(), component);
		}

	private:
		//------------------------------------------------------------------------------
		// Private Functions:
		//------------------------------------------------------------------------------

		// Disable copy and assign to prevent accidental copies
		GameObjectFactory(const GameObjectFactory&) = delete;
		GameObjectFactory& operator=(const GameObjectFactory&) = delete;

		//------------------------------------------------------------------------------
		// Private Variables:
		//------------------------------------------------------------------------------

		// Contains all components used by objects.
		std::unordered_map<std::string, Component*> registeredComponents;

		// Subdirectory for object archetype files
		static const std::string objectFilePath;
	};
}

//------------------------------------------------------------------------------
