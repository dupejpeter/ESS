/*
 * Grid_test.cpp
 *
 *  Created on: 3 Mar 2014
 *      Author: Peter
 */

#include "Grid.h"
#include <stdexcept>
#include <iostream>

using namespace std;

int main() {
	try {
		Grid g = Grid(1, 1);
		cout << g.getSizeX() << endl;
		cout << g.getSizeY() << endl;
		cout << g.getPot(0, 0) << endl;
		//g.setPot(0, 0, 9.9);
		//cout << "g.getPot(0, 0) = " << g.getPot(0, 0);
	} catch (invalid_argument &e) {
		cerr << "Invalid argument: " << e.what() << endl;
	} catch (exception &e) {
		cerr << "Some other error: " << e.what() << endl;
	}

	return 0;
}
