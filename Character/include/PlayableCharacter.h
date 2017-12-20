#ifndef PLAYABLECHARACTER_H
#define PLAYABLECHARACTER_H

#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "BattlingCharacter.h"

class PlayableCharacter: public BattlingCharacter {
private:
	unsigned int level;
	unsigned int experience; // break this out into a class? YES!
	SDL_Texture* portrait;
public:
	PlayableCharacter(SDL_Window* win, SDL_Renderer* ren, std::string fileName);
	void setPortrait(std::string fileName);
	unsigned int getLevel() { return level; };
};

#endif