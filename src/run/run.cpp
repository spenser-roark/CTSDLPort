/**
* Maybe either rename this or split it up, but it works for now
* This will include the move switcheroo so something appropriate that reflects that I guess
*/

#include <iostream>
using namespace std;

#include "run.h"

/**
* This function takes a display playable character, changes their position on the screen based on the 
* directional button pressed and returns the character. This function does mutate the character.
*
* Input:
*	DisplayPlayableCharacter character
*	const Uint8 state
*
* Returns: void
*/
void moveCharacter(DisplayPlayableCharacter& displayCharacter, const Uint8 state []) {

	// cout << displayCharacter.character.getName() << "'s level is " << displayCharacter.character.getLevel() << endl;

	if (state[SDL_SCANCODE_UP]) {
		// i is the position, base it on the prior pos not some global one
		// not a callback, but do some magic in displaycharacter before it goes down to the sprite so we can keep track of the position index
		currentCharacterSprite = *displayCharacter.character.sprite().walk().up(i);
		// if (frame_count % 10 == 0) {
			displayCharacter.move(0, -8);
		// }
		if (i >= 5) {
			i = 0;
		}
		i++;
	} else if (state[SDL_SCANCODE_DOWN]) {
		currentCharacterSprite = *displayCharacter.character.sprite().walk().down(i);
		displayCharacter.move(0, 8);

		if (i >= 5) {
			i = 0;
		}
		i++;
	} else if (state[SDL_SCANCODE_LEFT]) {
		currentCharacterSprite = *displayCharacter.character.sprite().walk().left(i);

		displayCharacter.move(-8, 0);

		if (i >= 5) {
			i = 0;
		}
		i++;
	} else if (state[SDL_SCANCODE_RIGHT]) {
		currentCharacterSprite = *displayCharacter.character.sprite().walk().right(i);

		displayCharacter.move(8, 0);

		if (i >= 5) {
			i = 0;
		}
		i++;
	}
}
