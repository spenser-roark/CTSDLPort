#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Background.h"
#include "VariableConstants.h"
#include "DestroySdlObjects.h"
#include "errorHandlers.h"


Background::Background() {
	BGFile = "";
	BGTexture = nullptr;
}

Background::Background(std::string newBGFile) {
	BGFile = newBGFile;
}

Background::Background(std::string newBGFile, SDL_Renderer* newRen, SDL_Window* newWin) {
	BGFile = newBGFile;
	if (!setBGTexture(newRen, newWin)) {
		cerr << "Warning: could not set the background texture for " << BGFile << endl;
	}
}

/**
* \fn Getter for the fileName member variable
*/
std::string Background::getBGFile() {
	return BGFile;
}

SDL_Texture* Background::getBGTexture() {
	return BGTexture;
}

bool Background::setBGTexture(SDL_Renderer* ren, SDL_Window* win) {
	try {
		string image;
		image = getBGPath() + BGFile;

		BGTexture = IMG_LoadTexture(ren, image.c_str());

		if (BGTexture == nullptr) {
			throw 1;
		}

		return true;
	} catch (int e) {
		printSDLErrorToTerminal(getErrorMessage(e), SDL_GetError());
		SDL_Quit();
		return false;
	}
}

void Background::setBGFile(std::string newBGFile) {
	BGFile = newBGFile;
}

