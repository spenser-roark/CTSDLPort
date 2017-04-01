#ifndef DIRECTION_H
#define DIRECTION_H

#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Direction {
private:
	std::vector<SDL_Rect*> Left;
	std::vector<SDL_Rect*> Right;
	std::vector<SDL_Rect*> Up;
	std::vector<SDL_Rect*> Down;
	SDL_Rect* checkDirection(std::vector<SDL_Rect*> direction, int index);

public:
	SDL_Rect* left(int index);
	SDL_Rect* right(int index);
	SDL_Rect* up(int index);
	SDL_Rect* down(int index);
	void setLeft(SDL_Rect* newLeft);
	void setLeft(std::vector<SDL_Rect*> newLeft);
	void setRight(SDL_Rect newRight);
	void setRight(std::vector<SDL_Rect> newRight);
	void setUp(SDL_Rect newUp);
	void setUp(std::vector<SDL_Rect> newUp);
	void setDown(SDL_Rect* newDown);
	void setDown(std::vector<SDL_Rect*> newDown);

	Direction();
	Direction( const Direction &dctn );
	~Direction();
};

#endif