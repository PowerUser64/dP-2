//------------------------------------------------------------------------------
//
// File Name:	Lab2.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		Lab2
// Course:		MAT140
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Includes:
//------------------------------------------------------------------------------

#include "BetaObject.h" // BetaObject
#include "Vector2D.h"   // Vector2D

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------

class Lab2 : public Beta::BetaObject
{
public:
	//------------------------------------------------------------------------------
	// Public Functions:
	//------------------------------------------------------------------------------

	// Constructor
	Lab2();

	// Initialize the memory associated with the Lab2 level.
	void Initialize();

	// Update the Lab2 level.
	// Params:
	//	 dt = Change in time (in seconds) since the last game loop.
	void Update(float dt);

	// Free memory associated with the Lab2 level.
	void Shutdown();

private:
	//------------------------------------------------------------------------------
	// Private Structures:
	//------------------------------------------------------------------------------
	
	enum DrawShape
	{
		Triangle,
		Parallelogram,
		Triforce,
		Face,
		Hexagon,
		DiamondCut,
		ShapeNum
	};

	// Function pointer for each of the shape drawing functions
	typedef void(*ShapeVoidFunctionPtr)();

	//------------------------------------------------------------------------------
	// Private Variables:
	//------------------------------------------------------------------------------

	// Shape type
	int shape;

	// Stores function pointers for shape drawing functions
	static ShapeVoidFunctionPtr shapeFunctions[ShapeNum];

	// Points/Vectors
	static const Beta::Vector2D& pointP;
	static const Beta::Vector2D& vectorV;
	static const Beta::Vector2D& vectorU;

	//------------------------------------------------------------------------------
	// Private Functions:
	//------------------------------------------------------------------------------

	// Draws a triangle from 3 points
	static void DrawAngle(const Beta::Vector2D& Point1, const Beta::Vector2D& Point2, const Beta::Vector2D& Point3);

	// Draws a line
	static void DrawLine(const Beta::Vector2D& start, const Beta::Vector2D& end);

	// Shapes - Complete these functions!
	static void CreateTriangle();
	static void CreateParallelogram();
	static void CreateTriforce();
	static void CreateFace();
	static void CreateHexagon();
	static void CreateDiamondCut();
};
