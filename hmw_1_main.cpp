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

	
	//currentRound keeps track of the rounds so the while loop runs that many rounds
	int currentRound = 0;
	//currentTurn is used to keep track of alternating turns so the correct player is playing each round
	int currentTurn = 0;

	//while loop so that game loops until number of inputted rounds are played
	while (currentRound < numberOfRounds) {
		//play round
		std::vector<std::string> gameBoard = generateBoard();
		startRound(currentTurn, gameBoard, player1, player2);
		++currentRound;
	}

	//declare a winner or tie after all rounds have been played
	checkWinner(player1, player2);
	return 0;
}
