//------------------------------------------------------------------------------
//
// File Name:   FileName.h
// Author(s):   Blakely North (blakely.north@digipen.edu)
// Project:     CS170 Project 4: Inheritance
// Course:      WANIC VGP2
//
// Copyright © 2019 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#include "Shape.h"
#include <iostream>

/* 
 * Description:
 * Abstract class that serves as the parent of all shapes.
 * In it you will find all properties and methods that belong in all shapes (Center, Draw, etc...)
 * 
 * Methods:
 * Shape(Point center_);
 * ~Shape();
 * Point GetCenter();
 * void SetCenter(float x_, float y_);
 * void Draw();
 * 
 * Properties
 * Point center;
 */

Shape::Shape(Point center_)
{
    center = center_;
}

Shape::~Shape()
{
}

Point Shape::GetCenter() const
{
    return center;
}

void Shape::SetCenter(float x_, float y_)
{
    center.x = x_, center.y = y_;
}