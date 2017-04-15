// Only need this file so cmake can find the header and go from there.
#include "PlayableCharacter.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// PlayableCharacterList::PlayableCharacterList(SDL_Window* win, SDL_Renderer* ren):Crono(win, ren, "Crono2.gif") {

void setupCharacters(SDL_Window* win, SDL_Renderer* ren) {
	PlayableCharacter Crono(win, ren, "Crono");
	// Crono.setName("Crono");
}
// }