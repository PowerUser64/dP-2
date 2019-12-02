//------------------------------------------------------------------------------
//
// File Name:	GraphicsEngine.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		Beta Engine
// Course:		WANIC VGP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Libraries:
//------------------------------------------------------------------------------

#pragma comment(lib, "opengl32.lib")

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "Matrix2D.h"
#include "Color.h"
#include "Camera.h"
#include "Texture.h"
#include "Shapes2D.h"

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Forward Declarations:
//------------------------------------------------------------------------------

struct FT_LibraryRec_;

namespace Beta
{
	class Matrix2D;
	class Renderer;
	class PostEffect;
	class ShaderProgram;
	typedef FT_LibraryRec_ FontSystem;

	//------------------------------------------------------------------------------
	// Public Consts:
	//------------------------------------------------------------------------------

	enum BE_API BlendMode
	{
		BM_None = 0,
		BM_Blend,
		BM_Add,
		BM_Multiply,
		BM_Screen,

		// Keep this one last
		BM_Num
	};

	//------------------------------------------------------------------------------
	// Public Functions:
	//------------------------------------------------------------------------------

	void BE_API CheckForOpenGLErrors();

	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	class BE_API GraphicsEngine
	{
	public:
		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		//////////////////////
		// ENGINE FUNCTIONS //
		//////////////////////

		GraphicsEngine();
		~GraphicsEngine();

		void Initialize(unsigned width, unsigned height);
		void FrameStart();
		void FrameEnd();

		/////////////////////
		// COMMON SETTINGS //
		/////////////////////

		// Otherwise uncolored pixels will have this color
		const Color& GetBackgroundColor() const;
		void SetBackgroundColor(const Color& color = Colors::Black);

		// Color to blend with whole screen
		const Color& GetScreenTintColor() const;
		void SetScreenTintColor(const Color& color = Colors::White);

		// Color to blend with the current sprite's color
		void SetSpriteBlendColor(const Color& color = Colors::White);

		// Returns a 1x1 white texture.
		const Texture& GetDefaultTexture() const;

		// Transform
		void SetTransform(const Matrix2D& matrix, float depth = 0.0f);
		void SetTransform(const Vector2D& translation, const Vector2D& scale = Vector2D(1.0f, 1.0f),
			float rotation = 0.0f, float depth = 0.0f);

		// Camera
		Camera& GetDefaultCamera() const;

		// Return the sprite shader (usually for the purpose of setting uniforms)
		const ShaderProgram& GetSpriteShader() const;
		// Return the font shader
		const ShaderProgram& GetFontShader() const;

		///////////////////////
		// ADVANCED SETTINGS //
		///////////////////////

		// Set how sprites are blended
		void SetBlendMode(BlendMode mode, bool forceSet = false);

		// Add a post-processing effect. Effects are applied sequentially,
		// starting with the first that was added.
		// Template Params:
		//   EffectType =  The type of effect to add to the current list of effects.
		// Returns:
		//   The newly created effect.
		template<class EffectType>
		EffectType* PushEffect()
		{
			EffectType* effect = new EffectType;
			PushEffect(*effect);
			return effect;
		}
		// Add a post-processing effect. Effects are applied sequentially,
		// starting with the first that was added.
		// Params:
		//   effect =  The effect to add to the current list of effects.
		void PushEffect(PostEffect& effect);
		// Remove the most recently added effect.
		void PopEffect();
		// Remove a specific effect.
		void RemoveEffect(PostEffect* effect);
		
		// Removes all effects that are currently active.
		void ClearEffects();

		// Test whether vertical sync is currently on
		bool GetUseVsync() const;
		// Turn vertical sync on or off - will cause performance issues on some machines
		void SetUseVSync(bool useVsync);

		// Get the dimensions of the viewport
		Vector2D GetViewport() const;
		// Set the dimensions of the viewport.
		// Params:
		//   width = The new width of the viewport.
		//   height = The new height of the viewport.
		void SetViewport(unsigned width, unsigned height);

		// Returns a pointer to the font system. For internal use only.
		FontSystem* GetFontSystem() const;

	private:
		//------------------------------------------------------------------------------
		// Private Functions:
		//------------------------------------------------------------------------------

		// Disable copy and assign to prevent accidental copies
		GraphicsEngine(const GraphicsEngine&) = delete;
		GraphicsEngine& operator=(const GraphicsEngine&) = delete;

		// Remove a specific effect.
		void RemoveEffect(PostEffect& effect);

		//------------------------------------------------------------------------------
		// Private Variables:
		//------------------------------------------------------------------------------

		class Implementation;
		Implementation* pimpl;
	};
}

//------------------------------------------------------------------------------
