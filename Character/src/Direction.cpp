#include "Direction.h"

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// Do we need this? Does this cause issues *if* we don't set certain directions? I'm assuming all will be set but I could be wrong.
Direction::Direction() {
	// std::cout << "Start of constructor \n";
}

void Direction::setLeft(SDL_Rect* newLeft) {
	Left.clear();
	SDL_Rect* temp;
	temp = new SDL_Rect;
	*temp = *newLeft;
	Left.push_back(temp);
}

void Direction::setRight(SDL_Rect* newRight) {
	Right.clear();
	SDL_Rect* temp;
	temp = new SDL_Rect;
	*temp = *newRight;
	Right.push_back(temp);
}

void Direction::setUp(SDL_Rect* newUp) {
	Up.clear();
	SDL_Rect* temp;
	temp = new SDL_Rect;
	*temp = *newUp;
	Up.push_back(temp);
}

void Direction::setDown(SDL_Rect* newDown) {
	Down.clear();
	SDL_Rect* temp;
	temp = new SDL_Rect;
	*temp = *newDown;
	Down.push_back(temp);
}

void Direction::setUp(std::vector<SDL_Rect> newUp) {
	Up.clear();
	for (int i = 0; i < newUp.size(); i++) {
		SDL_Rect* temp;
		temp = new SDL_Rect;
		*temp = newUp[i];
		Up.push_back(temp);
	}
}

void Direction::setDown(std::vector<SDL_Rect> newDown) {
	Down.clear();
	for (int i = 0; i < newDown.size(); i++) {
		SDL_Rect* temp;
		temp = new SDL_Rect;
		*temp = newDown[i];
		Down.push_back(temp);
	}
}

void Direction::setLeft(std::vector<SDL_Rect> newLeft) {
	Left.clear();
	for (int i = 0; i < newLeft.size(); i++) {
		SDL_Rect* temp;
		temp = new SDL_Rect;
		*temp = newLeft[i];
		Left.push_back(temp);
	}
}

void Direction::setRight(std::vector<SDL_Rect> newRight) {
	Right.clear();
	for (int i = 0; i < newRight.size(); i++) {
		SDL_Rect* temp;
		temp = new SDL_Rect;
		*temp = newRight[i];
		Right.push_back(temp);
	}
}

SDL_Rect* Direction::left(int index) const {
	return checkDirection(Left, index);
}

SDL_Rect* Direction::right(int index) const {
	return checkDirection(Right, index);
}

SDL_Rect* Direction::up(int index) const {
	return checkDirection(Up, index);
}

SDL_Rect* Direction::down(int index) const {
	return checkDirection(Down, index);
}

SDL_Rect* Direction::checkDirection(std::vector<SDL_Rect*> direction, int index) const {
	SDL_Rect* nullRect;
	nullRect = new SDL_Rect;

	if (direction.size() < 1) {
		return nullRect;
	}

	if (index < 0 || index > direction.size()) {
		return direction[0];
	}

	return direction[index];
}


Direction::Direction( const Direction& dctn ) {
	for (int i = 0; i < dctn.Down.size(); i++) {
		SDL_Rect* temp = new SDL_Rect;
		*temp = *dctn.Down[i];
		Down.push_back(temp);
	}
	for (int i = 0; i < dctn.Left.size(); i++) {
		SDL_Rect* temp = new SDL_Rect;
		*temp = *dctn.Left[i];
		Left.push_back(temp);
	}
	for (int i = 0; i < dctn.Up.size(); i++) {
		SDL_Rect* temp = new SDL_Rect;
		*temp = *dctn.Up[i];
		Up.push_back(temp);
	}
	for (int i = 0; i < dctn.Right.size(); i++) {
		SDL_Rect* temp = new SDL_Rect;
		*temp = *dctn.Right[i];
		Right.push_back(temp);
	}
}

Direction::~Direction(void) {
	for (int i = 0; i < Down.size(); i++) {
		delete [] Down[i];
		Down.erase(Down.begin());
	}
	for (int i = 0; i < Left.size(); i++) {
		delete [] Left[i];
		Left.erase(Left.begin());
	}
	for (int i = 0; i < Up.size(); i++) {
		delete [] Up[i];
		Up.erase(Up.begin());
	}
	for (int i = 0; i < Right.size(); i++) {
		delete [] Right[i];
		Right.erase(Right.begin());
	}
}