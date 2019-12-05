#include "stdafx.h"
#include "Animator.h"


Animator::Animator(Sprite* sprite_)
{
}

void Animator::Update(float dt)
{
}

void Animator::Play(size_t animationIndex, float playbackSpeed, bool loop)
{
}

size_t Animator::AddAnimation(const Animation* animation)
{
	return size_t();
}

size_t Animator::GetCurrentAnimationIndex() const
{
	return size_t();
}

size_t Animator::GetAnimationIndex(const std::string& name) const
{
	return size_t();
}

bool Animator::IsDone() const
{
	return false;
}

void Animator::SetPlaybackSpeed(float speed)
{
}
