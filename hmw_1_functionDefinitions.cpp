//hmw_1_functionDefinitions.cpp

#include <iostream>
#include <string>
#include <vector>
#include "hmw_1_functionDeclarations.h"

void generateBoard(std::vector<std::string>& board) {
	//sets the first row of the board
	board.push_back(" 1 2 3 \n");

	//store the next three rows into the vector
	for (int i = 1; i < 4; ++i) {
		board.push_back(std::to_string(i) + " | |\n -----\n"); 
	}

	//output the board into the console
	for (size_t j = 0; j < board.size(); ++j) {
			std::cout << board[j]; 
	}
}

std::vector<int> startTurn(const std::string name) {
	std::cout << "It is " << name << "'s turn. \nWhere would you like to play? Enter your row position and column position: row col: ";

	//store the user inputted coordinates into a string then cast them into a vector of ints to be used to update the board later
	std::string input;
	std::vector<int> coordinates;
	std::getline(std::cin, input);
	coordinates.push_back(static_cast<int>(input[0]));
	coordinates.push_back(static_cast<int>(input[2])); 

	return coordinates;
}

void updateBoard(int& turn, std::vector<std::string>& board, const std::vector<int> coordinates) {
	//create a new string representing row to be updated
	std::string update = board[coordinates[0]];
	
	//if even turn, update row element with X, otherwise with O
	if ((turn % 2) == 0) {
		update[coordinates[2]] = 'X';
	}
	else {
		update[coordinates[2]] = 'O';
	}

	//update board vector with new row
	board[coordinates[0]] = update;

	//increase turn by 1
	++turn;
}