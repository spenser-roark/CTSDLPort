#include <iostream>
#include <string>
using namespace std;

#include "errorHandlers.h"

/**
* Prints the given errorMsg to the terminal along with the sdl error.
* The sdl error is passed in but I do wonder if there's a way to not need to do that.
* For now that works for me
*
* Input: std::string errorMsg
* 		 std::string sdlError
*
* Output: void
*/
void printSDLErrorToTerminal(string errorMsg, string sdlError) {
	cerr << errorMsg << ": " << sdlError << endl;
}