//hmw_1_functionDefinitions.cpp

#include <iostream>
#include <string>
#include "hmw_1_functionDeclarations.h"

void generateBoard() {
	std::cout << " 1 2 3 \n";

	for (int i = 1; i < 4; ++i) {
		std::cout << i << " | |\n -----\n";
	}
}

void startTurn(const std::string name) {
	std::cout << "It is " << name << "'s turn. \nWhere would you like to play> Enter your row position and column position: row col: "
}