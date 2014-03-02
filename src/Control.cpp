//============================================================================
// Name        : Control.cpp
// Author      : Peter Dupej
// Version     : 1.0
// Copyright   : The MIT License (MIT)
// Description : Main control of the program
//============================================================================

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	cout << "There are " << argc << " arguments:" << endl;

	// Loop through each argument and print its number and value
	for (int nArg=0; nArg < argc; nArg++)
		cout << nArg << " " << argv[nArg] << endl;

	// TODO program control

	return 0;
}
