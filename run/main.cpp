#include "MagicSquare.h"
#include <iostream>

int main() {
	size_t input;
	std::cin >> input;
	std::vector<std::vector<int>> numbers(input, std::vector<int>(input));
	MagicSquare a = MagicSquare(input, numbers);
	a.output();
	system("pause");
	std::cin.get();
	return 0;
}