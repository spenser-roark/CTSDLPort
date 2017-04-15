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
#include "PlayableCharacter.h"
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

/*	cout << "Hello World! \n"
		 << "My name is " << Crono.getName() << endl;
*/

	// Make an errorhandler that opens an error window?
	Background cronosHouse("CronosHouse.png", ren, win);

	SDL_Event e;
	bool quit = false;

	// Temp variable
	SDL_Rect tempBackgroundRect;

	tempBackgroundRect.w = constants.getCameraWidth();
	tempBackgroundRect.h = constants.getCameraHeight();
	tempBackgroundRect.x = 10;
	tempBackgroundRect.y = 35;

 	PlayableCharacter Crono(win, ren, "Crono2.gif");
 	Crono.setName("Crono");

 	// setupPlayableCharacter(Crono);

 	SDL_Rect currentCharacterSprite = *Crono.getSprite().stand().down(0);
	 while (!quit) {
		while (SDL_PollEvent(&e)) {
			SDL_RenderClear(ren);
			if (e.type == SDL_QUIT) {
				quit = true;
			} else if (e.type == SDL_KEYDOWN) {
				switch(e.key.keysym.sym) {
					case SDLK_1:
						tempBackgroundRect.x = 10;
						break;
					case SDLK_2:
						tempBackgroundRect.x = 17 + constants.getCameraWidth();
						break;
					case SDLK_LEFT:
						currentCharacterSprite = *Crono.getSprite().stand().left(0);
						break;
					case SDLK_RIGHT:
						currentCharacterSprite = *Crono.getSprite().stand().right(0);
						break;
					case SDLK_UP:
						currentCharacterSprite = *Crono.getSprite().stand().up(0);
						break;
					case SDLK_DOWN:
						currentCharacterSprite = *Crono.getSprite().stand().down(0);
						break;
					case SDLK_ESCAPE:
						quit = true;
						break;
				}
			}
		}
			SDL_RenderCopy(ren, cronosHouse.getBGTexture(), &tempBackgroundRect, NULL);
			
			SDL_RenderCopy(ren, Crono.getSprite().getSpriteSheet(), &currentCharacterSprite, Crono.getSprite().getSpriteRect());

			// SDL_Wait(1000);
			// SDL_RenderCopy(ren, Crono.getSprite().getSpriteSheet(), Crono.getSprite().stand().down(0), Crono.getSprite().getSpriteRect());
			// SDL_RenderTexture(cronosHouse.getBGTexture(), ren, screen_width, screen_height, NULL);

			// renderTexture(ren, windowX, windowY, &clips[useClip]);
			SDL_RenderPresent(ren);
	}
	SDL_Quit();
	IMG_Quit();
	return 0;
}