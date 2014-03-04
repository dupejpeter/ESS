/*
 * Grid_test.cpp
 *
 *  Created on: 3 Mar 2014
 *      Author: Peter
 */

#include "Grid.h"
#include <iostream>

using namespace std;

int main() {
	Grid g = Grid(1, 0);
	cout << g.getSizeX();
	//g.setPot(0, 0, 9.9);
	//cout << "g.getPot(0, 0) = " << g.getPot(0, 0);
	return 0;
}
