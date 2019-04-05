//hmw_1_functionDefinitions.cpp

#include "hmw_1_functionDeclarations.h"

std::vector<std::string> generateBoard() {
	std::vector<std::string> board;

	//sets the first row of the board
	board.push_back("\n 1 2 3 \n");

	//store the next three rows into the vector
	for (int i = 1; i < 4; ++i) {
		board.push_back(std::to_string(i) + " | | \n -----\n"); 
	}

	return board;
}

void printBoard(const std::vector<std::string>& board) {
	//output board into console
	for (size_t i = 0; i < board.size(); ++i) {
		std::cout << board[i];
	}
}

void updateBoard(int& turn, std::vector<std::string>& board, const std::vector<int>& coordinates) {
	//create a new string representing row to be updated
	std::string update = board[coordinates[0]];
	
	//if even turn, update row element with X, otherwise with O. multiply coordinate by 2 and subtract 1 to get proper string element
	if ((turn % 2) == 0) {
		update[(2 * coordinates[1]) - 1] = 'x';
	}
	else {
		update[(2 * coordinates[1]) - 1] = 'o';
	}

	//update board vector with new row
	board[coordinates[0]] = update;

	//increase turn by 1
	turn++;
}

std::vector<int> startTurn(const Player& player) {
	std::cout << "\nIt is " << player.getName() << "'s turn. \nWhere would you like to play? Enter your row position and column position: row col: ";

	//store the user inputted coordinates into a string then cast them into a vector of ints to be used to update the board later
	std::string input;
	std::vector<int> coordinates;
	std::getline(std::cin, input);
	coordinates.push_back(static_cast<int>(input[0] - '0'));
	coordinates.push_back(static_cast<int>(input[2] - '0'));

	return coordinates;
}

void playTurn(int& turn, bool& hasSomeoneWon, std::vector<std::string>& board, Player& player) {
	//start the first turn and get the coordinates the first player wants to play
	std::vector<int> inputtedCoordinates = startTurn(player);

	//update the board with that player's selection
	updateBoard(turn, board, inputtedCoordinates);

	//print new updated board
	printBoard(board);

	//check for a winner
	checkWin(hasSomeoneWon, board);
}


void checkWin(bool& hasSomeoneWon, const std::vector<std::string>& board) {
	//create strings for each board row to be checked
	std::string row1 = board[1];
	std::string row2 = board[2];
	std::string row3 = board[3];

	//go through the coordinates for each winning combination and check if they all have the same value, meaning someone has won
	if (((row1[1] == 'x') || (row1[1] == 'o')) && (row1[1] == row1[3]) && (row1[3] == row1[5])) {
		hasSomeoneWon = true;
	}
	else if (((row2[1] == 'x') || (row2[1] == 'o')) && (row2[1] == row2[3]) && (row2[3] == row2[5])) {
		hasSomeoneWon = true;
	}
	else if (((row3[1] == 'x') || (row3[1] == 'o')) && (row3[1] == row3[3]) && (row3[3] == row3[5])) {
		hasSomeoneWon = true;
	}
	else if (((row1[1] == 'x') || (row1[1] == 'o')) && (row1[1] == row2[1]) && (row2[1] == row3[1])) {
		hasSomeoneWon = true;
	}
	else if (((row1[3] == 'x') || (row1[3] == 'o')) && (row1[3] == row2[3]) && (row2[3] == row3[3])) {
		hasSomeoneWon = true;
	}
	else if (((row1[5] == 'x') || (row1[5] == 'o')) && (row1[5] == row2[5]) && (row2[5] == row3[5])) {
		hasSomeoneWon = true;
	}
	else if (((row1[1] == 'x') || (row1[1] == 'o')) && (row1[1] == row2[3]) && (row2[3] == row3[5])) {
		hasSomeoneWon = true;
	}
	else if (((row1[5] == 'x') || (row1[5] == 'o')) && (row1[5] == row2[3]) && (row2[3] == row3[1])) {
		hasSomeoneWon = true;
	}
	else {
		hasSomeoneWon = false;
	}
}

void outputScores(Player& player1, Player& player2) {
	//output scores at end of round
	std::cout << "Presently, " << player1.getName() << " has " << player1.getScore() << " points and " << player2.getName() << " has " << player2.getScore() << " points.\n";
}

void startRound(std::vector <std::string>& board, Player& player1, Player& player2) {
	//declare empty vector for the board and use functions to fill it and output the board
	printBoard(board);

	//set bool for if someone has won or not
	bool didSomeoneWin = false;

	//set int for turn count
	int currentTurn = 0;

	//while no one has won yet, start the turn and play the game
	while (didSomeoneWin == false) {
		//if even turn, player 1 plays, else player 2 plays
		if ((currentTurn % 2) == 0) {
			playTurn(currentTurn, didSomeoneWin, board, player1);
		}
		else {
			playTurn(currentTurn, didSomeoneWin, board, player2);
		}

		//in case all possible turns are played and it is a tie, output current scores
		if (currentTurn == 9) {
			std::cout << "Tie! No one wins!\n";
			outputScores(player1, player2);
			break;
		}

		//if someone wins, declare it and update the player's score, output current scores
		if ((didSomeoneWin == true) && ((currentTurn % 2) == 1)) {
			std::cout << '\n' << player1.getName() << " won the round!\n";
			player1.updateScore();
			outputScores(player1, player2);
		}
		else if (didSomeoneWin == true) {
			std::cout << '\n' << player2.getName() << " won the round!\n";
			player2.updateScore();
			outputScores(player1, player2);
		}
	}
}