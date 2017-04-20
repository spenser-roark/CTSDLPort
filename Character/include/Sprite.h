#ifndef SPRITE_H
#define SPRITE_H

#include <map>
#include <string>
#include <vector>

#include "Direction.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Sprite {
private:
	// We have 6 walking left animations, let's store them both here
	// Most movement variables will probably be the same
	Direction Walk;
	Direction Stand;

	SDL_Window* win;
	SDL_Renderer* ren;
	SDL_Texture* spriteSheet;
	std::string resourceDirectory;
	void moveCharacter();

public:
	Sprite(SDL_Window* newWin, SDL_Renderer* newRen, std::string fileName);
	Sprite( const Sprite &sprite );
	~Sprite();

	SDL_Texture* sheet();
	SDL_Rect* getSpriteRect();
	Direction walk();
	Direction stand();

	bool setSpriteSheet(std::string fileName);

	void setSpriteRect(int, int);

	void setStand(SDL_Rect, SDL_Rect, SDL_Rect, SDL_Rect); //left, right, up, down
	void setStandUp(SDL_Rect);
	void setStandDown(SDL_Rect);
	void setStandLeft(SDL_Rect);
	void setStandRight(SDL_Rect);

	void setWalkUp(std::vector<SDL_Rect>);
	void setWalkDown(std::vector<SDL_Rect>);
	void setWalkLeft(std::vector<SDL_Rect>);
	void setWalkRight(std::vector<SDL_Rect>);

	Direction getStand();
};

#endif