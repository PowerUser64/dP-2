//------------------------------------------------------------------------------
//
// File Name:	GameObject.h
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

#include <BetaObject.h>

#include <Array.h>				// Array of components
#include "Component.h"			// Array of components
#include "ResourceManager.h"	// Archetype manager

//------------------------------------------------------------------------------

namespace Beta
{
	//------------------------------------------------------------------------------
	// Forward References:
	//------------------------------------------------------------------------------

	class Space;
	class GameObject;
	typedef std::shared_ptr<const GameObject> Archetype;

	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	class ArchetypeManager : public ResourceManager<const GameObject>
	{
	public:
		BE_HL_API ArchetypeManager();
	private:
		Archetype Create(const std::string& name) override;
	};

	class GameObject : public BetaObject, public Serializable
	{
	public:
		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		// Create a new game object.
		// Params:
		//	 name = The name of the game object being created.
		BE_HL_API GameObject(const std::string& name);

		// Copy a game object from another object. Explicit to prevent accidental copies.
		// Params:
		//	 other = A reference to the object being cloned.
		BE_HL_API explicit GameObject(const GameObject& other);

		// Copy a game object from an archetype. Explicit to prevent accidental copies.
		// Params:
		//	 archetype = A pointer to the object being cloned.
		BE_HL_API explicit GameObject(Archetype archetype);

		// Free the memory associated with a game object.
		BE_HL_API ~GameObject();
			
		// Adds a component to the object.
		BE_HL_API void AddComponent(Component* component);

		// Retrieves the component with the given type if it exists.
		template<typename ComponentType>
		ComponentType* GetComponent()
		{
			size_t numComponents = components.Size();

			for (size_t i = 0; i < numComponents; ++i)
			{
				if (components[i]->IsOfType(ComponentType::GetType()))
					return static_cast<ComponentType*>(components[i]);
			}

			return nullptr;
		}

		// Initialize this object's components and set it to active.
		BE_HL_API void Initialize() override;

		// Whether the object has been marked for destruction.
		// Returns:
		//		True if the object will be destroyed, false otherwise.
		BE_HL_API bool IsDestroyed() const;

		// Update any components attached to the game object.
		// Params:
		//	 dt = Change in time (in seconds) since the last game loop.
		BE_HL_API void Update(float dt) override;

		// Updates components using a fixed timestep (usually just physics)
		// Params:
		//	 dt = A fixed change in time, usually 1/60th of a second.
		BE_HL_API void FixedUpdate(float dt) override;

		// Draw any visible components attached to the game object.
		BE_HL_API void Draw() override;

		// Mark an object for destruction.
		BE_HL_API void Destroy();

		// Tells whether an object will be updated.
		BE_HL_API bool IsActive() const;

		// Sets whether an object will be updated.
		BE_HL_API void SetActive(bool value);

		// Get the space that contains this object.
		BE_HL_API Space* GetSpace() const;

		// Save object data to file.
		// Params:
		//   stream = The stream object used to save the object's data.
		BE_HL_API void Serialize(FileStream& stream) const;

		// Load object data from file
		// Params:
		//   stream = The stream object used to load the object's data.
		BE_HL_API void Deserialize(FileStream& stream);

		// Use this to manage game object archetype resources!
		BE_HL_API static ArchetypeManager& GetArchetypeManager();

	private:
		//------------------------------------------------------------------------------
		// Private Functions:
		//------------------------------------------------------------------------------

		// Deleted to prevent accidental copies of objects.
		GameObject& operator=(const GameObject& rhs) = delete;

		//------------------------------------------------------------------------------
		// Private Variables:
		//------------------------------------------------------------------------------

		// Array of components
		Array<Component*> components;

		// Whether or not the object should be updated and drawn.
		bool active;

		// Whether the object has been marked for destruction.
		bool isDestroyed;

		// Archetype on which this object is based (if any)
		Archetype baseArchetype;

		static ArchetypeManager archetypeManager;
	};

	#define ResourceGetArchetype(a) GameObject::GetArchetypeManager().GetResource(a)
}

//------------------------------------------------------------------------------
