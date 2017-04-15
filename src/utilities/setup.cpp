#include <iostream>
using namespace std;

#include "setup.h"

void setupPlayableCharacter(PlayableCharacter& character) {
	/**
	* Standing
	*/

	// down
	SDL_Rect* standDownRect = new SDL_Rect;
	standDownRect->w = 40;
	standDownRect->h = 40;
	standDownRect->x = 110;
	standDownRect->y = 0;
	character.getSprite().getStand().setDown(standDownRect);
	/*// left
	standRect->x = 150;
	standRect->y = 0;

	character.getSprite().getStand().setLeft(standRect);

	// Up
	standRect->x = 190;
	standRect->y = 0;

	character.getSprite().getStand().setUp(standRect);

	// Up
	standRect->x = 230;
	standRect->y = 0;

	character.getSprite().getStand().setRight(standRect);*/

	character.getSprite().setStand(*standDownRect, *standDownRect, *standDownRect, *standDownRect);
	// cout << "setupPlayableCharacter down h = " << character.getSprite().stand().down(0)->h << endl;
	delete [] standDownRect;
	// delete [] standLeftRect;
	// delete [] standRect;
}