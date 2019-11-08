//------------------------------------------------------------------------------
//
// File Name:	ResourceManager.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		BetaFramework
// Course:		CS230
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include <BetaObject.h>

#include <EngineCore.h>		// GetFilePath
#include <unordered_map>	// resources, creation functions

//------------------------------------------------------------------------------

namespace Beta
{
	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	template <typename ResourceType>
	class ResourceManager
	{
	public:
		//------------------------------------------------------------------------------
		// Public Typedefs:
		//------------------------------------------------------------------------------

		typedef std::shared_ptr<ResourceType> ResourcePtr;
		typedef std::weak_ptr<ResourceType> WeakResourcePtr;

		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		// Constructor
		// Params:
		//   relativePath = The assets subfolder where this resource type can be found.
		//	 fileExtension = The file extension used by this resource type.
		ResourceManager(const std::string& relativePath, const std::string& fileExtension = ".txt")
			: relativePath(relativePath), extension(fileExtension)
		{
		}

		// Destructor
		virtual ~ResourceManager()
		{
			Clear();
		}

		// Add a pre-existing resource to the manager.
		// Params:
		//   name = The name of the resource.
		//   data = A pointer to the resource.
		void Add(const std::string& name, ResourcePtr data)
		{
			// Make sure it's not already in the map
			auto foundResource = resources.find(name);
			if (foundResource != resources.end())
			{
				foundResource->second.reset();
				foundResource->second = data;
				return;
			}

			// Create the resource and add it to the map
			resources.emplace(name, WeakResourcePtr(data));
		}

		// Retrieve a resource required by a game object.
		// Params:
		//   name = The name of the resource.
		//   createIfNotFound = Whether to create/load the resource if it does not exist.
		ResourcePtr GetResource(const std::string& name, bool createIfNotFound = true)
		{
			ResourcePtr data = nullptr;

			auto foundResource = resources.find(name);
			if (foundResource != resources.end() && !foundResource->second.expired())
			{
				data = ResourcePtr(foundResource->second);
			}

			// Couldn't find existing resource
			if (data == nullptr && createIfNotFound)
			{
				// Attempt to creat/load resource with the given name
				data = Create(name);
				if (data.get() != nullptr)
				{
					resources.emplace(name, data);
				}
			}

			return data;
		}

		// Remove all resources from the manager.
		void Clear()
		{
			resources.clear();
		}

		// Return the path to this resource type.
		std::string GetFilePath() const
		{
			return EngineCore::GetInstance().GetFilePath() + relativePath;
		}

		// Return the file extension used by this resource type.
		// Ex: .txt, .png
		const std::string& GetFileExtension() const
		{
			return extension;
		}

	private:
		//------------------------------------------------------------------------------
		// Private Functions:
		//------------------------------------------------------------------------------

		// Disable copy and assign to prevent accidental copies
		ResourceManager(const ResourceManager&) = delete;
		ResourceManager& operator=(const ResourceManager&) = delete;

		virtual ResourcePtr Create(const std::string& name) = 0;

		//------------------------------------------------------------------------------
		// Private Variables:
		//------------------------------------------------------------------------------

		// Contains all resources
		std::unordered_map<std::string, WeakResourcePtr> resources;

		// Path to resources
		std::string relativePath;

		// File extension for this resource type
		std::string extension;
	};
}

//------------------------------------------------------------------------------
