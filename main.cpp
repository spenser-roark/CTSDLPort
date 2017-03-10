#include <iostream>
using namespace std;

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// My header files
#include "errorHandlers.h"
#include "config.h"

int main() {
	cout << "Hello World!\n";

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
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

	SDL_Event e;
	bool quit = false;

	while (!quit) {
		
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				quit = true;
			} else if (e.type == SDL_KEYDOWN) {
				switch(e.key.keysym.sym) {
					case SDLK_ESCAPE:
						quit = true;
						break;
				}
			} 
		}
			SDL_RenderClear(ren);

			// renderTexture(ren, windowX, windowY, &clips[useClip]);
			SDL_RenderPresent(ren);
	}

	return 0;
}