//------------------------------------------------------------------------------
//
// File Name:	BetaObject.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		BetaFramework
// Course:		WANIC VGP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include <unordered_map> // unordered_map
#include <type_traits>   // alignment_of

//------------------------------------------------------------------------------

namespace Beta
{
	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	// This class provides a common interface for things like engine systems,
	// levels/game states, game objects, and components. It is an abstract 
	// class, so while objects of this class are illegal, game systems and objects 
	// should almost always inherit from this class or one of its subclasses.
	class BetaObject
	{
	public:
		//------------------------------------------------------------------------------
		// Public Typedefs:
		//------------------------------------------------------------------------------

		// Type for object IDs. 32 bit unsigned int allows for 4,294,967,296 objects
		// over the course of the lifetime of the program.
		typedef unsigned IDType;
		typedef std::unordered_map<IDType, BetaObject*> ObjectList;

		//------------------------------------------------------------------------------
		// Constructors and Destructors:
		//------------------------------------------------------------------------------

		// Constructor
		// Params:
		//   name = The name of this object.
		//   owner = The owner object to this beta object (defaults to no owner).
		BE_API BetaObject(const std::string& name, BetaObject* owner = nullptr);

		// Copy constructor
		BE_API BetaObject(const BetaObject& other);

		// Assignment operator
		BE_API BetaObject& operator=(const BetaObject& other);

		// Destructor
		// This function is virtual to ensure destruction works properly
		// with inherited classes. It is PURE virtual (= 0) to force the class to
		// be abstract without forcing the user to implement any functions.
		BE_API virtual ~BetaObject() = 0;

		//------------------------------------------------------------------------------
		// Game Loop Functions:
		//------------------------------------------------------------------------------

		// Loads external resources associated with this object. 
		// Occurs when a level starts for the first time.
		BE_API virtual void Load();

		// Resets instance data and reinstantiates child objects. 
		// Occurs when a level is loaded or restarted.
		BE_API virtual void Initialize();

		// Executes all operations that should occur every frame.
		// Params:
		//   dt = The change in time between last frame and the current frame.
		BE_API virtual void Update(float dt);

		// Updates components using a fixed timestep (usually just for physics).
		// Params:
		//	 dt = A fixed change in time, usually 1/60th of a second.
		BE_API virtual void FixedUpdate(float dt);

		// Draw this object. Could be a sprite, text, or debug visuals.
		BE_API virtual void Draw();

		// Removes any objects that will be recreated in Initialize.
		BE_API virtual void Shutdown();

		// Unloads external assets associated with this object. 
		// Occurs when changing levels.
		BE_API virtual void Unload();

		//------------------------------------------------------------------------------
		// Other Public Functions:
		//------------------------------------------------------------------------------

		// Returns the name of the object.
		BE_API const std::string& GetName() const;

		// Give the object a new name - use with caution!
		BE_API void SetName(const std::string& name);

		// Returns the globally unique id of the object.
		BE_API const IDType GetID() const;

		// Retrieve the object that contains this object.
		BE_API BetaObject* GetOwner() const;

		// Set the object that owns or contains this object.
		// Params:
		//   object - A pointer to the object that owns this object.
		BE_API void SetOwner(BetaObject* object);

		// Returns a pointer to an object with the given ID, if it exists.
		// Returns nullptr if the object does not exist (was destroyed).
		// Params:
		//   id - The ID of the object that should be retrieved.
		BE_API static BetaObject* GetObjectByID(IDType id);

	private:
		//------------------------------------------------------------------------------
		// Private Functions:
		//------------------------------------------------------------------------------

		// Generate an identifier for the object.
		void GenerateID();

		// Retrieve the master object list
		static ObjectList& GetObjectList();

		//------------------------------------------------------------------------------
		// Private Data:
		//------------------------------------------------------------------------------

		// Name of the object.
		std::string name;

		// ID of the object
		IDType id;

		// Object that contains this object.
		BetaObject* owner;
	};
}

//------------------------------------------------------------------------------
