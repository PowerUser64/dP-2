#include "stdafx.h"
#include "Lab2.h"
#include "Animator.h"
#define p pointP
#define v vectorV
#define w vectorU
/*
 *
 *            P+v
 *            /\
 *           /   \
 *          /      \
 *         /         \
 *        /       __---\
 *       /____---      P+u
 *      P
 */
using namespace Beta;

const Vector2D &Lab2::pointP = Animator::GetPointP();
const Vector2D &Lab2::vectorU = Animator::GetVectorU();
const Vector2D &Lab2::vectorV = Animator::GetVectorV();

Lab2::Lab2()
	: BetaObject("Lab2")
{
}

void Lab2::Initialize()
{
	std::cout << "Lab2:Initialize" << std::endl;
}

void Lab2::Update(float dt)
{
	DebugDraw& debug = *EngineGetModule(DebugDraw);
	void EndLineList(Camera & camera, float zDepth = 0.0f);
}

void Lab2::DrawAngle(const Beta::Vector2D& Point1, const Beta::Vector2D& Vect2, const Beta::Vector2D& Vect3)
{
	DrawLine(Point1, Vect2);
	DrawLine(Point1, Vect3 + Point1);
}

void Lab2::DrawLine(const Beta::Vector2D& start, const Beta::Vector2D& end)
{
	// Obtain necessary modules, etc.
	DebugDraw& debug = *EngineGetModule(DebugDraw);
	debug.AddLineToList(start, end, Colors::Green);
}

void Lab2::CreateTriangle()
{
	DrawLine(p, w + p);
	DrawLine(p, v + p);
	DrawLine(w + p, v + p);
}

void Lab2::CreateParallelogram()
{
	DrawLine(p, w + p);
	DrawLine(p, v + p);
	DrawLine(p + w, p + v);
	DrawLine(p + v, p + v + w);
	DrawLine(p + w, p + v + w);
 }

void Lab2::CreateTriforce()
{
	DrawLine(p, w + p);
	DrawLine(p, v + p);
	DrawLine(w + p, v + p);
	DrawLine((w + p)/2, (v + p)/2);
	DrawLine(p, v + p);
	DrawLine(w + p, v + p);
}

void Lab2::CreateFace()
{
}

void Lab2::CreateHexagon()
{
}

void Lab2::CreateDiamondCut()
{
}

void Lab2::Shutdown()
{
}
