//------------------------------------------------------------------------------
//
// File Name:	Renderer.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		Beta Engine
// Course:		WANIC VGP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "Array.h"

//------------------------------------------------------------------------------

namespace Beta
{
	//------------------------------------------------------------------------------
	// Forward Declarations:
	//------------------------------------------------------------------------------

	class PostEffect;
	class ShaderProgram;

	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	class Renderer
	{
	public:
		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		// Ctors/Dtors
		BE_API Renderer();
		BE_API ~Renderer();

		// Methods
		BE_API void Init();
		BE_API void FrameStart();
		BE_API void FrameEnd();

		// Get the default sprite shader (usually for the purposes of setting uniforms)
		BE_API const ShaderProgram& GetSpriteShader() const;

		// Get the font shader.
		BE_API const ShaderProgram& GetFontShader() const;

		// Sets the dimensions that the renderer will use to construct its framebuffer.
		BE_API void SetDimensions(unsigned width, unsigned height);

		// Adds a post-processing effect. Effects are applied sequentially,
		// starting with the first that was added.
		// Params:
		//   effect =  The effect to add to the current list of effects.
		BE_API void PushEffect(PostEffect& effect);

		// Removes the most recently added effect.
		BE_API void PopEffect();

		// Removes a specific effect.
		BE_API void RemoveEffect(PostEffect& effect);

		// Removes all effects that are currently active.
		BE_API void ClearEffects();

	private:
		//------------------------------------------------------------------------------
		// Private Functions:
		//------------------------------------------------------------------------------

		void ApplyEffects();

		//------------------------------------------------------------------------------
		// Private Variables:
		//------------------------------------------------------------------------------

		// Shader indices
		ShaderProgram* spriteShader;
		ShaderProgram* bufferToScreenShader;
		ShaderProgram* fontShader;

		// Viewport dimensions
		unsigned width;
		unsigned height;

		// Framebuffer Data
		unsigned frameBuffer;
		unsigned quadVertexBuffer;
		unsigned quadVertexArray;
		unsigned diffuseTexture0;
		unsigned diffuseTexture1;

		// Post-processing effects
		Array<PostEffect*> effects;
	};
}

//------------------------------------------------------------------------------
