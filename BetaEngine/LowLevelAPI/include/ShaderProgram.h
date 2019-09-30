//------------------------------------------------------------------------------
//
// File Name:	ShaderProgram.h
// Author(s):	Jeremy Kings
// Project:		Beta Engine
// Course:		WANIC VGP2
//
// Copyright © 2018-2019 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include <map>
#include "Array.h"

//------------------------------------------------------------------------------

namespace Beta
{
	//------------------------------------------------------------------------------
	// Forward Declarations:
	//------------------------------------------------------------------------------

	class Vector2D;
	struct Vector3D;
	class Matrix2D;
	struct Matrix3D;
	struct Color;

	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	class ShaderProgram
	{
	public:
		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		// Destructor
		BE_API ~ShaderProgram();

		// Set this as the active shader program
		BE_API void Use() const;

		// Set values of uniform variables
		BE_API void SetUniform(const std::string& name, int value) const;
		BE_API void SetUniform(const std::string& name, float value) const;
		BE_API void SetUniform(const std::string& name, bool value) const;
		BE_API void SetUniform(const std::string& name, const Vector2D& value) const;
		BE_API void SetUniform(const std::string& name, const Vector3D& value) const;
		BE_API void SetUniform(const std::string& name, const Color& value) const;
		BE_API void SetUniform(const std::string& name, const Matrix2D& value) const;
		BE_API void SetUniform(const std::string& name, const Matrix3D& value) const;

		// Set values of uniform arrays
		BE_API void SetUniform(const std::string& name, const Array<int>& values) const;
		BE_API void SetUniform(const std::string& name, const Array<float>& values) const;
		BE_API void SetUniform(const std::string& name, const Array<Vector2D>& values) const;
		BE_API void SetUniform(const std::string& name, const Array<Vector3D>& values) const;
		BE_API void SetUniform(const std::string& name, const Array<Color>& values) const;

		// Operators
		BE_API bool operator==(const ShaderProgram& other) const;

		// Attempt to load a shader program from a file.
		// Params:
		//   vertexShaderFile = The file name of the vertex shader.
		//   pixelShaderFile = The file name of the pixel shader.
		// Returns:
		//   A valid program if successful, nullptr if unsuccessful.
		BE_API static ShaderProgram* CreateProgramFromFile(const std::string& vertexShaderFile, const std::string& fragmentShaderFile);

		// The current relative path for loading shaders.
		BE_API static std::string shaderPath;

	private:
		//------------------------------------------------------------------------------
		// Private Functions:
		//------------------------------------------------------------------------------

		// Deleted functions
		ShaderProgram(const ShaderProgram& other) = delete;
		ShaderProgram& operator=(const ShaderProgram& other) = delete;

		// Constructor
		// Params:
		//   id = The program id returned by OpenGL during shader creation.
		//   vertexShader = The file name of the vertex shader.
		//   pixelShader = The file name of the pixel shader.
		ShaderProgram(unsigned id, const std::string& vertexShader, const std::string& pixelShader);

		// Getting IDs of shader variables
		int GetUniformLocation(const std::string& name) const;
		int GetAttributeLocation(const std::string& name) const;

		// Loads shaders into OpenGL from strings/files
		static bool AddShaderFromString(unsigned program, const std::string& source, int glType);
		static bool AddShaderFromFile(unsigned program, const std::string& filename, int glType);

		// Reads contents from a file into a string
		static std::string ReadFromFile(const std::string& filename);

		//------------------------------------------------------------------------------
		// Private Variables:
		//------------------------------------------------------------------------------

		// Variables
		unsigned id;
		std::string vertexShader;
		std::string pixelShader;

		// Store locations for faster lookup
		mutable std::map<std::string, int> uniformLocations;
		mutable std::map<std::string, int> attributeLocations;
	};
}

//------------------------------------------------------------------------------
