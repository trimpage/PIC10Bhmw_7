//MagicSquare.h

#ifndef MAGICSQUARE
#define MAGICSQUARE
#include <iostream>
#include <string>
#include <vector>

class MagicSquare {
public:
	//constructors
	MagicSquare(const size_t& _size, const std::vector<std::vector<int>>& _numbers);

	//operator >> overload
	friend std::istream& operator>>(std::istream& inStream, std::vector<std::vector<int>>& _numbers);








	void output() const {
		for (size_t i = 0, j = size; i < j; ++i) {
			for (size_t k = 0; k < j; ++k) {
				std::cout << numbers[i][k];
			}
			std::cout << '\n';
		}
	}



private:
	//size variable
	size_t size;

	//vector of vector of ints, stores square values
	std::vector<std::vector<int>> numbers;
};

#endif	
