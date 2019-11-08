//------------------------------------------------------------------------------
//
// File Name:	WindowSystem.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		Beta Engine
// Course:		CS230
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Includes:
//------------------------------------------------------------------------------

#include "StartupSettings.h"
#include "Vector2D.h"

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Forward Declarations:
//------------------------------------------------------------------------------

struct GLFWwindow;

namespace Beta
{
	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	class BE_API WindowSystem
	{
	public:
		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		// Constructor
		WindowSystem();

		// Shutdown the WindowSystem (Windows, Event Handlers).
		~WindowSystem();

		// Initialize the WindowSystem (Windows, Event Handlers).
		// Params: 
		//   settings = The settings to use for the window.
		void Initialize(const StartupSettings& settings);

		// End the frame and draw
		void Draw();

		// Set the title of the window being used by Beta Framework.
		// Params: 
		//   text = The string that the window title will be set to.
		void SetWindowTitle(const std::string& text);

		// Does the window for this program still exist?
		bool DoesWindowExist() const;

		// Test whether the application is in fullscreen mode.
		bool IsFullScreen() const;
		// Set whether the window is fullscreen.
		void SetFullScreen(bool fullscreen);

		// Set the resolution of the window.
		// Params:
		//   width = The new width of the window.
		//   height = The new height of the window.
		void SetResolution(unsigned width, unsigned height);

		// Get the current resolution of the window.
		Vector2D GetResolution() const;

		// GLFW callbacks
		friend void WinCloseCallback(GLFWwindow* window);

	private:
		//------------------------------------------------------------------------------
		// Private Functions:
		//------------------------------------------------------------------------------

		// Disable copy and assign to prevent accidental copies
		WindowSystem(const WindowSystem&) = delete;
		WindowSystem& operator=(const WindowSystem&) = delete;

		// Initializes the Beta systems. Uses the specified options to initialize Beta and
		// the functionality handled by Beta.
		void InitHelper();

		// Window creation
		void CreateWindowGLFW();

		//------------------------------------------------------------------------------
		// Private Variables:
		//------------------------------------------------------------------------------

		// Window information
		bool winExists;
		StartupSettings systemInfo;
		GLFWwindow* glfwWindow;
		bool fullscreen;
		int windowPositionX;
		int windowPositionY;
	};
}

/*----------------------------------------------------------------------------*/
