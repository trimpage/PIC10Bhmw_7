//VectorString.h

#ifndef VECTORSTRING
#define VECTORSTRING
#include <string>
#include <memory>
#include <iostream>

//class for vector string, within namespace pic10b
namespace pic10b {
	class VectorString {
	public:
		//default constructor
		VectorString();

		//constructor with size
		VectorString(size_t size);
		
		//constructor with size and string to initialize
		VectorString(size_t size, const std::string& inputString);

		//copy constructor
		VectorString(const VectorString& oldVector);

		//move constructor
		VectorString(VectorString&& oldVector);

		/**
		copy assignment operator to copy a vector to another
		@param oldVector: vector to be copied
		@return: new vector, copied from the old one, to be assigned
		*/
		VectorString& operator = (const VectorString& oldVector);

		/**
		move assignment operator to move a vector to another
		@param oldVector: vector to be moved from
		@return: new vector that old vector values were moved to
		*/
		VectorString& operator = (const VectorString&& oldVector);

		/**
		size member function that returns vector size
		@return: size of vector
		*/
		size_t size() const;

		/**
		capacity member function that returns vector capacity
		@return: capacity of vector
		*/
		size_t capacity() const;

		/**
		push back function that adds a new string to the end of the vector, capacity permitting, otherwise it will update the capacity and then add it
		@param inputString: new string to be pushed back
		*/
		void push_back(const std::string& inputString);

		/**
		pop back function that removes the last element in the vector, based on the size
		*/
		void pop_back();

		/**
		delete at function that delete the element at the given index and shifts back all the other elements
		@param index: index of element to be deleted
		*/
		void deleteAt(const size_t& index);

		/**
		insert at function that inserts the given input at the given index and shifts all other elements accordingly
		@param index: index where new element will be inserted
		@param inputString: new string to be inserted
		*/
		void insertAt(const size_t& index, const std::string& inputString);

		/**
		at function that returns the element at given index
		@param index: index value to look at
		@return: element at index value
		*/
		std::string& at(const size_t& index) const;
	private:
		//vector size variable
		size_t vec_size;

		//vector capacity variable
		size_t vec_capacity;

		//unqiue pointer variable 
		std::unique_ptr<std::string[]> stringPointer;
	};


}
#endif	
