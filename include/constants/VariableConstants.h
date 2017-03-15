#ifndef VARIABLECONSTANTS_H
#define VARIABLECONSTANTS_H

#include <map>
using namespace std;

/**
* These constants are used only by the program, there's a separate config file for user specific options
*/

class VariableConstants {
private:
	static const map<int, string>& errorMessages;
	static const string& BGPath;
	static const int& CAMERA_WIDTH;
	static const int& CAMERA_HEIGHT;

public:
	string getBGPath();
	string getErrorMessage(int idx);
	int getCameraWidth();
	int getCameraHeight();
};

#endif