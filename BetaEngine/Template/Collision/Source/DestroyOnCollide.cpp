#include "stdafx.h"
#include "DestroyOnCollide.h"

DestroyOnCollide::DestroyOnCollide()
    : Component("DestroyOnCollide")
{
}

void DestroyOnCollide::Initialize()
{
    RegisterEventHandler(GetOwner(), "CollisionStarted", &DestroyOnCollide::OnCollisionStarted);
}

void DestroyOnCollide::OnCollisionStarted(const Beta::Event& event)
{
    // Destoy the obj  that owns this
    GetOwner()->Destroy();
}

COMPONENT_SUBCLASS_DEFINITION(DestroyOnCollide);