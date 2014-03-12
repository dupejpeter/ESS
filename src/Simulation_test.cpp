/*
 * Simulation_test.cpp
 *
 *  Created on: 5 Mar 2014
 *      Author: Peter
 */

#include "Simulation.h"
#include "File.h"
#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
	try {
		Grid g = File::LoadDataFile("in.dat");

		Simulation s = Simulation(&g);
		s.SetMaxIteration(1000);
		s.SetThreshold(0.000001);
		s.Run(true);

		File::SaveDataFile(g, "data_out.dat");
	} catch (runtime_error &e) {
		cerr << "File Error: " << e.what() << endl;
	}
	return 0;
}
