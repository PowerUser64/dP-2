//------------------------------------------------------------------------------
//
// File Name:	EngineCore.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		BetaFramework
// Course:		WANIC VGP2 2018-2019
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Includes:
//------------------------------------------------------------------------------

#include "BetaObject.h"

#include <typeindex> // Comparing module types
#include "Array.h" // Array of modules
#include "StartupSettings.h"

//------------------------------------------------------------------------------

// Helper for easy retrieval of system modules
#define EngineGetModule(type) Beta::EngineCore::GetInstance().GetModule<type>()

namespace Beta
{
	//------------------------------------------------------------------------------
	// Forward Declarations:
	//------------------------------------------------------------------------------

	// Windows
	class Input;
	class WindowSystem;
	class DebugDraw;
	class GraphicsEngine;
	class MeshFactory;

	class FrameRateController;

	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	class EngineCore : public BetaObject
	{
	public:
		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		// Start the game loop and runs until quit state is reached.
		// Params:
		//   settings = The settings to use when starting the application.
		BE_API void Start(const StartupSettings& settings = StartupSettings());

		// Stops the engine and shuts everything down
		BE_API void Stop();

		// Add an additional module to the engine, which will be updated.
		// Params:
		//   ModuleType = A template parameter that specifies the class type 
		//      of the module being added to the engine.
		// Return:
		//   A pointer to the module that was added to the engine. 
		template<class ModuleType>
		ModuleType* AddModule()
		{
			ModuleType* module = new ModuleType();
			module->SetOwner(this);
			moduleMap.emplace(typeid(ModuleType), module);
			moduleList.PushBack(module);
			return module;
		}

		// Retrieve the module with the given type if it exists.
		// Params:
		//   ModuleType = A template parameter that specifies the class type 
		//      of the module being retrieved.
		// Return:
		//   A pointer to the specified module.
		template<class ModuleType>
		ModuleType* GetModule()
		{
			auto location = moduleMap.find(typeid(ModuleType));
			if (location != moduleMap.end())
				return static_cast<ModuleType*>(location->second);

			return nullptr;
		}

		// Getters for standard modules
		template<> DebugDraw* GetModule<DebugDraw>() { return debugDraw; }
		template<> FrameRateController* GetModule<FrameRateController>() { return frameRateController; }
		template<> GraphicsEngine* GetModule<GraphicsEngine>() { return graphics; }
		template<> Input* GetModule<Input>() { return input; }
		template<> MeshFactory* GetModule<MeshFactory>() { return meshFactory; }
		template<> WindowSystem* GetModule<WindowSystem>() { return system; }

		// Returns the path that contains all assets
		BE_API const std::string& GetFilePath() const;

		// Set the path used for assets
		// Params:
		//   directory = The relative path to the master assets directory. Textures, 
		//      objects, shaders, and sound files should be placed in subdirectories within this directory.
		BE_API void SetFilePath(const std::string & directory = "Assets/");

		// Return true if the engine is set to close when escape is pressed.
		BE_API bool DoesCloseOnEscape() const;

		// Set whether pressing the escape key will close the program.
		BE_API void SetCloseOnEscape(bool closeOnEscape);

		// Return true if the engine is currently running, false otherwise.
		BE_API bool IsRunning() const;

		// Return the single instance of the EngineCore class
		BE_API static EngineCore & GetInstance();

	private:
		//------------------------------------------------------------------------------
		// Private Function Declarations:
		//------------------------------------------------------------------------------

		// Constructor/destructor private to prevent accidental instantiation/destruction.
		EngineCore();
		~EngineCore();

		// Disable copy constructor and assignment operator
		EngineCore(const EngineCore&) = delete;
		EngineCore & operator=(const EngineCore&) = delete;

		// Initialize custom modules.
		void Initialize() override;

		// Update all engine modules.
		// Params:
		//	 dt = Change in time (in seconds) since the last game loop.
		void Update(float dt) override;

		// Shutdown custom modules.
		void Shutdown() override;

		//------------------------------------------------------------------------------
		// Private Variables:
		//------------------------------------------------------------------------------

		// Is the engine currently running?
		bool isRunning;

		// Pointers to additional engine modules
		typedef std::map<std::type_index, BetaObject*> ModuleMap;
		ModuleMap moduleMap; // For retrieval
		typedef Array<BetaObject*> ModuleList;
		ModuleList moduleList; // For iterating

		// Assets directory
		std::string assetsPath;

		// Should the program stop when escape is pressed?
		bool closeOnEscape;

		// Standard modules - Declaration order here
		// in class specifies ideal order of initialization.
		WindowSystem* system;
		Input* input;
		GraphicsEngine* graphics;
		MeshFactory* meshFactory;
		DebugDraw* debugDraw;
		FrameRateController* frameRateController;
	};
}

//------------------------------------------------------------------------------
