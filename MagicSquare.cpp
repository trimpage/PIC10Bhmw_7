//MagicSquare.cpp

#include "MagicSquare.h"

//FREE FUNCTION DEFINITIONS
//operator >> overload
std::istream& operator>>(std::istream& inStream, std::vector<std::vector<int>>& _numbers) {
	//size of vector variable
	size_t vectorSize = _numbers.size();

	//for loop that goes through each row position using the number of rows, which equals the row size as well
	for (size_t i = 0; i < vectorSize; ++i) {
		for (size_t k = 0; k < vectorSize; ++k) {
			//input variable
			std::string input;

			//get values from user
			inStream >> input;

			//if input is *
			if (input == "*") {
				//ignore and continue
				continue;
			}
			else {
				//else set vector value to user input
				_numbers[i][k] = std::stoi(input);
			}
		}
	}

	//spacing
	std::cout << '\n';

	return inStream;
}

//operator << overload
std::ostream& operator<<(std::ostream& outStream, const std::vector<std::vector<int>>& _numbers) {
	//size of vector variable
	size_t vectorSize = _numbers.size();

	//for loop that goes through each row position using the number of rows, which equals the row size as well
	for (size_t i = 0; i < vectorSize; ++i) {
		for (size_t k = 0; k < vectorSize; ++k) {
			outStream << _numbers[i][k] << " ";
		}
		outStream << '\n';
	}

	//spacing
	std::cout << '\n';

	return outStream;
}

//MAGICSQUARE CLASS DEFINITIONS
//constructor
MagicSquare::MagicSquare(const size_t& _size, const size_t& _sizeSquared, const int& _targetSum, const std::vector<std::vector<int>>& _numbers) 
	: solutionCount(0), size(_size), sizeSquared(_sizeSquared), targetSum(_targetSum), numbers(_numbers) {
	//store numbers 1 through n^2 in set
	for (size_t i = 1; i < sizeSquared; ++i) {
		unusedNumbers.insert(static_cast<int>(i));
	}

	//remove taken numbers from set
	for (size_t i = 0; i < size; ++i) {
		for (size_t k = 0; k < size; ++k) {
			//if number at index is not 0
			if (numbers[i][k] != 0) {
				//remove from unused numbers
				unusedNumbers.erase(numbers[i][k]);

				//create vector for user inputted index and store to set of fixed indices
				std::vector<size_t> index = { i, k };
				fixedIndices.push_back(index);
			}
			//else continue
			else {
				continue;
			}
		}
	}
}

//set number function
void MagicSquare::setNumber(const int& number, const std::vector<int>& index) {
	numbers[index[0]][index[1]] = number;
}

//solve square function
void MagicSquare::solveSquare(size_t considered, std::vector<int> unused) {
	//size_t variable for size of unused numbers vector
	size_t sizeUnused = unused.size();

	//if we have considered every number possible
	if (considered == sizeUnused) {
		size_t count = 0;

		//for all indices of numbers
		for (size_t i = 0; i < size; ++i) {
			for (size_t j = 0; j < size; ++j) {
				//fixed indices size
				size_t fixed = fixedIndices.size();

				//search for fixed index
				for (size_t k = 0; k < fixed; ++k) {
					//if index is fixed
					if ((fixedIndices[k][0] == i) && (fixedIndices[k][1] == j)) {
						break;
					}
					//else continue
					else {
						continue;
					}
				}
				//if value in numbers is 0
				if (numbers[i][j] == 0) {
					//place in an unused number and increase count
					numbers[i][j] = unused[count];
					++count;
				}
			}
		}

		//if valid solution
		if (checkValid()) {
			std::cout << numbers;
			++solutionCount;
		}
		//else continue as normal, discarding the solution
	}
	else {
		for (size_t i = 0; i < size; ++i) {
			for (size_t j = 0; j < size; ++j) {
				//if slot is empty
				if (numbers[i][j] == 0) {
					//for unplaced elements
					for (size_t i = considered; i < sizeUnused; ++i) {
						//swap
						std::swap(unused[considered], unused[i]);

						//recursion
						solveSquare(++considered, unused);

						//undo swap
						std::swap(unused[considered], unused[i]);
					}
				}
				//else recursion
				else {
					//recursion
					solveSquare(++considered, unused);
				}
			}
		}
	}
}

