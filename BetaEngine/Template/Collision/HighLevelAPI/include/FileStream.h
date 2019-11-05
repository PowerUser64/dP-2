//------------------------------------------------------------------------------
//
// File Name:	FileStream.h
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

#include <exception>
#include <fstream>

//------------------------------------------------------------------------------

namespace Beta
{
	//------------------------------------------------------------------------------
	// Forward References:
	//------------------------------------------------------------------------------
	
	class Vector2D;

	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	// Exception class for problems encountered while reading/writing from files
	class FileStreamException : public std::exception
	{
	public:
		// Constructor
		// Params:
		//   fileName = The name of file that the stream was trying to read or write.
		//   errorDetails = The specific details of the error that occurred.
		BE_HL_API FileStreamException(const std::string& fileName, const std::string& errorDetails);
	};

	enum StreamOpenMode
	{
		OM_Read,
		OM_Write
	};

	// FileStream class - reads/writes data object data to/from files
	class FileStream
	{
	public:
		// Opens a file for loading.
		// Params:
		//   filename = The name of the file to open.
		//   mode = Whether to open the file for reading/writing, etc.
		BE_HL_API FileStream(const std::string& filename, StreamOpenMode mode);

		// Closes the currently open file.
		BE_HL_API ~FileStream();

		// Begins a new scope. When writing, outputs a curly brace and increases the tab count.
		// When reading, looks for an end curly brace, causing an exception if it does not exist.
		BE_HL_API void BeginScope();

		// Ends the current scope. When writing, outputs an end curly brace and decreases tab count.
		// When reading, looks for an end curly brace, causing an exception if it does not exist.
		BE_HL_API void EndScope();

		// Writes a variable name and value to the currently open file.
		// Params:
		//   name = The name of the variable that will be written to the file.
		//   variable =  The value of the variable that will be written to the file.
		template<typename T>
		void WriteVariable(const std::string& name, const T& variable)
		{
			CheckFileOpen();

			for (unsigned i = 0; i < indentLevel; ++i)
				stream << tab;
			stream << name << " : " << variable << std::endl;
		}

		// Writes a variable name and array to the currently open file.
		// Params:
		//   name = The name of the array that will be written to the file.
		//   variable = The value of the variable that will be written to the file.
		//   width = The width of the array.
		//   height = The height of the array.
		//   insertCommas = Whether to separate values in the array with commas.
		template<typename T>
		void WriteArrayVariable(const std::string& name, T** const array, size_t width,
			size_t height, bool insertCommas)
		{
			CheckFileOpen();

			for (unsigned i = 0; i < indentLevel; ++i)
				stream << tab;
			stream << name << " : " << std::endl;
			WriteArray(array, width, height, insertCommas);
		}

		// Writes a variable name and array to the currently open file.
		// Params:
		//   name = The name of the array that will be written to the file.
		//   variable = The value of the variable that will be written to the file.
		//   size = The number of elements in the array.
		//   insertCommas = Whether to separate values in the array with commas.
		template<typename T>
		void WriteArrayVariable(const std::string& name, T* const array,
			size_t size, bool insertCommas)
		{
			CheckFileOpen();

			for (unsigned i = 0; i < indentLevel; ++i)
				stream << tab;
			stream << name << " : " << std::endl;
			WriteArray(array, size, insertCommas);
		}

		// Writes a value to the currently open file.
		// Params:
		//   value =  The value that will be written to the file.
		template<typename T>
		void WriteValue(const T& value)
		{
			CheckFileOpen();

			for (unsigned i = 0; i < indentLevel; ++i)
				stream << tab;
			stream << value << std::endl;
		}

		// Writes an array to the currently open file.
		// Params:
		//   array =  The array that will be written to the file.
		//   width = The width of the array.
		//   height = The height of the array.
		//   insertCommas = Whether to separate values in the array with commas.
		template<typename T>
		void WriteArray(T** const array, size_t width, size_t height, bool insertCommas)
		{
			CheckFileOpen();

			BeginScope();

			std::string separator = " ";
			if (insertCommas)
				separator = ", ";

			for (size_t r = 0; r < height; ++r)
			{
				for (unsigned i = 0; i < indentLevel; ++i)
					stream << tab;

				for (size_t c = 0; c < width; ++c)
					stream << array[c][r] << separator;

				stream << std::endl;
			}

			EndScope();
		}

		// Writes an array to the currently open file.
		// Params:
		//   array =  The array that will be written to the file.
		//   width = The number of elements in the array.
		//   insertCommas = Whether to separate values in the array with commas.
		template<typename T>
		void WriteArray(T* const array, size_t size, bool insertCommas)
		{
			CheckFileOpen();

			BeginScope();

			std::string separator = " ";
			if (insertCommas)
				separator = ", ";

			for (unsigned j = 0; j < indentLevel; ++j)
				stream << tab;

			for (size_t i = 0; i < size; ++i)
				stream << array[i] << separator;

			stream << std::endl;

			EndScope();
		}

