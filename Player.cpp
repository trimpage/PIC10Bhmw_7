//Player.cpp

#include "Player.h"

//initialize player with name and starting score of 0
Player::Player(std::string name) : name(name), score(0) {}

void Player::updateScore() {
	//increase score by 1
	score += 1;
}

std::string Player::getName() const {
	return name;
}

int Player::getScore() const {
	return score;
}
