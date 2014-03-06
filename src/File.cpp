/*
 * File.cpp
 *
 *  Created on: 6 Mar 2014
 *      Author: Peter
 */

#include "File.h"
#include "Grid.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

void File::SaveDatafile(Grid& g, const char* strFileName) {
	ofstream outf(strFileName);

	if (!outf) {
		cerr << "File could not be opened for writing!" << endl;
	} else {
		outf << "# " << g.getSizeX() << " " << g.getSizeY() << endl;
		for (int y = 0; y < g.getSizeY(); y++) {
			for (int x = 0; x < g.getSizeX(); x++) {
				outf << g.getPot(x, y) << " ";
			}
			outf << endl;
		}
		outf << endl;
		for (int y = 0; y < g.getSizeY(); y++) {
			outf << "#";
			for (int x = 0; x < g.getSizeX(); x++) {
				outf << g.isFixed(x, y);
			}
			outf << endl;
		}
	}

	outf.close();
}
