#ifndef PLAYABLECHARACTERLIST_H
#define PLAYABLECHARACTERLIST_H

#include "../PlayableCharacter.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void initPlayableCharacters();

struct PlayableCharacterList {
	PlayableCharacterList(SDL_Window* win, SDL_Renderer* ren);
	PlayableCharacter Crono;
};

#endif