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
#include <iostream>

class Shape
{
public:
    Shape(Point center_);
    virtual ~Shape();
    Point GetCenter() const;
    void SetCenter(float x_, float y_);
    virtual void Draw() const = 0;

private:
    Point center;
};