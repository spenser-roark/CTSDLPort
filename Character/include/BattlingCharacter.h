#ifndef BATTLINGCHARACTER_H
#define BATTLINGCHARACTER_H

#include "Character.h"

#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class BattlingCharacter: public Character {
private:
	// Stats stats;
	// attacks
	// magic
	// etc
public:
	//More public stuff here man
	BattlingCharacter(SDL_Window* win, SDL_Renderer* ren, std::string fileName): Character(win, ren, fileName){};
};

#endif