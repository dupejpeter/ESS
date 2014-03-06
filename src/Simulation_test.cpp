/*
 * Simulation_test.cpp
 *
 *  Created on: 5 Mar 2014
 *      Author: Peter
 */

#include "Simulation.h"
#include "File.h"
#include <iostream>

using namespace std;

int main() {
	Grid g = File::LoadDataFile("data_in.dat");

	Simulation s = Simulation(&g);
	s.Run();

	File::SaveDataFile(g, "data_out.dat");
	return 0;
}
