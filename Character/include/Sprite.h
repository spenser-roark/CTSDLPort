#ifndef SPRITE_H
#define SPRITE_H

#include <map>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Sprite {
private:
	// just 2, I don't remember why I made the third one but there was a good reason I think
	std::map<int, int, int> position;
	SDL_Texture* spriteSheet;
	
public:
	void moveLeft();
	void moveRight();
	void moveUp();
	void movedown();
	void setSpriteSheet(std::string fileName);
};

#endif