#include "PlayableCharacter.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
using std::cout;

#include <vector>
using std::vector;

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

	// there are 6 walking animations
	vector <SDL_Rect> walkRect(6);
	for (int i = 0; i < 6; i++) {
		walkRect[i].w = 40;
		walkRect[i].h = 40;
		walkRect[i].x = 190;
		walkRect[i].y = 599 + (40 * i);
	}
	Character::setWalkUp(walkRect);

	for (int i = 0; i < 6; i++) {
		walkRect[i].w = 40;
		walkRect[i].h = 40;
		walkRect[i].x = 110;
		walkRect[i].y = 599 + (40 * i);
	}

	Character::setWalkDown(walkRect);

	for (int i = 0; i < 6; i++) {
		walkRect[i].w = 40;
		walkRect[i].h = 40;
		walkRect[i].x = 150;
		walkRect[i].y = 599 + (40 * i);
	}

	Character::setWalkLeft(walkRect);

	for (int i = 0; i < 6; i++) {
		walkRect[i].w = 40;
		walkRect[i].h = 40;
		walkRect[i].x = 230;
		walkRect[i].y = 599 + (40 * i);
	}

	Character::setWalkRight(walkRect);
}
