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
#include "Shape_With_Vertices.h"
class Rectangle : public Shape_With_Vertices
{
public:
    Rectangle(Point center_, unsigned int width_, unsigned int height_);
    void Draw() const;

private:
    unsigned int width;
    unsigned int height;
};