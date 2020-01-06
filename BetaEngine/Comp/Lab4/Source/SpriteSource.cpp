#include "stdafx.h"
#include "SpriteSource.h"

/* 1.  SpriteSource (constructor)
 *     *   Simple constructor, just make sure everything gets initialized properly using the provided parameters/sane default values.
 */
SpriteSource::SpriteSource(const Beta::Texture *_texture, std::string _name, unsigned _numCols, unsigned _numRows)
{
	// The dimensions of the sprite sheet texture.
	// unsigned
	numRows = _numRows;
	// unsigned
	numCols = _numCols;

	// Pointer to a texture created using the Low Level API.
	// const Beta::Texture
	texture = _texture;

	// Name of sprite source
	// std::string
	name = _name;
}

/* 2.  UseTexture
 *     *   Calculate the UV offset using _GetUV_ and store it in a variable.
 *     *   Call the texure's _Use _function, passing 1 and 1 for the rows and columns, using the appropriate class variables for the other parameters. You can leave
 *   the last param (the shader) blank; it will default to the last used shader.
 *     *
 *    *-*   _\[NOTE:_ _Yes, we do have actual variables for the rows and columns of the sprite source that we could pass in here, in which case the shader would 
 *	 take care of drawing the correct portion of the texture for us, which is ideal. However, I want you_ _to do the work of calculating which portion of the texture 
 *	 to display when you create the quad mesh in MeshHelper.cpp. This is just to prove you can get the math correct. If you pass in the columns and rows here instead 
 *	 of doing the UV calculations in the mesh creation, I will dock you points for this assignment. In the future, however, I suggest passing in the column/row info 
 *	 here, as this will allow you to use the same mesh for nearly every 2D sprite.\]_
 */
void SpriteSource::UseTexture(unsigned frameIndex, bool flipX, bool flipY) const
{
	Beta::Vector2D UV = GetUV(frameIndex);
	texture->Use(1, 1, flipX, flipY, UV /* , shader ???? */); // void Use(unsigned int spriteColumns, unsigned int spriteRows, bool flipX, bool flipY, const Beta::Vector2D &uvOffset, const Beta::ShaderProgram *shader = (const Beta::ShaderProgram *)nullptr) const
}

/* 3.   GetFrameCount
 *    *   Return the total frame count (calculated based off of _numRows _and _numCols_).
 */
unsigned SpriteSource::GetFrameCount() const
{
	return (numRows * numCols);
}

// Gets the name of the sprite source.
const std::string &SpriteSource::GetName() const
{
	return name;
}

// Gets the dimensions of the texture (number of columns, rows)
const Beta::Vector2D SpriteSource::GetTextureDimensions() const
{
	return Beta::Vector2D(numCols, numRows);
}

/* 4.  GetUV
 *     *   The only non-trivial function. First calculate the portion of the texture that each column and row take up (sometimes called U-size and V-size). Remember 
 *   that texture coordinates go from 0.0 to 1.0 on both axes.
 *     *   Next, calculate the column and row that correspond to the given frame. (HINT: You'll need to use some form of division, along with the frame and the 
 *   number of columns.)
 *     *   Once you have the U size and V size and the column and row that correspond to the given frame, the UV coordinates can be calculated quite easily:
 *         *   u = uSize \* column
 *         *   v = vSize \* row
 *     *   Store the U and V in the x and y of the provided vector.
 */
const Beta::Vector2D SpriteSource::GetUV(unsigned int frameIndex) const
{
	// First calculate the portion of the texture that each column and row take up (sometimes called U-size and V-size). Remember that texture coordinates go from 0.0 to 1.0 on both axes.
	int currentCol = 0, currentRow = 0;
	currentCol = frameIndex % numCols;
	currentRow = frameIndex / numCols;
	return Beta::Vector2D(currentCol / (float)numCols, currentRow / (float)numRows);
}
