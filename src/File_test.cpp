/*
 * File_test.cpp
 *
 *  Created on: 6 Mar 2014
 *      Author: Peter
 */

#include "File.h"

using namespace std;

void test_LoadDataFile() {
	Grid g = File::LoadDataFile("data.dat");
	File::SaveDataFile(g, "data_copy.dat");
}

void test_SaveDataFile() {
	Grid g = Grid(3, 3);

	g.setPot(0, 0, 5.32);
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

	File::SaveDataFile(g, "data.dat");
}

int main() {
	test_LoadDataFile();
	return 0;
}
