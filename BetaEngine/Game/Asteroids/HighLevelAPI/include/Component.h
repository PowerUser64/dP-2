//------------------------------------------------------------------------------
//
// File Name:	Component.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		Project 7
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
#include "Serializable.h"

#include <Array.h>
#include <EngineCore.h>
#include "EventManager.h"

//------------------------------------------------------------------------------

// Easier declarations for DLL import/export
// NOTE: Normally default BetaHighExport.h would be
// sufficient, but the static function definitions in
// the macros below are a bit too weird for the linker.
#ifndef BE_HL_API_COMP
	#ifdef _BE_HL_EXPORT
		#define BE_HL_API_COMP __declspec(dllexport)
	#else
		#define BE_HL_API_COMP
	#endif
#endif

namespace Beta
{
	//------------------------------------------------------------------------------
	// Forward References:
	//------------------------------------------------------------------------------

	class GameObject;
	class Component;
	class Space;
}

//------------------------------------------------------------------------------
// Macros (for RTTI):
//------------------------------------------------------------------------------

// Inspired by the following post, which in turn was inspired by idTech4:
// https://stackoverflow.com/questions/44105058/how-does-unitys-getcomponent-work

// Convert a type to a string
#define TYPE_TO_STRING(x) #x

// Declare a type and overload for IsClassType
// This should be placed in the header (.h/.hpp) file for any subclasses that need RTTI.
#define COMPONENT_SUBCLASS_DECLARATION(subClassType)			\
public:															\
/* Clone function - used to properly copy components */			\
virtual Beta::Component* Clone() const override;				\
/* Check whether component's type matches other type */			\
virtual bool IsOfType(size_t classType) const override;			\
/* Register an event handler with the event manager */			\
void RegisterEventHandler(const Beta::BetaObject* source,		\
	const std::string& eventType,								\
	void (subClassType::*handler)(const Beta::Event&));			\
/* Unregister all event handlers */								\
virtual void UnregisterEventHandlers() override;				\
BE_HL_API_COMP static size_t GetType();							\
private:														\
/* Constant type variable for this component */					\
static const size_t type;										\
/* Array of listeners - used for UnregisterEventHandlers */		\
Beta::Array<Beta::Listener<subClassType>*> listeners;			\
		
// Declare a type and overload for IsClassType
// This should be placed in the header (.h/.hpp) file for any subclasses that need RTTI.
#define COMPONENT_ABSTRACT_DECLARATION(subClassType)		\
public:														\
/* Check whether component's type matches other type */		\
virtual bool IsOfType(size_t classType) const override;		\
BE_HL_API_COMP static size_t GetType();						\
private:													\
/* Constant type variable for this component */				\
static const size_t type;									\

// Clone function for subclasses
#define COMPONENT_SUBCLASS_CLONE_DEFINITION(subClassType)		\
Beta::Component* subClassType::Clone() const					\
{																\
	subClassType* copy = new subClassType(*this);				\
	/* Must have this line to avoid Clone copying listeners */	\
	copy->listeners.Clear();									\
	return copy;												\
}																\
		
// Event handler functions for subclasses
#define COMPONENT_SUBCLASS_EVENT_DEFINITION(subClassType)					\
void subClassType::RegisterEventHandler(const Beta::BetaObject* source,		\
		const std::string& eventType,										\
		void (subClassType::*handler)(const Beta::Event&))					\
{																			\
	Beta::Listener<subClassType>* listener =								\
		new Beta::Listener<subClassType>(source,							\
	eventType, *this, handler);												\
	listeners.PushBack(listener);											\
	Beta::EventManager* em = EngineGetModule(Beta::EventManager);			\
	if (em == nullptr)														\
		return;																\
	em->RegisterEventHandler(*listener);									\
}																			\
																			\
void subClassType::UnregisterEventHandlers()								\
{																			\
	Beta::EventManager* em = EngineGetModule(Beta::EventManager);			\
	if (em == nullptr)														\
		return;																\
																			\
	for(auto it = listeners.Begin(); it != listeners.End(); ++it)			\
	{																		\
		em->UnregisterEventHandler(**it);									\
	}																		\
	listeners.Clear();														\
}																			\

// Define the type and overload for IsClassType (RTTI, no inheritance)
// This should be placed in the source (.cpp) file for any subclasses that need RTTI.
#define COMPONENT_SUBCLASS_DEFINITION(subClassType)							\
const size_t subClassType::type = std::hash<std::string>()(					\
	TYPE_TO_STRING(subClassType));											\
bool subClassType::IsOfType(size_t classType) const							\
{																			\
	return classType == subClassType::GetType();							\
}																			\
size_t subClassType::GetType() { return type; }								\
COMPONENT_SUBCLASS_CLONE_DEFINITION(subClassType)							\
COMPONENT_SUBCLASS_EVENT_DEFINITION(subClassType)							\

// Define the type and overload for IsClassType (RTTI, no inheritance)
// This should be placed in the source (.cpp) file for any subclasses that need RTTI.
#define COMPONENT_ABSTRACT_DEFINITION(subClassType)							\
const size_t subClassType::type = std::hash<std::string>()(					\
	TYPE_TO_STRING(subClassType));											\
bool subClassType::IsOfType(size_t classType) const							\
{																			\
	return classType == subClassType::GetType();							\
}																			\
size_t subClassType::GetType() { return type; }								\

// Define the type and overload for IsClassType (RTTI with single-level inheritance)
// This should be placed in the source (.cpp) file for any subclasses that need RTTI.
#define COMPONENT_SUBCLASS_SUBCLASS_DEFINITION(parentClassType, subClassType)	\
const size_t subClassType::type = std::hash<std::string>()(						\
	TYPE_TO_STRING(subClassType));												\
bool subClassType::IsOfType(size_t classType) const								\
{																				\
	if(classType == subClassType::GetType())									\
	{																			\
		return true;															\
	}																			\
	return parentClassType::IsOfType(classType);								\
}																				\
size_t subClassType::GetType() { return type; }									\
COMPONENT_SUBCLASS_CLONE_DEFINITION(subClassType)								\
COMPONENT_SUBCLASS_EVENT_DEFINITION(subClassType)								\

namespace Beta
{
	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	class Component : public BetaObject, public Serializable
	{
	public:
		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		// Constructor - needed to construct BetaObject.
		BE_HL_API Component(const std::string& name);

		// Retrieve component's owner object (if any).
		BE_HL_API GameObject* GetOwner() const;

		// Get the space that contains this object.
		BE_HL_API Space* GetSpace() const;

		// Clones the component, returning a dynamically allocated copy.
		BE_HL_API virtual Component* Clone() const = 0;

		// Checks whether a component is the same type as another component
		// Params:
		//   componentType - An unsigned int representing the type of the other object.
		BE_HL_API virtual bool IsOfType(size_t classType) const = 0;

		// Unregisters any events that were registered during intialization
		BE_HL_API virtual void UnregisterEventHandlers() = 0;
	};
}

//------------------------------------------------------------------------------
