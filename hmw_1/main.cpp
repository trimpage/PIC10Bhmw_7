/*

Homework 1
Arian Owji
604649619

*/

#include <iostream>
#include "Player.h"

int main() {
	int numberOfRounds;

	std::cout << "This is a Tic Tac Toe game! \n How many rounds would you like to play?";
	std::cin >> numberOfRounds;

	std::string name1;
	std::cout << "Please enter the name of player 1: ";
	std::getline(std::cin, name1);
	Player player1 = Player(name1);

	std::string name2;
	std::cout << "Thanks. Please enter the name of player 2: ";
	std::getline(std::cin, name2);
	Player player2 = Player(name2);
}
