#ifndef SPRITE_H
#define SPRITE_H

#include <map>
#include <string>

#include "Direction.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Sprite {
private:
	// just 2, I don't remember why I made the third one but there was a good reason I think
	std::map<int, int> position;
	// We have 6 walking left animations, let's store them both here
	// Most movement variables will probably be the same
	SDL_Rect* spriteRect;

	Direction Walk;
	Direction Stand;

	SDL_Window* win;
	SDL_Renderer* ren;
	SDL_Texture* spriteSheet;
	std::string resourceDirectory;
	
public:
	Sprite(SDL_Window* newWin, SDL_Renderer* newRen, std::string fileName);
	Sprite( const Sprite &sprite );
	SDL_Rect* move_left(int index);
	void move_right();
	void move_up();
	void move_down();
	bool setSpriteSheet(std::string fileName);
	SDL_Texture* getSpriteSheet();
	SDL_Rect* getSpriteRect();
	Direction walk();
	Direction stand();
	~Sprite();
};

#endif