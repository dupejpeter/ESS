/*
 * Grid_test.cpp
 *
 *  Created on: 3 Mar 2014
 *      Author: Peter
 */

#include "Grid.h"
#include <stdexcept>	//	invalid_argument, out_of_range, exception
#include <iostream>		//	cout, cerr, endl

using namespace std;

void test1() {
	try {
		Grid g = Grid(1, 1);
		cout << "g.getSizeX() = " << g.GetSizeX() << endl;
		cout << "g.getSizeY() = " << g.GetSizeY() << endl;
		cout << "g.getPot(0, 0) = " << g.GetPot(0, 0) << endl;
		g.SetPot(0, 0, 9.999999);
		cout << "g.setPot(0, 0, 9.999999)" << endl;
		cout << "g.getPot(0, 0) = " << g.GetPot(0, 0) << endl;
		cout << "g.isFixed(0, 0) = " << g.IsFixed(0, 0) << endl;
		g.SetFixed(0, 0, 1);
		cout << "g.setFixed(0, 0, 1)" << endl;
		cout << "g.isFixed(0, 0) = " << g.IsFixed(0, 0) << endl;
	} catch (invalid_argument &e) {
		cerr << "Invalid argument: " << e.what() << endl;
	} catch (out_of_range &e) {
		cerr << "Out of range: " << e.what() << endl;
	} catch (exception &e) {
		cerr << "Everything else we forgot: " << e.what() << endl;
	}
}

int main() {
	test1();

	return 0;
}
