//Solve.cpp

#include "MagicSquare.h"

int main() {
	//create size_t variable for user inputted size
	size_t input;
	std::cout << "Enter a square size: ";
	std::cin >> input;

	//create vector to pass into square with user inputted size
	std::vector<std::vector<int>> numbers = { {1,2}, {3,4} }; //(input, std::vector<int>(input));

	//obtain user constraints
	std::cout << "Enter square format:\n";
	std::cin >> numbers;

	//create the square object
	MagicSquare a = MagicSquare(input, numbers);
	




	system("pause");
	std::cin.get();
	return 0;
}