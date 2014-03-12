/*
 * File_test.cpp
 *
 *  Created on: 6 Mar 2014
 *      Author: Peter
 */

#include "File.h"
#include <iostream>

using namespace std;

void test_LoadDataFile() {
	Grid g = File::LoadDataFile("data.dat");
	File::SaveDataFile(g, "data_copy.dat");
	cout << g.GetPot(0,0) << endl;
}

void test_SaveDataFile() {
	Grid g = Grid(3, 3);

	g.SetPot(0, 0, 5);
	g.SetPot(0, 1, 5);
	g.SetPot(0, 2, 5);

	g.SetPot(2, 0, -5);
	g.SetPot(2, 1, -5);
	g.SetPot(2, 2, -5);

	g.SetFixed(0, 0, 1);
	g.SetFixed(0, 1, 1);
	g.SetFixed(0, 2, 1);

	g.SetFixed(2, 0, 1);
	g.SetFixed(2, 1, 1);
	g.SetFixed(2, 2, 1);

	File::SaveDataFile(g, "data.dat");
}

int main() {
	test_LoadDataFile();
	return 0;
}
