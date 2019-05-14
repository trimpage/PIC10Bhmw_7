//Solve.cpp

#include "MagicSquare.h"

std::istream& operator>>(std::istream& inStream, std::vector<std::vector<int>>& _numbers) {
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
}

int main() {
	//create size_t variable for user inputted size
	size_t input;
	std::cout << "Enter a square size: ";
	std::cin >> input;

	//create vector to pass into square with user inputted size
	std::vector<std::vector<int>> numbers (input, std::vector<int>(input));

	//obtain user constraints
	std::cout << "Enter square format:\n";
	std::cin >> numbers;

	//create the square object
	MagicSquare a = MagicSquare(input, numbers);
	a.output();


	system("pause");
	std::cin.get();
	return 0;
}