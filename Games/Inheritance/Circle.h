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
#pragma once
#include "Point.h"
#include "Shape.h"
/*
 * Circle(Point center_, unsigned int radius_);
 * Properties: unsigned int radius
 */
class Circle : public Shape
{
public:
    Circle(Point center_, unsigned int radius_);
    ~Circle();
    void Draw() const;

private:
    unsigned int radius;
};