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
#include <stdexcept>

using namespace std;

Grid * File::LoadDataFile(const char * strFileName) {
	ifstream inf(strFileName);
	string strInput;
	int nSizeX, nSizeY;
	float fInput;
	bool bInput;

	if (!inf) {
		throw runtime_error("Could not open file " + string(strFileName) + " !");
	}

	inf >> strInput; // #

	inf >> nSizeX;
	inf >> nSizeY;

	Grid * g = new Grid(nSizeX, nSizeY);

	for (int y = 0; y < g->GetSizeY(); y++) {
		for (int x = 0; x < g->GetSizeX(); x++){
			inf >> fInput;
			g->SetPot(x, y, fInput);
		}
	}

	for (int y = 0; y < g->GetSizeY(); y++) {
		inf >> strInput; // #
		for (int x = 0; x < g->GetSizeX(); x++){
			inf >> bInput;
			g->SetFixed(x, y, bInput);
		}
	}

	return g;
}

void File::SaveDataFile(Grid * g, const char * strFileName) {
	ofstream outf(strFileName);

	if (!outf) {
		throw runtime_error("Could not open file " + string(strFileName) + " for writing!");
	} else {
		outf << "# " << g->GetSizeX() << " " << g->GetSizeY() << endl;
		outf << fixed << showpoint;
		for (int y = 0; y < g->GetSizeY(); y++) {
			for (int x = 0; x < g->GetSizeX(); x++) {
				outf << g->GetPot(x, y) << " ";
			}
			outf << endl;
		}
		outf << endl;
		for (int y = 0; y < g->GetSizeY(); y++) {
			outf << "# ";
			for (int x = 0; x < g->GetSizeX(); x++) {
				outf << g->IsFixed(x, y) << " ";
			}
			outf << endl;
		}
	}

	outf.close();
}

void File::SaveDataFile(Grid * g, const char * strFileName, float fTime, int nIterationCount) {
	ofstream outf(strFileName);

	if (!outf) {
		throw runtime_error("Could not open file " + string(strFileName) + " for writing!");
	} else {
		outf << "# " << g->GetSizeX() << " " << g->GetSizeY() << endl;
		outf << fixed << showpoint;
		for (int y = 0; y < g->GetSizeY(); y++) {
			for (int x = 0; x < g->GetSizeX(); x++) {
				outf << g->GetPot(x, y) << " ";
			}
			outf << endl;
		}
		outf << endl;
		outf << "# Calculated in " << fTime << " ms and " << nIterationCount << " iterations." << endl;
	}

	outf.close();
}

void File::SaveDiffFile(Grid * diff, const char * strFileName) {
	ofstream outf(strFileName);

	if (!outf) {
		throw runtime_error("Could not open file " + string(strFileName) + " for writing!");
	} else {
		outf << "# " << diff->GetSizeX() << " " << diff->GetSizeY() << endl;
		outf << fixed << showpoint;
		for (int y = 0; y < diff->GetSizeY(); y++) {
			for (int x = 0; x < diff->GetSizeX(); x++) {
				outf << diff->GetPot(x, y) << " ";
			}
			outf << endl;
		}
		outf << endl;
	}

	outf.close();
}
