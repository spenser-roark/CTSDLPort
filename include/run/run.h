#ifndef RUN_H
#define RUN_H
#include "DisplayPlayableCharacter.h"
#include <SDL2/SDL.h>

void moveCharacter(DisplayPlayableCharacter& character, SDL_Rect& currentCharacterSprite, const Uint8 state [], int& i);

#endif