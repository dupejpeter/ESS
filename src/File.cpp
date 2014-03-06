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

Grid File::LoadDataFile(const char * strFileName) {
	ifstream inf(strFileName);
	string strInput;
	int nSizeX, nSizeY;
	float fInput;
	bool bInput;

	if (!inf) {
		cerr << "File could not be opened for writing!" << endl;
	}

	inf >> strInput;
	cout << strInput << endl;

	inf >> nSizeX;
	inf >> nSizeY;

	Grid g = Grid(nSizeX, nSizeY);

	for (int y = 0; y < g.getSizeY(); y++) {
		for (int x = 0; x < g.getSizeX(); x++){
			inf >> fInput;
			g.setPot(x, y, fInput);
		}
	}

	for (int y = 0; y < g.getSizeY(); y++) {
		inf >> strInput;
		for (int x = 0; x < g.getSizeX(); x++){
			inf >> bInput;
			g.setFixed(x, y, bInput);
		}
	}

	return Grid(1,1);
}

void File::SaveDataFile(Grid& g, const char * strFileName) {
	ofstream outf(strFileName);

	if (!outf) {
		cerr << "File could not be opened for writing!" << endl;
	} else {
		outf << "# " << g.getSizeX() << " " << g.getSizeY() << endl;
		outf << showpoint;
		for (int y = 0; y < g.getSizeY(); y++) {
			for (int x = 0; x < g.getSizeX(); x++) {
				outf << g.getPot(x, y) << " ";
			}
			outf << endl;
		}
		outf << endl;
		for (int y = 0; y < g.getSizeY(); y++) {
			outf << "# ";
			for (int x = 0; x < g.getSizeX(); x++) {
				outf << g.isFixed(x, y) << " ";
			}
			outf << endl;
		}
	}

	outf.close();
}
