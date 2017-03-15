#include <map>
#include <string>
using namespace std;

#include "utilities.h"
#include "VariableConstants.h"

const map<int, string> variable_constants_error_messages = {
	{0, "SDL Surface load error"},
	{1, "Could not create texture from surface"}
};

static const string variable_constants_bg_path = getResourcePath("Backgrounds");
static const int variable_constants_camera_width = 250;
static const int variable_constants_camera_height = 200;

// these keys are arbitrary, maybe I can change them to something meaningful later on
// Break this into its own file if it starts getting too large
const map<int, string>& VariableConstants::errorMessages = variable_constants_error_messages;

const string& VariableConstants::BGPath = variable_constants_bg_path;
const int& VariableConstants::CAMERA_WIDTH = variable_constants_camera_width;
const int& VariableConstants::CAMERA_HEIGHT = variable_constants_camera_height;

string VariableConstants::getBGPath() {
	return BGPath;
}

string VariableConstants::getErrorMessage(int idx) {
	return errorMessages.find(idx)->second;
}

int VariableConstants::getCameraWidth() {
	return CAMERA_WIDTH;
}

int VariableConstants::getCameraHeight() {
	return CAMERA_HEIGHT;
}