#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "VariableConstants.h"

/**
* This class contains the background/image data.
* E.g. Chrono's house, Leene square, etc.
*/
class Background: public VariableConstants {
private:
	std::string BGFile;
	SDL_Texture* BGTexture;
	int BGWidth;
	int BGHeight;
public:
	Background();
	Background(std::string newBGFile);
	Background(std::string newBGFile, SDL_Renderer* newRen, SDL_Window* newWin);
	std::string getBGFile();
	SDL_Texture* getBGTexture();
	bool setBGTexture(SDL_Renderer* ren, SDL_Window* win);
	void setBGFile(std::string newBGFile);
	// WE NEED A DESTRUCTOR TO CLEAN UP BGTexture
};

#endif