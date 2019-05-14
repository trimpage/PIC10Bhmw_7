//MagicSquare.cpp

#include "MagicSquare.h"

//MAGICSQUARE CLASS DEFINITIONS
//constructor
MagicSquare::MagicSquare(const size_t& _size, const std::vector<std::vector<int>>& _numbers) : size(_size), numbers(_numbers) {}

//operator >> overload
/*std::istream& operator>>(std::istream& inStream, std::vector<std::vector<int>>& _numbers) {
	//create size_t variables for number of rows and row size
	size_t numberOfRows = _numbers.size();
	size_t rowSize = _numbers[0].size();

	for (size_t i = 0; i < numberOfRows; ++i) {
		for (size_t j = 0; j < rowSize; ++j) {
			//input variable
			char input;
			
			//get values from user
			inStream >> input;

			//if input is *
			if (input == '*') {
				//discard and continue
				continue;
			}
			else {
				//else set vector value to user input
				_numbers[i][j] = (input - '0');
			}
		}
		std::cout << '\n';
	}
	return inStream;
}*/