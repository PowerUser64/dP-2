//------------------------------------------------------------------------------
//
// File Name:	Sprite.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		BetaFramework
// Course:		WANIC VGP2 2018-2019
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "Component.h"

#include <Color.h>
#include <Vector2D.h>
#include <Mesh.h>

#include "ResourceManager.h"

//------------------------------------------------------------------------------

namespace Beta
{
	//------------------------------------------------------------------------------
	// Forward References:
	//------------------------------------------------------------------------------

	class Transform;

	class SpriteSource;
	typedef std::shared_ptr<SpriteSource> SpriteSourcePtr;
	typedef std::shared_ptr<const SpriteSource> ConstSpriteSourcePtr;
	typedef std::shared_ptr<Mesh> MeshPtr;

	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	class MeshManager : public ResourceManager<Mesh>
	{
	public:
		BE_HL_API MeshManager();
	private:
		MeshPtr Create(const std::string& name) override;
	};

	// You are free to change the contents of this structure as long as you do not
	//   change the public interface declared in the header.
	class Sprite : public Component
	{
	public:
		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		// Create a new sprite object.
		BE_HL_API Sprite();

		// Grabs mesh and sprite source from resource manager,
		// other necessary components.
		BE_HL_API void Initialize() override;

		// Draw a sprite (Sprite can be textured or untextured).
		BE_HL_API void Draw() override;

		// Draw a sprite at an offset from the object's translation.
		// Params:
		//   offset = The offset that will be added to the translation when drawing.
		BE_HL_API void Draw(const Vector2D& offset);

		// Set a sprite's transparency (between 0.0f and 1.0f).
		// Params:
		//   alpha = New value for the sprite's 'alpha' value.
		BE_HL_API void SetAlpha(float alpha);

		// Get the current value for a sprite's transparency.
		BE_HL_API float GetAlpha() const;

		// Set the sprite's current frame.
		// Params:
		//   frameIndex = New frame index for the sprite (0 .. frame count).
		BE_HL_API void SetFrame(unsigned int frameIndex);

		// Set the sprite's mesh.
		// (NOTE: This mesh may be textured or untextured.)
		// (NOTE: This mesh may contain any number of triangles.)
		// Params:
		//   mesh = Pointer to a mesh created using the Beta Framework.
		BE_HL_API void SetMesh(MeshPtr mesh);

		// Set a new SpriteSource for the specified sprite.
		// Params:
		//	 spriteSource = A new sprite source for the sprite.
		BE_HL_API void SetSpriteSource(ConstSpriteSourcePtr spriteSource);

		// Returns the current sprite source being used by the sprite.
		BE_HL_API ConstSpriteSourcePtr GetSpriteSource();

		// Set the blend color for the specified sprite.
		// Params:
		//	 color = A new color for the sprite.
		BE_HL_API void SetColor(Color color);

		// Retrieves the blend color for the sprite.
		BE_HL_API const Color& GetColor() const;

		// Retrieves the current depth of the sprite in the level.
		BE_HL_API float GetZDepth() const;

		// Sets the current depth of the sprite in the level.
		BE_HL_API void SetZDepth(float depth);

		// Set whether to flip the sprite horizontally when drawing
		BE_HL_API void SetFlipX(bool flipX);

		// Set whether to flip the sprite vertically when drawing
		BE_HL_API void SetFlipY(bool flipY);

		// Save object data to file.
		// Params:
		//   stream = The stream object used to save the object's data.
		BE_HL_API void Serialize(FileStream& stream) const;

		// Load object data from file
		// Params:
		//   stream = The stream object used to load the object's data.
		BE_HL_API void Deserialize(FileStream& stream);

		// Use this to manage sprite source resources!
		BE_HL_API static MeshManager& GetMeshManager();

	protected:
		//------------------------------------------------------------------------------
		// Protected Variables:
		//------------------------------------------------------------------------------

		// Components
		Transform* transform;

	private:
		//------------------------------------------------------------------------------
		// Private Variables:
		//------------------------------------------------------------------------------

		// The frame currently being displayed (for sprite sheets).
		unsigned int frameIndex;

		// The sprite source used when drawing (simple colored mesh will have no sprite source).
		ConstSpriteSourcePtr spriteSource;

		// The mesh used to draw the sprite.
		MeshPtr mesh;

		// Color used for blending/tint
		Color color;

		// For depth
		float zDepth;

		// Mirroring
		bool flipX;
		bool flipY;

		static MeshManager meshManager;

		// RTTI
		COMPONENT_SUBCLASS_DECLARATION(Sprite)
	};

#define ResourceGetMesh(m) Sprite::GetMeshManager().GetResource(m)
}

//------------------------------------------------------------------------------
