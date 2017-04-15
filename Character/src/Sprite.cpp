#include "Sprite.h"
#include "Direction.h"

#include <iostream>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Sprite::Sprite(SDL_Window* newWin, SDL_Renderer* newRen, std::string fileName) {
	// TODO: DO NOT HARD CODE THIS. CHANGE IT AS SOON AS POSSIBLE! THIS IS TERRIBLE!
	// I need to test it though so we're good for now
	resourceDirectory = "/home/ubuntu/Programs/chronoTrigger/Character/resources/";
	win = newWin;
	ren = newRen;
	setSpriteSheet(fileName);

	spriteRect = new SDL_Rect;

	// Change this to be based on screen size
	// This can stay here though, most sprites will be the same size and we can just overload it as the exception
	spriteRect->w = 150;
	spriteRect->h = 175;
	spriteRect->x = 400;
	spriteRect->y = 320;

	// We're assuming all the sprite sheets are set up similarly so walk/stand should be the same across all boards
	// std::vector<SDL_Rect> standDefaults;
	
	/**
	* Standing
	*/

	// down
	SDL_Rect* standRect = new SDL_Rect;
	standRect->w = 40;
	standRect->h = 40;
	standRect->x = 110;
	standRect->y = 0;
	Stand.setDown(standRect);
	// left
	standRect->x = 150;
	standRect->y = 0;

	Stand.setLeft(standRect);

	// Up
	standRect->x = 190;
	standRect->y = 0;

	Stand.setUp(standRect);

	// Up
	standRect->x = 230;
	standRect->y = 0;

	Stand.setRight(standRect);

	delete [] standRect;
}

Sprite::Sprite( const Sprite &sprite )
	: Walk(sprite.Walk), Stand(sprite.Stand), resourceDirectory(sprite.resourceDirectory), spriteSheet(sprite.spriteSheet), ren(sprite.ren), win(sprite.win) {
	std::cout << "Sprite copy constructor Stand down h = " << sprite.Stand.down(0)->h << std::endl;
	spriteRect = new SDL_Rect;
	*spriteRect = *sprite.spriteRect;
	// delete [] spriteRect;
}

Sprite::~Sprite() {
	delete [] spriteRect;
}

bool Sprite::setSpriteSheet(std::string fileName) {
	try {
		std::string image;
		image = resourceDirectory + fileName;

		spriteSheet = IMG_LoadTexture(ren, image.c_str());

		if (spriteSheet == nullptr) {
			throw 1;
		}

		return true;
	} catch (int e) {
		// Convert this to generic error message function later
		
		std::cerr << "Error: Could not load sprite: " << SDL_GetError() << std::endl;

		SDL_Quit();
		return false;
	}
}

void Sprite::setStand(SDL_Rect newLeft, SDL_Rect newRight, SDL_Rect newUp, SDL_Rect newDown) {
	SDL_Rect* standLeft = new SDL_Rect;
	*standLeft = newLeft;
	Stand.setLeft(standLeft);

	SDL_Rect* standRight = new SDL_Rect;
	*standRight = newRight;
	Stand.setRight(standRight);

	SDL_Rect* standUp = new SDL_Rect;
	*standUp = newUp;
	Stand.setUp(standUp);

	SDL_Rect* standDown = new SDL_Rect;
	*standDown = newDown;
	std::cout << "setstand standDown h = " << standDown->h << std::endl;
	Stand.setDown(standDown);
	std::cout << "setstand Stand.down(0) h = " << Stand.down(0)->h << std::endl;

	delete [] standLeft;
	delete [] standRight;
	delete [] standUp;
	delete [] standDown;
}

Direction Sprite::getStand() {
	return Stand;
}

SDL_Texture* Sprite::getSpriteSheet() {
	// Deprecated, we'll be using move_left... etc. to return a map of the texture and the rect, but this for now
	return spriteSheet;
}

SDL_Rect* Sprite::getSpriteRect() {
	// Deprecated, we'll be using move_left... etc. to return a map of the texture and the rect, but this for now
	return spriteRect;
}

Direction Sprite::walk() {
	return Walk;
}

Direction Sprite::stand() {
	return Stand;
}