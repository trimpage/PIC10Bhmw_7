/*

Homework 1
Arian Owji
604649619

*/

#include <iostream>
#include "Player.h"
#include "hmw_1_functionDeclarations.h"

int main() {
	int numberOfRounds;

	std::cout << "This is a Tic Tac Toe game! \nHow many rounds would you like to play? ";
	std::cin >> numberOfRounds;
	std::cin.ignore(1000, '\n');

	std::string name1;
	std::cout << "Please enter the name of player 1: ";
	std::getline(std::cin, name1);
	Player player1 = Player(name1);

	std::string name2;
	std::cout << "Thanks. Please enter the name of player 2: ";
	std::getline(std::cin, name2);
	Player player2 = Player(name2);

	std::cout << "Let the game begin! \n";

	generateBoard();

	return 0;
}
