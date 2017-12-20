#include <iostream>
using namespace std;

#include <time.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/* My header files */
#include "errorHandlers.h"
#include "config.h"
// #include "constants.h"
#include "Background.h"
#include "utilities.h"
#include "DisplayPlayableCharacter.h"
#include "setup.h"
#include "run.h"

int main() {
	const int imgFlags = IMG_INIT_PNG;
	const int initted = IMG_Init(imgFlags);

	time_t dt; // delta time - change in time
	time_t clock; // current time
	time_t render_timer; // do we render? Only TIME will tell HAHAHHAHAHAHA

	time(&clock);

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
	int frame_count = 0;
	while (!quit) {
		time(&dt);
		while (SDL_PollEvent(&e)) {
			SDL_RenderClear(ren);
			if (e.type == SDL_QUIT) {
				quit = true;
			} else if (e.type == SDL_KEYDOWN) {

				moveCharacter(Crono, state);
				

				switch(e.key.keysym.sym) {
					case SDLK_1:
						tempBackgroundRect.x = 10;
						break;
					case SDLK_2:
						tempBackgroundRect.x = 17 + constants.getCameraWidth();
						break;
					case SDLK_ESCAPE:
						quit = true;
						break;
				}
			}
		}

		// if (render_timer < 1 && frame_count < 60) {
			SDL_RenderCopy(ren, cronosHouse.getBGTexture(), &tempBackgroundRect, NULL);
			SDL_RenderCopy(ren, Crono.character.sprite().sheet(), &currentCharacterSprite, Crono.position);
			// frame_count++;
		//}
		/*
		if (render_timer >= 1) {
			if (frame_count < 60) {
				frame_count++;
			} else {
				time(&clock);
				frame_count = 0;
			}
		}*/

		// SDL_Wait(1000);
		// SDL_RenderCopy(ren, Crono.sprite().getSpriteSheet(), Crono.sprite().stand().down(0), Crono.sprite().getSpriteRect());
		// SDL_RenderTexture(cronosHouse.getBGTexture(), ren, screen_width, screen_height, NULL);

/*		cout << "frame count = " << frame_count << endl
			 << "render timer = " << render_timer << endl
			 << "delta time = " << dt << endl;
*/
		// renderTexture(ren, windowX, windowY, &clips[useClip]);
		SDL_RenderPresent(ren);

		render_timer = dt - clock;
	}
	SDL_Quit();
	IMG_Quit();
	return 0;
}

/*
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
						break;*/