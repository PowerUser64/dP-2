#include "stdafx.h"
#include "SpriteSource.h"

SpriteSource::SpriteSource(const Beta::Texture* texture, std::string name, unsigned numCols, unsigned numRows)
{
}

void SpriteSource::UseTexture(unsigned frameIndex, bool flipX, bool flipY) const
{
}

unsigned SpriteSource::GetFrameCount() const
{
	return 0;
}

const std::string& SpriteSource::GetName() const
{
	// TODO: insert return statement here
}

const Beta::Vector2D SpriteSource::GetTextureDimensions() const
{
	return Beta::Vector2D();
}

const Beta::Vector2D SpriteSource::GetUV(unsigned int frameIndex) const
{
	return Beta::Vector2D();
}
