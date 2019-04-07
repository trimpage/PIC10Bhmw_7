//Player.h

#ifndef PLAYER
#define PLAYER
#include <string>

//class for player object
class Player { 
public: 
	//constructor using name
	Player(std::string name);

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
	//string to store player name
	std::string name; 
	//int to store player score
	int score;
};

#endif	
