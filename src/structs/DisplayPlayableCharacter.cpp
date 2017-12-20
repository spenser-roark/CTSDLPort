#include "DisplayPlayableCharacter.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

DisplayPlayableCharacter::DisplayPlayableCharacter(SDL_Window* win, SDL_Renderer* ren, string fileName) : character(win, ren, fileName){
	// character(win, ren, fileName);

	position = new SDL_Rect;
	
	// This is the character position on the screen
	position->w = 150;
	position->h = 175;
	position->x = 400; // 400
	position->y = 320; // 320
}

void DisplayPlayableCharacter::move(int x, int y) {
	position->x += x;
	position->y += y;
}

DisplayPlayableCharacter::~DisplayPlayableCharacter() {
	delete [] position;
}