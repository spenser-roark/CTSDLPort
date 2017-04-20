#include <iostream>
using namespace std;

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// My header files
#include "errorHandlers.h"
#include "config.h"
// #include "constants.h"
#include "Background.h"
#include "utilities.h"
#include "DisplayPlayableCharacter.h"
#include "setup.h"

int main() {
	int imgFlags = IMG_INIT_PNG;	
	int initted = IMG_Init(imgFlags);
	VariableConstants constants;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0 && (initted&imgFlags != imgFlags)) {
		printSDLErrorToTerminal("Initialization error", SDL_GetError());
		return 1;
	}

	SDL_Window* win = SDL_CreateWindow("Chrono Trigger", 0, 0, screen_width, screen_height, SDL_WINDOW_SHOWN);

	if (win == nullptr) {
		printSDLErrorToTerminal("Error creating sdl window", SDL_GetError());

		SDL_Quit();
		return 1;
	}

	SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

	if (ren == nullptr) {
		printSDLErrorToTerminal("Error creating renderer", SDL_GetError());
		SDL_Quit();
		return 1;
	}

	// ADD CONSTRUCTOR HERE, WE NEED TO PASS IN WIN AND REN
	// setupCharacters(win, ren);

	// TODO: Make an errorhandler that opens an error window?
	Background cronosHouse("CronosHouse.png", ren, win);

	SDL_Event e;
	bool quit = false;

	// Temp variable
	SDL_Rect tempBackgroundRect;

	tempBackgroundRect.w = constants.getCameraWidth();
	tempBackgroundRect.h = constants.getCameraHeight();
	tempBackgroundRect.x = 10;
	tempBackgroundRect.y = 35;

 	// PlayableCharacter PCCrono(win, ren, "Crono2.gif");
	DisplayPlayableCharacter Crono(win, ren, "Crono2.gif");
	// Crono.character = PCCrono;
 	Crono.character.setName("Crono");

 	SDL_Rect currentCharacterSprite = *Crono.character.sprite().stand().down(0);
 	const Uint8 *state = SDL_GetKeyboardState(NULL);
	int i = 0;
	int test = 1;
	 while (!quit) {
		while (SDL_PollEvent(&e)) {
			SDL_RenderClear(ren);
			if (e.type == SDL_QUIT) {
				quit = true;
			} else if (e.type == SDL_KEYDOWN) {
				if (state[SDL_SCANCODE_UP]) {
					currentCharacterSprite = *Crono.character.sprite().walk().up(i);
					Crono.move(0, -4);
					if (i >= 5) {
						i = 0;
					}
					i++;
				} else if (state[SDL_SCANCODE_DOWN]) {
					currentCharacterSprite = *Crono.character.sprite().walk().down(i);
					Crono.move(0, 4);

					if (i >= 5) {
						i = 0;
					}
					i++;
				} else if (state[SDL_SCANCODE_LEFT]) {
					currentCharacterSprite = *Crono.character.sprite().walk().left(i);

					Crono.move(-4, 0);

					if (i >= 5) {
						i = 0;
					}
					i++;
				} else if (state[SDL_SCANCODE_RIGHT]) {
					currentCharacterSprite = *Crono.character.sprite().walk().right(i);

					Crono.move(4, 0);

					if (i >= 5) {
						i = 0;
					}
					i++;
				}
				switch(e.key.keysym.sym) {
					case SDLK_1:
						tempBackgroundRect.x = 10;
						break;
					case SDLK_2:
						tempBackgroundRect.x = 17 + constants.getCameraWidth();
						break;
					case SDLK_LEFT:
						// currentCharacterSprite = *Crono.character.sprite().stand().left(0);
						break;
					case SDLK_RIGHT:
						// currentCharacterSprite = *Crono.character.sprite().stand().right(0);
						break;
					case SDLK_UP:
						// currentCharacterSprite = *Crono.character.sprite().stand().up(0);
						break;
					case SDLK_DOWN:
						// currentCharacterSprite = *Crono.character.sprite().stand().down(0);
						break;
					case SDLK_ESCAPE:
						quit = true;
						break;
				}
			}
		}
			SDL_RenderCopy(ren, cronosHouse.getBGTexture(), &tempBackgroundRect, NULL);
			
			SDL_RenderCopy(ren, Crono.character.sprite().sheet(), &currentCharacterSprite, Crono.position);

			// SDL_Wait(1000);
			// SDL_RenderCopy(ren, Crono.sprite().getSpriteSheet(), Crono.sprite().stand().down(0), Crono.sprite().getSpriteRect());
			// SDL_RenderTexture(cronosHouse.getBGTexture(), ren, screen_width, screen_height, NULL);

			// renderTexture(ren, windowX, windowY, &clips[useClip]);
			SDL_RenderPresent(ren);
	}
	SDL_Quit();
	IMG_Quit();
	return 0;
}