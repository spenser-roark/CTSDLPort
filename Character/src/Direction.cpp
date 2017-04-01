#include "Direction.h"

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Direction::Direction() {
	std::cout << "Start of constructor \n";
}

void Direction::setLeft(SDL_Rect* newLeft) {
	// Left.clear();
	// Left.push_back(newLeft);
}

void Direction::setLeft(std::vector<SDL_Rect*> newLeft) {
	// Left.clear();
	// Left = newLeft;
}

void Direction::setRight(SDL_Rect newRight) {
	// Right.clear();
	// Right.push_back(newRight);
}

void Direction::setRight(std::vector<SDL_Rect> newRight) {
	// Right.clear();
	// Right = newRight;
}

void Direction::setUp(SDL_Rect newUp) {
	// Up.clear();
	// Up.push_back(newUp);
}

void Direction::setUp(std::vector<SDL_Rect> newUp) {
	// Up.clear();
	// Up = newUp;
}

void Direction::setDown(SDL_Rect* newDown) {
	std::cout << "Beginning of set down\n";
	
	std::cout << "Clearing Down\n";
	Down.clear();
	
	std::cout << "instantiate temp as a sdl_rect pointer\n";
	SDL_Rect* temp;
	
	std::cout << "temp = new rect\n";
	temp = new SDL_Rect;

	std::cout << "temp = newDown\n";
	*temp = *newDown;

	std::cout << "Down push back\n";
	Down.push_back(temp);

	// are we still referencing temp instead of copying the values?
	// yes!!!!!!
	// delete [] temp;
	// Is this a memory leak????

	std::cout << "Down length = " << Down.size() << std::endl;
	
	std::cout << "Down[0]->h = " << Down[0]->h << std::endl
			  << "Down[0]->w = " << Down[0]->w << std::endl
			  << "Down[0]->x = " << Down[0]->x << std::endl
			  << "Down[0]->y = " << Down[0]->y << std::endl;
	std::cout << "End of set down\n\n";
}

void Direction::setDown(std::vector<SDL_Rect*> newDown) {
	// Down.clear();
	// Down = newDown;
}

// maybe add this functionality later
/*void Direction::setDown(SDL_Rect newDown[]) {
	std::cout << "sizeof newDown" << sizeof(newDown) / sizeof(SDL_Rect) << std::endl;
	// Down.clear();
	// for (int i = 0; i < 10; i++) {
	// 	Down.push_back(newDown[i]);
	// }
}*/

SDL_Rect* Direction::down(int index) {
	std::cout << "beginning of \"down()\", index " << index << std::endl;

	std::cout << "Down h " << Down[0]->h << std::endl
	<< "Down w " << Down[0]->w << std::endl
	<< "Down x " << Down[0]->x << std::endl
	<< "Down y " << Down[0]->y << std::endl;
	return checkDirection(Down, index);
	std::cout << "End of \"down()\"\n\n";
}

SDL_Rect* Direction::left(int index) {
		std::cout << "\n\n\ngetting left index " << index << std::endl 
				  << "Left h " << Left[0]->h << std::endl
				  << "Left w " << Left[0]->w << std::endl
				  << "Left x " << Left[0]->x << std::endl
				  << "Left y " << Left[0]->y << std::endl;
	return checkDirection(Left, index);
}

SDL_Rect* Direction::checkDirection(std::vector<SDL_Rect*> direction, int index) {
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


Direction::Direction( const Direction& dctn ) : Up(dctn.Up), Right(dctn.Right)
{
	std::cout << "Beginning of copy constructor\n";
	std::cout << "dctn.Down size = " << dctn.Down.size() << std::endl;
	for (int i = 0; i < dctn.Down.size(); i++) {
		std::cout << "beginning of loop\n";
		std::cout << "Declaring new sdlrect with temp\n";
		SDL_Rect* temp = new SDL_Rect;
		std::cout << "temp = dctn.Down[i], i = " << i << "\n";
		*temp = *dctn.Down[i];
		/*std::cout << "temp->h = " << temp->h << std::endl
				  << "temp->w = " << temp->w << std::endl
				  << "temp->x = " << temp->x << std::endl
				  << "temp->y = " << temp->y << std::endl;
		std::cout << "dctn.Down[i]->h = " << dctn.Down[i]->h << std::endl
				  << "dctn.Down[i]->w = " << dctn.Down[i]->w << std::endl
				  << "dctn.Down[i]->x = " << dctn.Down[i]->x << std::endl
				  << "dctn.Down[i]->y = " << dctn.Down[i]->y << std::endl;*/
		std::cout << "Pushing back temp\n";
		Down.push_back(temp);
		// delete [] temp;
		std::cout << "End of loop\n";
	}
	std::cout << "End of copy constructor\n\n";
}

Direction::~Direction(void) {
	std::cout << "Beginning of destructor\n";
	for (int i = 0; i < Down.size(); i++) {
		std::cout << "Beginning of loop\n";
		std::cout << "Delete Down[i], i = " << i << "\n";
		delete [] Down[i];
		std::cout << "Erase Down\n";
		Down.erase(Down.begin());
		std::cout << "End of loop\n";
	}
	/*for (int i = 0; i < Left.size(); i++) {
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
	}*/
	std::cout << "End of destructor\n\n";
}