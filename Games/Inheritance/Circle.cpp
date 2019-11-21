
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
#include "Circle.h"

Circle::Circle(Point center_, unsigned int radius_) : Shape(center_)
{
    radius = radius_, SetCenter(center_.x, center_.y);
}
Circle::~Circle()
{
}
void Circle::Draw() const
{
    std::cout << "Drawing a circle at x = " << GetCenter().x << " y = " << GetCenter().y << " and radius " << radius << std::endl << std::endl;
}