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

	inf >> nSizeX;
	inf >> nSizeY;

	Grid g = Grid(nSizeX, nSizeY);

	for (int y = 0; y < g.GetSizeY(); y++) {
		for (int x = 0; x < g.GetSizeX(); x++){
			inf >> fInput;
			g.SetPot(x, y, fInput);
		}
	}

	for (int y = 0; y < g.GetSizeY(); y++) {
		inf >> strInput;
		for (int x = 0; x < g.GetSizeX(); x++){
			inf >> bInput;
			g.SetFixed(x, y, bInput);
		}
	}

	return g;
}

void File::SaveDataFile(Grid & g, const char * strFileName) {
	ofstream outf(strFileName);

	if (!outf) {
		cerr << "File could not be opened for writing!" << endl;
	} else {
		outf << "# " << g.GetSizeX() << " " << g.GetSizeY() << endl;
		outf << showpoint;
		for (int y = 0; y < g.GetSizeY(); y++) {
			for (int x = 0; x < g.GetSizeX(); x++) {
				outf << g.GetPot(x, y) << " ";
			}
			outf << endl;
		}
		outf << endl;
		for (int y = 0; y < g.GetSizeY(); y++) {
			outf << "# ";
			for (int x = 0; x < g.GetSizeX(); x++) {
				outf << g.IsFixed(x, y) << " ";
			}
			outf << endl;
		}
	}

	outf.close();
}
