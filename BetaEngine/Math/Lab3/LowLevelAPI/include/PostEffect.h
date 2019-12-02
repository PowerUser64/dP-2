//------------------------------------------------------------------------------
//
// File Name:	PostEffect.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		Beta Engine
// Course:		WANIC VGP2
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
	// Forward Declarations:
	//------------------------------------------------------------------------------

	class ShaderProgram;

	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	class BE_API PostEffect
	{
	public:
		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		// Constructor
		// Params:
		//   fragmentShader = The filename of the fragment shader for this effect.
		//   vertexShader = The filename of the vertex shader for this effect. Defaults to simple vertex shader.
		PostEffect(const std::string& fragmentShader, const std::string& vertexShader = "passthroughShader.vert");
		~PostEffect();

		// Override this to reset variables as needed.
		virtual void Initialize();

		// Override this to modify variables before they are sent to the shader.
		virtual void Update(float dt);

		// Test whether this effect is currently being used by the renderer.
		bool IsActive() const;

		// Get the shader program used by this effect.
		const ShaderProgram& GetProgram() const;

		// Allow renderer to access private functions.
		friend class Renderer;

	protected:
		//------------------------------------------------------------------------------
		// Protected Functions:
		//------------------------------------------------------------------------------

		// Sends uniform data to shader. Called automatically by the Render function.
		// Override this to send custom data to the shader.
		virtual void Draw();

	private:
		//------------------------------------------------------------------------------
		// Private Functions:
		//------------------------------------------------------------------------------

		// Renders from the source texture to the target using the given effect.
		// Params:
		//   sourceTexture = The texture we will be affecting.
		//   width = Width of the source/target textures.
		//   height = Height of the source/target textures.
		void Render(unsigned sourceTexture, unsigned width, unsigned height);

		//------------------------------------------------------------------------------
		// Private Variables:
		//------------------------------------------------------------------------------

		ShaderProgram* program;
		bool active;
	};
}

//------------------------------------------------------------------------------
