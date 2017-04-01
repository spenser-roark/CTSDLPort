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