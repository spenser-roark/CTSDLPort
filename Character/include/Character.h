#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Sprite.h"

class Character {
private:
	std::string name;
	Sprite characterSprite;
public:
	Character(SDL_Window* win, SDL_Renderer* ren, std::string fileName): characterSprite(win, ren, fileName){};
	void setName(std::string newName);
	std::string getName();
	Sprite sprite();
	void setStandUp(SDL_Rect);
	void setStandDown(SDL_Rect);
	void setStandLeft(SDL_Rect);
	void setStandRight(SDL_Rect);

	void setWalkUp(std::vector<SDL_Rect>);
	void setWalkDown(std::vector<SDL_Rect>);
	void setWalkLeft(std::vector<SDL_Rect>);
	void setWalkRight(std::vector<SDL_Rect>);

	void setPosition(int, int);
};

#endif