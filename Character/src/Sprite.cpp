#include "Sprite.h"
#include "Direction.h"

#include <iostream>
using std::cout;
using std::endl;

#include <map>
using std::map;

#include <vector>
using std::vector;

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Sprite::Sprite(SDL_Window* newWin, SDL_Renderer* newRen, std::string fileName) {
	// TODO: DO NOT HARD CODE THIS. CHANGE IT AS SOON AS POSSIBLE! THIS IS TERRIBLE!
	// I need to test it though so we're good for now
	resourceDirectory = "/home/ubuntu/Programs/chronoTrigger/Character/resources/";
	win = newWin;
	ren = newRen;
	setSpriteSheet(fileName);
}

Sprite::Sprite( const Sprite &sprite )
	: Walk(sprite.Walk), Stand(sprite.Stand), resourceDirectory(sprite.resourceDirectory), spriteSheet(sprite.spriteSheet), ren(sprite.ren), win(sprite.win) {
}

Sprite::~Sprite() {
	// delete [] spriteRect;
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
		// TODO:
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
	Stand.setDown(standDown);

	delete [] standLeft;
	delete [] standRight;
	delete [] standUp;
	delete [] standDown;
}

void Sprite::setStandUp(SDL_Rect newUp) {
	SDL_Rect* standUp = new SDL_Rect;
	*standUp = newUp;
	Stand.setUp(standUp);
}

void Sprite::setStandDown(SDL_Rect newDown) {
	SDL_Rect* standDown = new SDL_Rect;
	*standDown = newDown;
	Stand.setDown(standDown);
}

void Sprite::setStandLeft(SDL_Rect newLeft) {
	SDL_Rect* standLeft = new SDL_Rect;
	*standLeft = newLeft;
	Stand.setLeft(standLeft);
}

void Sprite::setStandRight(SDL_Rect newRight) {
	SDL_Rect* standRight = new SDL_Rect;
	*standRight = newRight;
	Stand.setRight(standRight);
}

void Sprite::setWalkUp(vector<SDL_Rect> newUp) {
	Walk.setUp(newUp);
}

void Sprite::setWalkDown(vector<SDL_Rect> newDown) {

	Walk.setDown(newDown);
}

void Sprite::setWalkRight(vector<SDL_Rect> newRight) {
	Walk.setRight(newRight);
}

void Sprite::setWalkLeft(vector<SDL_Rect> newLeft) {
	Walk.setLeft(newLeft);

}

Direction Sprite::getStand() {
	return Stand;
}

SDL_Texture* Sprite::sheet() {
	return spriteSheet;
}

Direction Sprite::walk() {
	return Walk;
}

Direction Sprite::stand() {
	return Stand;
}