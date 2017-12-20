#ifndef DISPLAYPLAYABLECHARACTER_H
#define DISPLAYPLAYABLECHARACTER_H

#include "PlayableCharacter.h"
#include "CharacterSpriteActionIndex.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <string>

struct DisplayPlayableCharacter {
	PlayableCharacter character;
	SDL_Rect* position;
	CharacterSpriteActionIndex actionIndex;
	void move(int, int);
	DisplayPlayableCharacter(SDL_Window*, SDL_Renderer*, std::string);
	~DisplayPlayableCharacter();
};

#endif