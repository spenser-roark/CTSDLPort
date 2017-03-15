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
#include "PlayableCharacterList.h"

int main() {
	cout << "Hello World!\n";
	PlayableCharacterList PlayableCharacters;
	cout << "Hello my name is " << PlayableCharacters.Crono.getName() << endl;
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

	// Make an errorhandler that opens an error window?
	Background cronosHouse("CronosHouse.png", ren, win);

	SDL_Event e;
	bool quit = false;
	SDL_Rect foo;
	foo.w = constants.getCameraWidth();
	foo.h = constants.getCameraHeight();
	foo.x = 10;
	foo.y = 35;

	while (!quit) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				quit = true;
			} else if (e.type == SDL_KEYDOWN) {
				switch(e.key.keysym.sym) {
					case SDLK_1:
						foo.x = 10;
						break;
					case SDLK_2:
						foo.x = 17 + constants.getCameraWidth();
						break;
					case SDLK_ESCAPE:
						quit = true;
						break;
				}
			}
		}
			SDL_RenderClear(ren);
			SDL_RenderCopy(ren, cronosHouse.getBGTexture(), &foo, NULL);
			// SDL_RenderTexture(cronosHouse.getBGTexture(), ren, screen_width, screen_height, NULL);

			// renderTexture(ren, windowX, windowY, &clips[useClip]);
			SDL_RenderPresent(ren);
	}
	SDL_Quit();
	IMG_Quit();
	return 0;
}