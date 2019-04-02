//Player.h
#ifndef PLAYER
#define PLAYER
#include <string>

class Player { //class for player object
public: 
	Player(std::string name); //constructor using name and score

	/**
	function to increase winner's score
	*/
	void updateScore();

	/**
	returns the player's name
	@return player's name
	*/
	std::string getName() const; 

	/**
	returns the player's score
	@return player's score
	*/
	int getScore() const;

private:
	std::string name; //string to store player name
	int score; //int to store player score
};

#endif	
