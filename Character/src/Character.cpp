#include <string>

#include "Character.h"

void Character::setName(std::string newName) {
	name = newName;
}

std::string Character::getName() {
	return name;
}

Sprite Character::getSprite() {
	return sprite;
}

void Character::setStandUp(SDL_Rect newStand) {
	sprite.setStandUp(newStand);
}

void Character::setStandDown(SDL_Rect newStand) {
	sprite.setStandDown(newStand);
}

void Character::setStandLeft(SDL_Rect newStand) {
	sprite.setStandLeft(newStand);
}

void Character::setStandRight(SDL_Rect newStand) {
	sprite.setStandRight(newStand);
}