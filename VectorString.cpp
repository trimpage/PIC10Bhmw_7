//VectorString.cpp

#include "VectorString.h"

//initializing default constructor
pic10b::VectorString::VectorString() : vec_size(0), vec_capacity(1), stringPointer(std::make_unique<std::string[]>(vec_capacity)) {}

//initializing size_t constructor
pic10b::VectorString::VectorString(size_t size) : vec_size(size), vec_capacity(2 * size), stringPointer(std::make_unique<std::string[]>(vec_capacity)) {
	//for loop to set vector elements to empty string
	for (size_t i = 0; i < vec_size; ++i) {
		stringPointer[i] = "";
	}
}

//initialize size and string constructor
pic10b::VectorString::VectorString(size_t size, const std::string& inputString) 
	: vec_size(size), vec_capacity(2 * size), stringPointer(std::make_unique<std::string[]>(vec_capacity)) {
	//for loop to set vector elements to inputted string
	for (size_t i = 0; i < vec_size; ++i) {
		stringPointer[i] = inputString;
	}
}

//initialize copy constructor
pic10b::VectorString::VectorString(const VectorString& copyVector) 
	: vec_size(copyVector.vec_size), vec_capacity(copyVector.vec_capacity), stringPointer(std::make_unique<std::string[]>(vec_capacity)) {
	//copy over values of each elements to new vector
	for (size_t i = 0; i < vec_size; ++i) {
		stringPointer[i] = copyVector.stringPointer[i];
	}
}

//initialize move constructor
pic10b::VectorString::VectorString(VectorString&& oldVector) 
	: vec_size(std::move(oldVector.vec_size)), vec_capacity(std::move(oldVector.vec_capacity)), stringPointer(std::move(oldVector.stringPointer)) {
}

//copy assignment operator
pic10b::VectorString& pic10b::VectorString::operator = (const VectorString& oldVector) {
	//copy as long as vectors aren't already the same
	if (this != &oldVector) {
		//copy size
		vec_size = oldVector.vec_size;
		
		//copy capacity
		vec_capacity = oldVector.vec_capacity;

		//make new string pointer and copy over old values
		stringPointer = std::make_unique<std::string[]>(vec_capacity);
		for (size_t i = 0; i < vec_size; ++i) {
			stringPointer[i] = oldVector.stringPointer[i];
		}
	}
	return *this;
}

//move assignment operator
pic10b::VectorString& pic10b::VectorString::operator = (const VectorString&& oldVector) {
	//move as long as vectors aren't already the same
	if (this != &oldVector) {
		//move size
		vec_size = std::move(oldVector.vec_size);

		//move capacity
		vec_capacity = std::move(oldVector.vec_capacity);

		//make new string pointer and move over old values
		stringPointer = std::make_unique<std::string[]>(vec_capacity);
		for (size_t i = 0; i < vec_size; ++i) {
			stringPointer[i] = std::move(oldVector.stringPointer[i]);
		}
	}
	return *this;
}

//size function
size_t pic10b::VectorString::size() const {
	return vec_size;
}

//capacity function
size_t pic10b::VectorString::capacity() const {
	return vec_capacity;
}

//push back function
void pic10b::VectorString::push_back(const std::string& inputString) {
	//check if the capacity is equal to the size, meaning the vector is full
	if (vec_size == vec_capacity) {
		//if it's full, then double the capacity
		vec_capacity *= 2;

		//now, make a temp pointer to store the old values and update the original pointer to a new pointer with larger capacity
		auto stringPointerTemp = stringPointer.release();
		stringPointer = std::make_unique<std::string[]>(vec_capacity);

		//for loop to copy temp values back into the original pointer
		for (size_t i = 0; i < vec_size; ++i) {
			stringPointer[i] = stringPointerTemp[i];
		}
	}
	//after checking if full - and if so, updating the capacity - insert the new value and update the size accordingly
	stringPointer[vec_size] = inputString;
	++vec_size;
}

//pop back function
void pic10b::VectorString::pop_back() {
	//decrement the size by 1 so that the last value is "removed"
	--vec_size;
}

//deleteAt fumction
void pic10b::VectorString::deleteAt(const size_t& index) {
	//for loop to iterate over indices and shift them back, deleting given index as well
	for (size_t i = index; i < vec_size; ++i) {
		stringPointer[i] = stringPointer[i + 1];
	}

	//decrement size by 1 to account for deletion
	--vec_size;
}

//insertAt function
void pic10b::VectorString::insertAt(const size_t& index, const std::string& inputString) {
	//check if vector is full
	if (vec_size == vec_capacity) {
		//if it's full, then double the capacity
		vec_capacity *= 2;

		//now, make a temp pointer to store the old values and update the original pointer to a new pointer with larger capacity
		auto stringPointerTemp = stringPointer.release();
		stringPointer = std::make_unique<std::string[]>(vec_capacity);

		//for loop to copy temp values back into the original pointer
		for (size_t i = 0; i < vec_size; ++i) {
			stringPointer[i] = stringPointerTemp[i];
		}
	}
	//after checking if full, push forward all old elements
	for (size_t i = vec_size; i > index; --i) {
		stringPointer[i] = stringPointer[i - 1];
	}

	//insert new string and increment size to accomodate
	stringPointer[index] = inputString;
	++vec_size;
}

//at function
std::string& pic10b::VectorString::at(const size_t& index) const {
	return stringPointer[index];
}
