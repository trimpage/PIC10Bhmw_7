//Solve.cpp

#include "MagicSquare.h"

/*
operator >> overload for writing to vector from user input stream
@param inStream: input stream, typically std::cin, to read from
@param _numbers: vector to write to
@return: returns input stream
*/
std::istream& operator>>(std::istream& inStream, std::vector<std::vector<int>>& _numbers);

/*
operator << overload for outputting magic square vector
@param inStream: output stream, typically std::cout, to output from
@param _numbers: vector of magic number to output
@return: returns output stream
*/
std::ostream& operator<<(std::ostream& outStream, const std::vector<std::vector<int>>& _numbers);

int main() {
	//create size_t variable for user inputted size
	size_t input;
	std::cout << "Enter a square size: ";
	std::cin >> input;

	//create vector for numbers and initialize them all to 0
	std::vector<std::vector<int>> numbers (input, std::vector<int>(input));

	//obtain user constraints
	std::cout << "Enter square format:\n\n";
	std::cin >> numbers;

	//input size squared variable
	size_t inputSquared = static_cast<size_t>(pow(input, 2));

	//create target sum with input size
	int targetSum = static_cast<int>((input * (inputSquared + 1)) / 2);

	//create the square object
	MagicSquare a = MagicSquare(input, inputSquared, targetSum, numbers);
	
	//copy unused numbers set
	std::set<int> unusedSet = a.get_unused();

	//create vector with unused numbers from set so we can swap values when solving
	std::vector<int> unused(unusedSet.begin(), unusedSet.end());

	//solve square object
	size_t considered = 0;
	a.solveSquare(considered, unused);
	std::cout << "Solving complete!\nThere were " << a.get_count() << "solutions!";

	std::cin.get();
	return 0;
}