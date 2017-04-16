#include "PlayableCharacter.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
using std::cout;

PlayableCharacter::PlayableCharacter(SDL_Window* win, SDL_Renderer* ren, std::string fileName):BattlingCharacter(win, ren, fileName){
	/**
	* Standing
	*/

	// down
	SDL_Rect* standRect = new SDL_Rect;
	standRect->w = 40;
	standRect->h = 40;
	standRect->x = 110;
	standRect->y = 0;
	Character::setStandDown(*standRect);
	
	// left
	standRect->x = 150;
	standRect->y = 0;

	Character::setStandLeft(*standRect);

	// Up
	standRect->x = 190;
	standRect->y = 0;

	Character::setStandUp(*standRect);

	// Right
	standRect->x = 230;
	standRect->y = 0;

	Character::setStandRight(*standRect);

	delete [] standRect;
}
