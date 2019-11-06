#pragma once

#include <Component.h> // "bass" class

class DestroyOnCollide : public Beta::Component
{
public:
    DestroyOnCollide();
    void Initialize();
private:
    void OnCollisionStarted(const Beta::Event& event);
    COMPONENT_SUBCLASS_DECLARATION(DestroyOnCollide);
};