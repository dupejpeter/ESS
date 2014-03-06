/*
 * File_test.cpp
 *
 *  Created on: 6 Mar 2014
 *      Author: Peter
 */

#include "File.h"
#include <iostream>		//	cout, endl

using namespace std;

int main() {
	Grid g = Grid(3, 3);

	g.setPot(0, 0, 5);
	g.setPot(0, 1, 5);
	g.setPot(0, 2, 5);

	g.setPot(2, 0, -5);
	g.setPot(2, 1, -5);
	g.setPot(2, 2, -5);

	g.setFixed(0, 0, 1);
	g.setFixed(0, 1, 1);
	g.setFixed(0, 2, 1);

	g.setFixed(2, 0, 1);
	g.setFixed(2, 1, 1);
	g.setFixed(2, 2, 1);

	File::SaveDatafile(g, "data.dat");

	return 0;
}
