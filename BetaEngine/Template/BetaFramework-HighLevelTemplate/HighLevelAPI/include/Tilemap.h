//------------------------------------------------------------------------------
//
// File Name:	Tilemap.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		BetaFramework
// Course:		WANIC VGP2 2018-2019
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include <Array.h>
#include <Vector2D.h>
#include "Serializable.h"
#include "ResourceManager.h"

//------------------------------------------------------------------------------

namespace Beta
{

	//------------------------------------------------------------------------------
	// Forward Declarations:
	//------------------------------------------------------------------------------

	class GameObject;

	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	struct ObjectInMap : public Serializable
	{
		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		// Constructors
		BE_HL_API ObjectInMap();
		BE_HL_API ObjectInMap(GameObject* object, const std::string& name, int x, int y);

		// Functions
		BE_HL_API void Serialize(FileStream& stream) const override;
		BE_HL_API void Deserialize(FileStream& stream) override;

		// Operators
		BE_HL_API bool operator==(const ObjectInMap& rhs) const;

		//------------------------------------------------------------------------------
		// Public Variables:
		//------------------------------------------------------------------------------

		// Variables
		mutable GameObject* object;
		std::string name;
		int x;
		int y;
	};

	class Tilemap;
	typedef std::shared_ptr<Tilemap> TilemapPtr;
	typedef std::shared_ptr<const Tilemap> ConstTilemapPtr;

	class TilemapManager : public ResourceManager<Tilemap>
	{
	public:
		BE_HL_API TilemapManager();
	private:
		TilemapPtr Create(const std::string& name) override;
	};

	class Tilemap : public Serializable
	{
	public:
		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		// Create a tilemap from the given parameters.
		// Params:
		//   width = The width of the map.
		//   height = The height of the map.
		//   name = The name of the map.
		//   data = The array containing the map data.
		BE_HL_API Tilemap(unsigned width = 0, unsigned height = 0, const std::string& name = "", int** data = nullptr);

		// Destructor.
		BE_HL_API ~Tilemap();

		// Gets the width of the map (in tiles).
		BE_HL_API unsigned GetWidth() const;

		// Get the height of the map (in tiles).
		BE_HL_API unsigned GetHeight() const;

		// Gets the minimum and maximum indices
		BE_HL_API int GetMinIndexX() const;
		BE_HL_API int GetMinIndexY() const;
		BE_HL_API int GetMaxIndexX() const;
		BE_HL_API int GetMaxIndexY() const;

		// Gets the value of the cell in the map with the given indices.
		// Params:
		//   column = The column of the cell.
		//   row = The row of the cell.
		// Returns:
		//   -1 if the indices are invalid, 0 if the cell is empty, 
		//   or a positive integer otherwise.
		BE_HL_API int GetCellValue(int column, int row) const;

		// Sets the value of the cell in the map with the given indices.
		// Params:
		//   column = The column of the cell.
		//   row = The row of the cell.
		//   value = The new value for the cell.
		//   resize = Whether to automatically resize the map if the selected indices are out of bounds.
		//   verbose = Whether to print the tilemap to the console after changing the map.
		BE_HL_API void SetCellValue(int column, int row, int value, bool resize = false, bool verbose = false);

		// Return the name of the tilemap.
		BE_HL_API const std::string& GetName() const;

		// Sets the name of the tilemap.
		BE_HL_API void SetName(const std::string& name);

		// Resizes the map based on the given parameters
		// Params:
		//   width = The new width of the map.
		//   height = The new height of the map.
		//   xShift = Amount to shift elements horizontally.
		//   yShift = Amount to shift elements vertically.
		BE_HL_API void Resize(unsigned width, unsigned height, int xShift = 0, int yShift = 0);

		// Resets all tiles to 0.
		// WARNING: This is permanent!
		BE_HL_API void Clear();

		// Shrinks map so that any columns or rows on the edge of the map
		// that are completely empty are removed.
		BE_HL_API void ShrinkToFit();

		// Add a game object to the map.
		// Params:
		//   object = The game object being added to the map.
		//   x = The column in which to place the object.
		//   y = The row in which to place the object.
		BE_HL_API void AddObject(GameObject* object, int x, int y);

		// Remove an object from the map.
		// Params:
		//   x = The column in which to place the object.
		//   y = The row in which to place the object.
		// Returns:
		//   The object that was removed, or nullptr if no object was at that location.
		BE_HL_API GameObject* RemoveObject(int x, int y);

		// Retrieves the current list of objects in the map
		BE_HL_API const Array<ObjectInMap>& GetObjects() const;

		// Loads object data from a file.
		// Params:
		//   stream = The stream for the file we want to read from.
		BE_HL_API virtual void Deserialize(FileStream& stream);

		// Saves object data to a file.
		// Params:
		//   stream = The stream for the file we want to write to.
		BE_HL_API virtual void Serialize(FileStream& stream) const;

		// Return the constant representing an invalid index for the tilemap.
		BE_HL_API static const int InvalidIndex();

		// Output operator for Tilemap
		BE_HL_API friend std::ostream& operator<<(std::ostream& stream, const Tilemap& map);

		// Use this to manage sprite source resources!
		BE_HL_API static TilemapManager& GetTilemapManager();

	private:
		//------------------------------------------------------------------------------
		// Private Variables:
		//------------------------------------------------------------------------------

		// Dimensions of the map
		unsigned width;
		unsigned height;

		// Current offset
		int offsetX;
		int offsetY;

		// The map data (a 2D array)
		int** data;

		// Objects in map
		Array<ObjectInMap> objects;

		// Filename
		std::string name;

		static TilemapManager tilemapManager;
		static const int invalidIndex;
	};

	//------------------------------------------------------------------------------
	// Global Functions:
	//------------------------------------------------------------------------------

	#define ResourceGetTilemap(t) Tilemap::GetTilemapManager().GetResource(t)
}

//------------------------------------------------------------------------------
