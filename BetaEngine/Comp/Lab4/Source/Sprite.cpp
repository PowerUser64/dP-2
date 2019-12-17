#include "stdafx.h"
#include "Sprite.h"
#include "SpriteSource.h"

using namespace Beta;

Sprite::Sprite(Beta::Mesh *mesh_, const SpriteSource *spriteSource_)
{
	// The frame currently being displayed (for sprite sheets).
	/* unsigned int */ frameIndex = 0;

	// The sprite source used when drawing (simple colored mesh will have no sprite source).
	/* const SpriteSource */ spriteSource = spriteSource_;

	// The mesh used to draw the sprite.
	/* Beta::Mesh */ mesh = mesh_;

	// Color used for blending/tint
	/* Beta::Color */ color;

	// Mirroring
	/* bool */ flipX = 0;
	/* bool */ flipY = 0;
}

/* 2.  Draw
 *   If this sprite has no mesh, simply return. Can't draw without a mesh!
 *   Get the sprite shader from the GraphicsEngine module and call its _Use_ function to activate it.
 *   If this sprite has a sprite source
 *   *   Call the _UseTexture_ function on the sprite source, passing it the appropriate information using this sprite's class variables.
 *   Otherwise
 *   *   Get the default texture from the GraphicsEngine module (a 1x1 white texture) and call its _Use_ function to set it as the current texture_._
 *   Set the location and scale of the object being drawn using the _SetTransform _function on Graphics. Eventually we'll have a transform component to get these values from, but for now just use _Vector2D(0, 0)_ as the position,  _Vector2D(1, 1)_ as the scale, and 0 as the rotation.
 */
void Sprite::Draw()
{
	if (mesh == nullptr)
		return;
	
	// Use sprite shader
	GraphicsEngine& graphics = *EngineGetModule(GraphicsEngine);
	graphics.GetSpriteShader().Use(); 
	// Set texture of object
	if (spriteSource != nullptr)
		spriteSource->UseTexture(frameIndex, flipX, flipY);
	else
		graphics.GetDefaultTexture().Use();
	
	// Set color of object
	graphics.SetSpriteBlendColor(color);
	// Set position of object
	graphics.SetTransform(Vector2D(0, 0), Vector2D(1, 1), 0);
	// Drawing the mesh (list of triangles)
	mesh->Draw();

}

/* 3.  SetAlpha
 *   Set the alpha on the sprite's _color_ variable to the provided value.
 */
void Sprite::SetAlpha(float alpha)
{
	color.a = alpha;
}

/* 4.  GetAlpha
 *   Return the alpha on the sprite's _color_ variable.
 */
float Sprite::GetAlpha() const
{
	return color.a;
}

/* 5.  SetFrame  
 *   Print out "Sprite::SetFrame" to the console.
 *   If the provided frame index is less than the sprite source's frame count, set the _frameIndex _to the provided value.
 */
void Sprite::SetFrame(unsigned int _frameIndex)
{
	std::cout << "Sprite::SetFrame\n";
	std::cout << "frame = \n" << frameIndex;
	if (frameIndex < spriteSource->GetFrameCount())
		frameIndex = _frameIndex;
}

/* SetMesh
 *   Simple accessors/mutators. Implement them.
 */
void Sprite::SetMesh(Beta::Mesh *_mesh)
{
	mesh = _mesh;
}

/* SetSpriteSource
 *   Simple accessors/mutators. Implement them.
 */
void Sprite::SetSpriteSource(const SpriteSource *_spriteSource)
{
	spriteSource = _spriteSource;
}

/* SpriteSource
 *   Simple accessors/mutators. Implement them.
 */
const SpriteSource *Sprite::GetSpriteSource()
{
	return spriteSource;
}

/* SetColor
 *   Simple accessors/mutators. Implement them.
 */
void Sprite::SetColor(Beta::Color _color)
{
	color = _color;
}

/* GetColor
 *   Simple accessors/mutators. Implement them.
 */
const Beta::Color &Sprite::GetColor() const
{
	return color;
}

/* SetFlipX
 *   Simple accessors/mutators. Implement them.
 */
void Sprite::SetFlipX(bool _flipX)
{
	flipX = _flipX;
}

/* SetFlipY
 *   Simple accessors/mutators. Implement them.
 */
void Sprite::SetFlipY(bool _flipY)
{
	flipY = _flipY;
}