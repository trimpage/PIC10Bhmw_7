//MagicSquare.h

#ifndef MAGICSQUARE
#define MAGICSQUARE
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>

class MagicSquare {
public:
	//constructors
	MagicSquare(const size_t& _size, const int& _targetSum, const std::vector<std::vector<int>>& _numbers);

	/*
	function to set number at given index
	@param number: number to set at given index
	@param index: vector containing index to set number at
	*/
	void setNumber(const int& number, const std::vector<int>& index);

	/*
	function to solve given square
	@param considered: number of slots in square already considered
	*/
	void solveSquare(size_t considered);

	/*
	function to check if magic square is empty at given position
	@param row: row of number to check
	@param column: column of number to check
	@return: returns bool of whether position is empty or not
	*/
	bool empty(size_t row, size_t column) const;

	/*
	function to check if magic square already contains a number
	@param number: number to check for
	@return: returns bool of whether number is taken or not
	*/
	bool taken(int number) const;

	/*
	function to check if rows/columns of vector are valid
	@param _numbers: vector to check
	@return: returns bool of whether row is valid or not
	*/
	bool checkRow() const;

	/*
	function to check if complete magic square is valid based on it's vector
	@param _numbers: vector to check
	@return: returns bool of whether square is valid or not
	*/
	bool checkValid() const;

	/*
	function to compute sum of row in square
	@param rowNumber: index of row to be checked
	@return: returns sum of given row
	*/
	int rowSum(size_t rowNumber) const;

	/*
	function to compute sum of column in square
	@param columnNumber: index of column to be checked
	@return: returns sum of given column
	*/
	int columnSum(size_t columnNumber) const;

	/*
	function to compute sum of diagonal in square
	@param diagonalNumber: index of diagonal to be checked, 0 left to right and 1 for right to left
	@return: returns sum of given diagonal
	*/
	int diagonalSum(size_t diagonalNumber) const;

	/*
	function to get number at given index
	@param index: vector containing index to get number from
	@return: returns int at given index
	*/
	int get_number(const std::vector<int>& index) const;

	/*
	function to get square vector
	@return: vector of numbers in magic square
	*/
	std::vector<std::vector<int>> get_numbers() const;

private:
	//valid solution count
	int solutionCount;

	//size variable
	const size_t size;

	//target sum variable
	const int targetSum;

	//vector of vector of ints, stores square values
	std::vector<std::vector<int>> numbers;

	//set of used numbers
	std::set<int> takenNumbers;

	//set of fixed indices
	std::set<std::vector<size_t>> fixedIndices;
};

#endif	
