//hmw_1_functionDeclarations.h

#include <iostream>
#include <string>
#include <vector>
#include "Player.h"

/**
generates tic tac toe board vector
@return: returns vector containing board
*/
std::vector<std::string> generateBoard();

/**
prints game board into console
@param board: game board vector to be printed
*/
void printBoard(const std::vector<std::string>& board);

/**
updates the game board with X or O at user selected coordinates
@param turn: int counter for the current turn, will be updated each time the function is run
@param counter: counter for keeping track of number of moves to see if there's a tie
@param board: board vector that will be updated with the new turn
@param coordinates: vector containing user inputted coordinates
*/
void updateBoard(int& turn, int& counter, std::vector<std::string>& board, const std::vector<int>& coordinates);


/**
states who's turn it is and asks where they want to play
@param player: player who's turn it is
*/
std::vector<int> startTurn(const Player& player);

/**
plays the current turn, which includes starting the turn, getting input, updating the board vector, printing the new board, and checking if anyone has won
@param turn: int counter to keep track of who's turn it is
@param counter: counter for keeping track of number of moves to see if there's a tie
@param hasSomeoneWon: bool to check if anyone has won, will be passed into checkWin function
@param board: game board vector that is being played with
@param player: player object who's turn it is
*/
void playTurn(int& turn, int& counter, bool& hasSomeoneWon, std::vector<std::string>& board, Player& player);

/**
checks to see if there is a winner and updates the bool accordingly
@param hasSomeoneWon: bool to be updated if someone wins
@param board: game board to be checked
*/
void checkWin(bool& hasSomeoneWon, const std::vector<std::string>& board);

/**
output scores at end of round
@param player1: first player object
@param player2: second player object
*/
void outputScores(Player& player1, Player& player2);

/**
starts the round and loops through the turns until someone wins or there is a tie
@param turn: int counter for current turn to keep track of who's turn it is
@param board: game board to be played with
@param player1: first player object
@param player2: second player object
*/
void startRound(int& turn, std::vector<std::string>& board, Player& player1, Player& player2);

/**
checks to see who won the overall game or if it was a tie
@param player1: first player object
@param player2: second player object
*/
void checkWinner(const Player& player1, const Player& player2);
