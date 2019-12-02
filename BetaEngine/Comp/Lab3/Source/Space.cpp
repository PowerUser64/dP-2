#include "stdafx.h"
#include "Space.h"

Space::Space(const std::string& name)
{
}

Space::~Space()
{
}

void Space::Update(float dt)
{
}

void Space::Shutdown()
{
}

bool Space::IsPaused() const
{
	return false;
}

const std::string& Space::GetLevelName() const
{
	// TODO: insert return statement here
}

void Space::SetPaused(bool value)
{
}

void Space::SetLevel(Level* level)
{
}

void Space::RestartLevel()
{
}

void Space::ChangeLevel()
{
}
