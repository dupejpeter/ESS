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
		cout << "g.getSizeX() = " << g.getSizeX() << endl;
		cout << "g.getSizeY() = " << g.getSizeY() << endl;
		cout << "g.getPot(0, 0) = " << g.getPot(0, 0) << endl;
		g.setPot(0, 0, 9.999999);
		cout << "g.setPot(0, 0, 9.999999)" << endl;
		cout << "g.getPot(0, 0) = " << g.getPot(0, 0) << endl;
		cout << "g.isFixed(0, 0) = " << g.isFixed(0, 0) << endl;
		g.setFixed(0, 0, 1);
		cout << "g.setFixed(0, 0, 1)" << endl;
		cout << "g.isFixed(0, 0) = " << g.isFixed(0, 0) << endl;
	} catch (invalid_argument &e) {
		cerr << "Invalid argument: " << e.what() << endl;
	} catch (out_of_range &e) {
		cerr << "Out of range: " << e.what() << endl;
	} catch (exception &e) {
		cerr << "Everything else we forgot: " << e.what() << endl;
	}

	return 0;
}
