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
#include "Polygon.h"

Polygon::Polygon(Point center_, unsigned int number_of_vertices_) : Shape_With_Vertices(center_, number_of_vertices_)
{
    
}
Polygon::Polygon(Point center_, const Point *points_, unsigned int number_of_vertices_) : Shape_With_Vertices(center_, number_of_vertices_)
{
    for (size_t i = 0; i < number_of_vertices_; ++i)
        vertices[i] = points_[i];
}
void Polygon::SetVertex(unsigned int vertexIdx_, float x_, float y_)
{
    vertices[vertexIdx_] = Point(x_, y_);
}

void Polygon::Draw() const
{
    std::cout << "Drawing a polygon at x = " << GetCenter().x << " y = " << GetCenter().y << std::endl;
    for(size_t i = 0; i < number_of_vertices; ++i)
        std::cout << "Vertex " << i << " (" << GetCenter().x << ", " << GetCenter().y << ')' << std::endl;
}