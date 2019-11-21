#include "stdafx.h"
#include "test.h"

using namespace Beta;

test::test()
{
    // getowner
    Transform *transform = GetOwner()->GetComponent<Transform>();
    RigidBody *rigidbody = GetOwner()->GetComponent<RigidBody>();
    Sprite *sprite = GetOwner()->GetComponent<Sprite>;

    // getspace
    Space *Space = GetSpace();
}