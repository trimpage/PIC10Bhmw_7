//Player.cpp
#include "Player.h"

Player::Player(std::string name) : name(name), score(0) {}

void Player::updateScore() {
	score += 1;
}

std::string Player::getName() const {
	return name;
}

int Player::getScore() const {
	return score;
}
