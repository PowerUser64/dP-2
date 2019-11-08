//------------------------------------------------------------------------------
//
// File Name:	Space.h
// Author(s):	Jeremy Kings
// Project:		BetaEngine
// Course:		CS230
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include <GameObjectManager.h>	// composition
#include <ResourceManager.h>	// composition
#include <BetaObject.h> // inheritance
#include <Camera.h>		// Reset

//------------------------------------------------------------------------------

namespace Beta
{
	//------------------------------------------------------------------------------
	// Forward Declarations:
	//------------------------------------------------------------------------------

	class Level;

	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	class Space : public BetaObject
	{
	public:
		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		// Constructor(s)
		BE_HL_API Space(const std::string& name, bool customCamera = false);

		// Destructor
		BE_HL_API ~Space();

		// Updates the level and object manager.
		BE_HL_API void Update(float dt) override;

		// Draw the level and object manager.
		BE_HL_API void Draw() override;

		// Shuts down the object manager
		BE_HL_API void Shutdown() override;

		// Returns a boolean indicating whether objects in this space are paused.
		BE_HL_API bool IsPaused() const;

		// Returns the name of the level currently running in this space.
		BE_HL_API std::string GetLevelName() const;

		// Returns the object manager, which you can use to retrieve and add objects.
		BE_HL_API GameObjectManager& GetObjectManager();

		// Pauses the space, preventing objects from being updated, but objects are still drawn.
		BE_HL_API void SetPaused(bool value);

		// Sets the level that the space is using after unloading the current level.
		template <class LevelType>
		void SetLevel()
		{
			if (currentLevel != nullptr && typeid(LevelType) == typeid(*currentLevel))
			{
				RestartLevel();
			}
			else
			{
				nextLevel = new LevelType();
				nextLevel->SetOwner(this);
				// Reset camera
				GetCamera().Reset();
			}
		}

		// Restarts the current level (next level = current)
		BE_HL_API void RestartLevel();

		// Checks whether space should be destroyed
		BE_HL_API bool IsDestroyed() const;

		// Marks the space for destruction
		BE_HL_API void Destroy();

		// Get the camera used by this space.
		BE_HL_API Camera& GetCamera() const;

	private:
		//------------------------------------------------------------------------------
		// Private Functions:
		//------------------------------------------------------------------------------

		// Disable copy and assign to prevent accidental copies
		Space(const Space&) = delete;
		Space& operator=(const Space&) = delete;

		// Updates current/next level pointers and calls shutdown/unload/load/init
		void ChangeLevel();

		//------------------------------------------------------------------------------
		// Private Variables:
		//------------------------------------------------------------------------------

		bool paused;
		BetaObject* currentLevel;
		BetaObject* nextLevel;
		GameObjectManager objectManager;
		bool isDestroyed;
		Camera* camera;
		bool customCamera;
	};
}

//------------------------------------------------------------------------------
