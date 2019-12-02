//------------------------------------------------------------------------------
//
// File Name:	Array.h
// Author(s):	Jeremy Kings (j.kings)
// Project:		BetaFramework
// Course:		WANIC VGP2 2018-2019
//
// Copyright © 2019 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

// No includes, no error checking, no nothing. 
// Fast, but dangerous! Use at your own risk.

//------------------------------------------------------------------------------

namespace Beta
{
	//------------------------------------------------------------------------------
	// Public Structures:
	//------------------------------------------------------------------------------

	template<typename ValueType>
	class Array
	{
	public:
		//------------------------------------------------------------------------------
		// Forward Declarations:
		//------------------------------------------------------------------------------

		typedef ValueType* ValuePointer;
		typedef ValueType& ValueReference;
		typedef const ValueType& ConstValueReference;
		typedef ValuePointer Iterator;
		class ReverseIterator;

		//------------------------------------------------------------------------------
		// Public Functions:
		//------------------------------------------------------------------------------

		// Constructors/Destructors
		Array()
			: data(nullptr), size(0), capacity(0)
		{
		}

		Array(const Array& other)
			: data(nullptr), size(0), capacity(0)
		{
			ReplaceWith(other);
		}

		Array(size_t size_)
			: data(nullptr), size(0), capacity(0)
		{
			Resize(size_);
		}

		~Array()
		{
			delete[] data;
		}

		// Add an element to the end of the array.
		void PushBack(ConstValueReference item)
		{
			if (size == capacity)
				Grow();

			data[size] = item;
			++size;
		}

		// Removes the last element from the array.
		void PopBack()
		{
			if (size == 0)
				return;
			--size;
		}

		// Clear the contents of the array, setting size to 0.
		void Clear()
		{
			size = 0;
		}

		// Increase the capacity of the array to the desired amount.
		void Reserve(size_t capacity_)
		{
			// Do nothing if requested capacity is not greater than current
			if (capacity >= capacity_)
				return;

			// Double capacity
			capacity = capacity_;
			ValuePointer newData = new ValueType[capacity];
			// Move data
			for (size_t i = 0; i < size; ++i)
			{
				newData[i] = data[i];
			}
			delete[] data;
			data = newData;
		}

		// Set the size of the array to the desired amount, reallocating if necessary.
		void Resize(size_t size_)
		{
			// Re-allocate only if necessary
			if (capacity < size_)
			{
				capacity = size_;
				ValuePointer newData = new ValueType[capacity];
				// Move data
				for (size_t i = 0; i < size; ++i)
				{
					newData[i] = data[i];
				}
				delete[] data;
				data = newData;
			}

			// Set size to new value
			size = size_;
		}

		// Remove the given element from the array.
		Iterator Erase(Iterator location)
		{
			if (location == End())
				return End();

			for (auto it = location; it != End() - 1; ++it)
			{
				*it = *(it + 1);
			}
			--size;

			return location;
		}

		ReverseIterator Erase(ReverseIterator location)
		{
			if (location == ReverseEnd())
				return ReverseEnd();

			for (auto it = &*location; it != End() - 1; ++it)
			{
				*it = *(it + 1);
			}
			--size;

			return location + 1;
		}

		// Get the position of the given element in the array.
		// Returns an iterator equal to End if the item is not found.
		Iterator Find(ConstValueReference item) const
		{
			for (auto it = Begin(); it != End(); ++it)
			{
				if (*it == item)
					return it;
			}
			return End();
		}

		// Replace each element in the array with the given value.
		void Fill(ConstValueReference item)
		{
			for (auto it = Begin(); it != End(); ++it)
			{
				*it = item;
			}
		}

		// Return the amount of items the array can store without needing to reallocate.
		size_t Capacity() const 
		{
			return capacity;
		}

		// Return the current number of elements in the array.
		size_t Size() const
		{
			return size;
		}

		// Return true if there are no elements in the array, false otherwise.
		bool IsEmpty() const
		{
			return size == 0;
		}

		// Return a pointer to the underlying array data.
		const ValuePointer Data() const
		{
			return data;
		}

		// Return an iterator to the first element of the array.
		Iterator Begin() const
		{
			return &data[0];
		}

		// Return an iterator to one after the last element of the array.
		Iterator End() const
		{
			return &data[size];
		}

		// Return the first element in the array.
		ValueReference Front() const
		{
			return *Begin();
		}

		// Return the last element in the array.
		ValueReference Back() const
		{
			return *(End() - 1);
		}

		ReverseIterator ReverseBegin() const
		{
			return ReverseIterator(End() - 1);
		}

		ReverseIterator ReverseEnd() const
		{
			return ReverseIterator(Begin() - 1);
		}

		// Operators
		Array& operator=(const Array& rhs)
		{
			if (this != &rhs)
				ReplaceWith(rhs);

			return *this;
		}

		ConstValueReference operator[](size_t index) const
		{
			return data[index];
		}

		ValueReference operator[](size_t index)
		{
			return data[index];
		}

		//------------------------------------------------------------------------------
		// Public Inner Structures:
		//------------------------------------------------------------------------------

		class ReverseIterator
		{
		public:
			ReverseIterator(Iterator it)
				: it(it)
			{
			}

			ValueReference operator*() const
			{
				return *it;
			}

			ReverseIterator operator+(int amount) const
			{
				return ReverseIterator(it - amount);
			}

			ReverseIterator operator-(int amount) const
			{
				return ReverseIterator(it + amount);
			}

			ReverseIterator& operator++()
			{
				--it;
				return *this;
			}

			ReverseIterator operator++(int)
			{
				ReverseIterator old(*this);
				++(*this);
				return old;
			}

			ReverseIterator& operator--()
			{
				++it;
				return *this;
			}

			ReverseIterator operator--(int)
			{
				ReverseIterator old(*this);
				--(*this);
				return old;
			}

			bool operator==(const ReverseIterator& other)
			{
				return other.it == it;
			}

			bool operator!=(const ReverseIterator& other)
			{
				return other.it != it;
			}

		private:
			Iterator it;
		};

	private:
		//------------------------------------------------------------------------------
		// Private Functions:
		//------------------------------------------------------------------------------

		// Replace the array's data with the data of another array.
		void ReplaceWith(const Array& other)
		{
			// Remove existing data
			Clear();

			// Re-allocate only if necessary
			if (capacity < other.size)
			{
				delete[] data;
				capacity = other.size;
				data = new ValueType[capacity];
			}

			for (auto it = other.Begin(); it != other.End(); ++it)
			{
				PushBack(*it);
			}
		}

		// Increase the capacity of the array.
		void Grow()
		{
			// Double capacity
			capacity = capacity > 0 ? capacity * 2 : 1;
			ValuePointer newData = new ValueType[capacity];
			// Move data
			for (size_t i = 0; i < size; ++i)
			{
				newData[i] = data[i];
			}
			delete[] data;
			data = newData;
		}

		//------------------------------------------------------------------------------
		// Private Variables:
		//------------------------------------------------------------------------------

		size_t size;
		size_t capacity;
		ValuePointer data;
	};
}

//------------------------------------------------------------------------------
