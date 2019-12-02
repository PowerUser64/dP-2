//------------------------------------------------------------------------------
//
// File Name:	SoundEvent.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		BetaFramework
// Course:		WANIC VGP2 2018-2019
//
// Copyright © 2019 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

namespace Beta
{
		//------------------------------------------------------------------------------
		// Public Structures:
		//------------------------------------------------------------------------------

		class BE_HL_API SoundEvent
		{
		public:
			//------------------------------------------------------------------------------
			// Public Functions:
			//------------------------------------------------------------------------------
			
			// Destructor
			~SoundEvent();

			// Start the event, causing sound to play.
			// Params:
			//   releaseOnStop = Whether the event should be released once it is stopped.
			void Start(bool releaseOnStop = true);

			// Stop the event, silencing all sounds.
			// Params:
			//   fadeout = Whether the sound will fade out or end immediately.
			void Stop(bool fadeOut = false);

			// Get the current value of the given parameter.
			float GetParameter(std::string name) const;

			// Set the value of the given parameter.
			void SetParameter(std::string name, float value);

			// Get the volume of this event.
			float GetVolume() const;

			// Set the volume of this event.
			void SetVolume(float volume);

			// Only SoundManager is allowed to create sound events.
			friend class SoundManager;

		private:
			//------------------------------------------------------------------------------
			// Private Functions:
			//------------------------------------------------------------------------------

			// Constructor
			// Params:
			//   data = Internal event data.
			SoundEvent(void* data);

			//------------------------------------------------------------------------------
			// Private Variables:
			//------------------------------------------------------------------------------

			void* data; // Internal data
		};
}

//------------------------------------------------------------------------------
