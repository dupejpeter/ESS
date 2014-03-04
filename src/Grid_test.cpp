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
		Grid g = Grid(0, 1);
		cout << "we should never get there" << endl;
		cout << g.getSizeX() << endl;
	} catch (invalid_argument &e) {
		cerr << "Invalid argument: " << e.what() << endl;
	}

	//cout << g.getSizeX();
	//g.setPot(0, 0, 9.9);
	//cout << "g.getPot(0, 0) = " << g.getPot(0, 0);

	return 0;
}
