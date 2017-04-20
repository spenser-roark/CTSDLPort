#include <string>

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

#include "Character.h"

void Character::setName(std::string newName) {
	name = newName;
}

std::string Character::getName() {
	return name;
}

Sprite Character::sprite() {
	return characterSprite;
}

void Character::setStandUp(SDL_Rect newStand) {
	characterSprite.setStandUp(newStand);
}

void Character::setStandDown(SDL_Rect newStand) {
	characterSprite.setStandDown(newStand);
}

void Character::setStandLeft(SDL_Rect newStand) {
	characterSprite.setStandLeft(newStand);
}

void Character::setStandRight(SDL_Rect newStand) {
	characterSprite.setStandRight(newStand);
}

void Character::setWalkUp(vector<SDL_Rect> newWalk) {
	characterSprite.setWalkUp(newWalk);
}

void Character::setWalkDown(vector<SDL_Rect> newWalk) {
	characterSprite.setWalkDown(newWalk);
}

void Character::setWalkLeft(vector<SDL_Rect> newWalk) {
	characterSprite.setWalkLeft(newWalk);
}

void Character::setWalkRight(vector<SDL_Rect> newWalk) {
	characterSprite.setWalkRight(newWalk);
}
