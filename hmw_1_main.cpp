/*

Homework 1
Arian Owji
604649619

*/

#include <iostream>
#include <vector>
#include <string>
#include "Player.h"
#include "hmw_1_functionDeclarations.h"

int main() {
	//get the number of rounds the players want to play and clear the console input
	int numberOfRounds;
	std::cout << "This is a Tic Tac Toe game! \nHow many rounds would you like to play? ";
	std::cin >> numberOfRounds;
	std::cin.ignore(1000, '\n'); 

	//store player 1 name
	std::string name1;
	std::cout << "Please enter the name of player 1: ";
	std::getline(std::cin, name1);
	Player player1 = Player(name1);

	//store player 2 name
	std::string name2;
	std::cout << "Thanks. Please enter the name of player 2: ";
	std::getline(std::cin, name2);
	Player player2 = Player(name2);

	std::cout << "Let the game begin! \n";

	//declare empty vector for the board and use generate board function to fill it and output the board
	std::vector<std::string> gameBoard;
	generateBoard(gameBoard);

	//start the first turn and get the coordinates the first player wants to play
	int currentTurn = 0;


	updateBoard(currentTurn, gameBoard, )
	std::cin.get();

	return 0;
}
