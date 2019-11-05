//------------------------------------------------------------------------------
//
// File Name:	Mesh.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		Beta Engine
// Course:		WANIC VGP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

namespace Beta
{
	class Vector2D;

	//------------------------------------------------------------------------------
	// Forward References:
	//------------------------------------------------------------------------------

	class ShaderManager;

	//------------------------------------------------------------------------------
	// Public Consts:
	//------------------------------------------------------------------------------

	// Types of data found in vertex buffers for default mesh
	enum BE_API BufferType
	{
		// DO NOT MODIFY - used by default vertices/meshes
		BT_Position,
		BT_Color,
		BT_TextureCoordinate,

		// Keep this one last
		BT_Num
	};

	// Different methods for drawing meshes
	enum BE_API MeshDrawMode
	{
		MDM_Points = 0,
		MDM_Lines,
		MDM_Lines_Strip,
		MDM_Lines_Loop,
		MDM_Triangles,

		// Keep this one last
		MDM_Num
	};

	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	class Mesh
	{
	public:
		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		BE_API ~Mesh();

		// Draw the mesh
		BE_API void Draw() const;

		// Return the number of vertices contained in this mesh.
		BE_API unsigned GetNumVertices() const;

		// Updates the positions of the vertices using the given array.
		// Currently only used by fonts. Updating mesh vertices at runtime is
		// generally not recommended for efficiency reasons.
		// Params:
		//   positions - An array containing the new vertex positions. The size
		//      of this array is assumed to be equal to "numVertices".
		BE_API void UpdatePositionBuffer(const Vector2D* positions);

		// Return the name of this mesh.
		BE_API const std::string& GetName() const;

		// Set the name of this mesh.
		BE_API void SetName(const std::string& name);

		friend class MeshFactory;

	private:
		//------------------------------------------------------------------------------
		// Private Functions:
		//------------------------------------------------------------------------------

		Mesh(unsigned numVertices, MeshDrawMode drawMode = MDM_Triangles, unsigned numBuffers = BT_Num);

		void SetDrawMode(MeshDrawMode drawMode);

		//------------------------------------------------------------------------------
		// Private Data:
		//------------------------------------------------------------------------------

		unsigned numVertices;
		unsigned numBuffers;
		unsigned* bufferIDs;
		unsigned arrayObjectID;
		unsigned drawMode;
		std::string name;
	};
}

//------------------------------------------------------------------------------