//empty function
bool MagicSquare::empty(size_t row, size_t column) const {
	//if number at position is empty, return true
	if (numbers[row][column] == 0) {
		return true;
	}
	//else return false
	else {
		return false;
	}
}

//taken function 
bool MagicSquare::taken(int number) const {
	//if number count within set is 0, return true
	if (unusedNumbers.count(number) == 0) {
		return true;
	}
	//else return false
	else {
		return false;
	}
}

//check row function
bool MagicSquare::checkRow() const {
	//for each row
	for (size_t i = 0; i < size; ++i) {
		//row sum variable
		int _rowSum = rowSum(i);

		//if row sum is equal to target sum, continue
		if (_rowSum == targetSum) {
			continue;
		}
		//else return false
		else {
			return false;
		}
	}

	//for each column
	for (size_t i = 0; i < size; ++i) {
		//column sum variable
		int _columnSum = columnSum(i);

		//if column sum is greater than target sum, return false
		if (_columnSum > targetSum) {
			return false;
		}
		//else continue
		else {
			continue;
		}
	}
	//at this point, if we haven't returned false, must be true
	return true;
}

//check valid function
bool MagicSquare::checkValid() const {
	//if rows are checked to be true
	if (checkRow()) {
		//check that columns equal target sum
		for (size_t i = 0; i < size; ++i) {
			//column sum variable
			int _columnSum = columnSum(i);

			//if column sum is not equal to target sum, return false
			if (_columnSum != targetSum) {
				return false;
			}
			//else continue
			else {
				continue;
			}
		}
		
		//check diagonals, index is either 0 or 1
		for (size_t i = 0; i < 2; ++i) {
			//diagonal sum variable
			int _diagonalSum = diagonalSum(i);

			//if diagonal sum is not equal to target sum, return false
			if (_diagonalSum != targetSum) {
				return false;
			}
			//else continue
			else {
				continue;
			}
			
		}
		//at this point, if we haven't returned false, must be true
		return true;
	}
	//else square cannot be valid since checkRow was not true
	else {
		return false;
	}
}

//row sum function
int MagicSquare::rowSum(size_t rowNumber) const {
	//row sum variable
	int rowSum = 0;

	//calculate row sum
	for (size_t i = 0; i < size; ++i) {
		//add up row sum
		rowSum += numbers[rowNumber][i];
	}
	return rowSum;
}

//column sum function
int MagicSquare::columnSum(size_t columnNumber) const {
	//column sum variable
	int columnSum = 0;

	//calculate column sum
	for (size_t i = 0; i < size; ++i) {
		columnSum += numbers[i][columnNumber];
	}
	return columnSum;
}

//diagonal sum function
int MagicSquare::diagonalSum(size_t diagonalNumber) const {
	//diagonal sum variable
	int diagonalSum = 0;

	//calculate diagonal sum
	//if left diagonal, diagonalNumber == 0
	if (diagonalNumber == 0) {
		for (size_t i = 0; i < size; ++i) {
			diagonalSum += numbers[i][i];
		}
	}
	//else right diagonal
	else {
		for (size_t i = 0; i < size; ++i) {
			for (size_t j = 0; j < size; ++j) {
				if ((i + j) == (size - 1)) {
					diagonalSum += numbers[i][j];
				}
			}
		}
	}
	return diagonalSum;
}

//get count function
int MagicSquare::get_count() const {
	return solutionCount;
}

//get number function
int MagicSquare::get_number(const std::vector<int>& index) const {
	return numbers[index[0]][index[1]];
}

//get numbers function
std::vector<std::vector<int>> MagicSquare::get_numbers() const {
	return numbers;
}

//get unused function
std::set<int> MagicSquare::get_unused() const {
	return unusedNumbers;
}