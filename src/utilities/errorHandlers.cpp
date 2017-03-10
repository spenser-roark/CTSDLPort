#include <iostream>
#include <string>
using namespace std;

#include "errorHandlers.h"

void printSDLErrorToTerminal(string errorMsg, string sdlError) {
	cerr << errorMsg << ": " << sdlError << endl;
}