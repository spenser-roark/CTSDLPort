// Only need this file so cmake can find the header and go from there.
#include "PlayableCharacterList.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

PlayableCharacterList::PlayableCharacterList(SDL_Window* win, SDL_Renderer* ren):Crono(win, ren, "Crono2.gif") {
	Crono.setName("Crono");
}