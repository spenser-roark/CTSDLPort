#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Sprite.h"

class Character {
private:
	std::string name;
	Sprite sprite;
public:
	Character(SDL_Window* win, SDL_Renderer* ren, std::string fileName): sprite(win, ren, fileName){}
	void setName(std::string newName);
	std::string getName();
	Sprite getSprite();
};

#endif