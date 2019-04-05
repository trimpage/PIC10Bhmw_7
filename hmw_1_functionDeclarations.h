//hmw_1_functionDeclarations.h

/**
generates tic tac toe board
@param board: vector of strings that represent the game board
*/
void generateBoard(std::vector<std::string>& board);

/**
states who's turn it is and asks where they want to play
@param player: player who's turn it is
*/
std::vector<int> startTurn(const Player& player);

/**
updates the game board with X or O at user selected coordinates
@param turn: int counter for the current turn, will be updated each time the function is run
@param board: board vector that will be updated with the new turn
@param coordinates: vector containing user inputted coordinates
*/
void updateBoard(int& turn, std::vector<std::string>& board, const std::vector<int>& coordinates);
