//------------------------------------------------------------------------------
//
// File Name:	SoundManager.h
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

#include "BetaObject.h"

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Forward References:
//------------------------------------------------------------------------------

// Undefining Windows macro 
#ifdef PlaySound
#undef PlaySound
#endif

namespace Beta
{
	class SoundEvent;
	typedef std::shared_ptr<SoundEvent> SoundEventPtr;

	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	class SoundManager : public BetaObject
	{
	public:
		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		// Constructor - initializes FMOD.
		BE_HL_API SoundManager();

		// Destructor
		BE_HL_API ~SoundManager();

		// Update the FMOD system.
		// Params:
		//	 dt = Change in time (in seconds) since the last game loop.
		BE_HL_API void Update(float dt);

		// Shutdown the sound manager.
		BE_HL_API void Shutdown(void);

		// Creates a non-looping FMOD sound.
		// Params:
		//	 filename = Name of the sound file (WAV).
		BE_HL_API void AddEffect(const std::string& filename);

		// Creates an FMOD stream for a music file.
		// Params:
		//	 filename = Name of the music file (MP3).
		BE_HL_API void AddMusic(const std::string& filename);

		// Creates an FMOD sound bank
		// Params:
		//   filename = Name of the FMOD bank file.
		BE_HL_API void AddBank(const std::string& filename);

		// Unloads a sound file from memory.
		BE_HL_API void RemoveSound(const std::string& filename);

		// Plays a sound with the specified name.
		// Params:
		//	 name = The name of the sound to be played.
		BE_HL_API void PlaySound(const std::string& name);

		// Starts an audio event with the given name.
		// The event must be in one of the loaded banks.
		// Params:
		//	 eventName = The name of the event that will be started.
		BE_HL_API SoundEventPtr PlayEvent(const std::string& eventName);

		// Set the volume of the music channel.
		// Params:
		//	 volume = New value for the music volume (0.0 to 1.0).
		BE_HL_API void SetMusicVolume(float volume);

		// Set the volume of the sound effects channel group.
		// Params:
		//	 volume = New value for the FX volume (0.0 to 1.0).
		BE_HL_API void SetEffectsVolume(float volume);

		// Get the volume of the music channel.
		// Return:
		//	 volume = Current value for the music volume.
		BE_HL_API float GetMusicVolume() const;

		// Get the volume of the sound effects channel group.
		// Return:
		//	 volume = Current value for the FX volume.
		BE_HL_API float GetEffectsVolume() const;

	private:
		//------------------------------------------------------------------------------
		// Private Functions:
		//------------------------------------------------------------------------------

		// Disable copy and assign to prevent accidental copies
		SoundManager(const SoundManager&) = delete;
		SoundManager& operator=(const SoundManager&) = delete;

		//------------------------------------------------------------------------------
		// Private Variables:
		//------------------------------------------------------------------------------

		class Implementation;
		Implementation* pimpl;
	};
}

//------------------------------------------------------------------------------