		// Reads the value of a variable with the given name from the currently open file.
		// Params:
		//   name = The name of the variable that should be read from the file.
		//   variable = The variable that should hold the value from the file.
		template<typename T>
		void ReadVariable(const std::string& name, T& variable)
		{
			CheckFileOpen();

			std::string nextWord;
			stream >> nextWord;

			if (nextWord != name)
				throw FileStreamException(filename, "Could not find variable " + name + " in file.");

			ReadSkip(':');
			stream >> variable;
		}

		// Reads the next value from the currently open file.
		// Params:
		//   value = The variable that should hold the value from the file.
		template<typename T>
		void ReadValue(T& value)
		{
			stream >> value;
		}

		// Reads the value of a array with the given name from the currently open file.
		// Params:
		//   name = The name of the array that should be read from the file.
		//   array = The array that should hold the value from the file.
		//   width = The width of the array.
		//   height = The height of the array.
		template<typename T>
		void ReadArrayVariable(const std::string& name, T** array, size_t width,
			size_t height)
		{
			CheckFileOpen();

			std::string nextWord;
			stream >> nextWord;

			if (nextWord != name)
				throw FileStreamException(filename, "Could not find variable " + name + " in file.");

			ReadSkip(':');
			ReadArray(array, width, height);
		}

		// Reads the value of a array with the given name from the currently open file.
		// Params:
		//   name = The name of the array that should be read from the file.
		//   array = The array that should hold the value from the file.
		//   size = The number of elements in the array.
		template<typename T>
		void ReadArrayVariable(const std::string& name, T* array,
			size_t size)
		{
			CheckFileOpen();

			std::string nextWord;
			stream >> nextWord;

			if (nextWord != name)
				throw FileStreamException(filename, "Could not find variable " + name + " in file.");

			ReadSkip(':');
			ReadArray(array, size);
		}

		// Reads the next value from the currently open file.
		// Params:
		//   array = The array that should hold the value from the file.
		//   width = The width of the array.
		//   height = The height of the array.
		template<typename T>
		void ReadArray(T** array, size_t width, size_t height)
		{
			T value;
			BeginScope();

			for (size_t r = 0; r < height; ++r)
			{
				for (size_t c = 0; c < width; ++c)
				{
					ReadValue(value);
					array[c][r] = value;
					ReadSkip(',', 0);
				}
			}

			EndScope();
		}

		// Reads the next value from the currently open file.
		// (Specialization for std::string)
		// Params:
		//   array = The array that should hold the value from the file.
		//   width = The width of the array.
		//   height = The height of the array.
		template<>
		void ReadArray(std::string** array, size_t width, size_t height)
		{
			std::string value;
			BeginScope();

			for (size_t r = 0; r < height; ++r)
			{
				for (size_t c = 0; c < width; ++c)
				{
					ReadValue(value);
					// Support for CSVs - remove comma if it exists
					value = value.substr(0, value.find(','));
					array[c][r] = value;
				}
			}

			EndScope();
		}

		// Reads the next value from the currently open file.
		// Params:
		//   array = The array that should hold the value from the file.
		//   size = The number of elements in the array.
		template<typename T>
		void ReadArray(T* array, size_t size)
		{
			T value;

			BeginScope();

			for (size_t i = 0; i < size; ++i)
			{
				ReadValue(value);
				array[i] = value;
				ReadSkip(',', 0);
			}

			EndScope();
		}

		// Reads the next value from the currently open file.
		// (Specialization for std::string)
		// Params:
		//   array = The array that should hold the value from the file.
		//   size = The number of elements in the array.
		template<>
		void ReadArray(std::string* array, size_t size)
		{
			std::string value;

			BeginScope();

			for (size_t i = 0; i < size; ++i)
			{
				ReadValue(value);
				// Support for CSVs - remove comma if it exists
				value = value.substr(0, value.find(','));
				array[i] = value;
			}

			EndScope();
		}

		// Reads a piece of text from the currently open file
		// and skips to the next word afterwards.
		// Params:
		//   text = The text to search for in the file.
		BE_HL_API void ReadSkip(const std::string& text);

		// Skips characters in the stream up until the next
		// occurrence of the given delimiter.
		//   delimiter = The delimiter to search for in the file.
		//   maxLookAhead = The maximum number of characters to extract while 
		//     looking for the given delimiter.
		BE_HL_API void ReadSkip(char delimiter, long long maxLookAhead
			= std::numeric_limits<std::streamsize>::max());

	private:
		//------------------------------------------------------------------------------
		// Private Functions:
		//------------------------------------------------------------------------------

		// Checks if the file was opened correctly. If not, throws an exception.
		BE_HL_API void CheckFileOpen();

		//------------------------------------------------------------------------------
		// Private Variables:
		//------------------------------------------------------------------------------

		std::fstream stream;	// The actual file stream
		std::string filename;	// File that was opened by the stream
		unsigned indentLevel;	// Number of tabs to print
		const char* tab = "\t";	// String to use for tabs
		StreamOpenMode mode;	// File read/write mode.
	};
}
