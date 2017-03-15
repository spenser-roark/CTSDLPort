#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

#include "Sprite.h"

class Character {
private:
	std::string name;
	Sprite sprite;
public:
	void setName(std::string newName);
	std::string getName();
};

#endif