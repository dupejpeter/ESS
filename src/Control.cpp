//============================================================================
// Name        : Control.cpp
// Author      : Peter Dupej
// Version     : 1.0
// Copyright   : The MIT License (MIT)
// Description : Main control of the program
//============================================================================

#include "File.h"
#include "Simulation.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdexcept>

using namespace std;

#define F_IMPORT 1
#define NUM_A 2
#define ANA_A 3
#define NUM_C 4
#define DIFF_F 1
#define DIFF_A 2

Grid * g;
Grid * g2;
Grid * diff;
Simulation * sim;
char * strFileName = "in.dat";
int nGrid = 0;
int nSizeX = 10;
int nSizeY = 10;
float fVp = 5.0;
float fVn = -5.0;
float fGND = 0.0;
float fR = 0.2;
float fD = 1.0;
char * strOFileName = "out.dat";
float fPrecission = 0.001;
int nMaxIteration = 1000;
bool bVerbose = false;
bool bNoSim = false;
bool bPot = false;
bool bMap = false;
bool bFL = false;
bool bEPL = false;
int nDiff = 0;
char * strDiffFileName;
char * strDiffOFileName = "diff.dat";

void help() {
	// TODO HELP
	cout << "TODO HELP" << endl;
}

int main(int argc, char *argv[]) {
	for (int nArg=1; nArg < argc; nArg++) {
		if (string(argv[nArg]) == "-f") {
			nArg++;
			strFileName = argv[nArg];
			nGrid = F_IMPORT;
		} else if (string(argv[nArg]) == "-numA") {
			nGrid = NUM_A;
		} else if (string(argv[nArg]) == "-anaA") {
			nGrid = ANA_A;
		} else if (string(argv[nArg]) == "-numC") {
			nGrid = NUM_C;
		} else if (string(argv[nArg]) == "-s" || string(argv[nArg]) == "--size") {
			nArg++;
			nSizeX = atoi(argv[nArg]);
			nSizeY = nSizeX;
		} else if (string(argv[nArg]) == "-X" || string(argv[nArg]) == "--sizeX") {
			nArg++;
			nSizeX = atoi(argv[nArg]);
		} else if (string(argv[nArg]) == "-Y" || string(argv[nArg]) == "--sizeY") {
			nArg++;
			nSizeY = atoi(argv[nArg]);
		} else if (string(argv[nArg]) == "-V") {
			nArg++;
			fVp = atof(argv[nArg]);
			fVn = fVp;
		} else if (string(argv[nArg]) == "-Vp") {
			nArg++;
			fVp = atof(argv[nArg]);
		} else if (string(argv[nArg]) == "-Vn") {
			nArg++;
			fVn = atof(argv[nArg]);
		} else if (string(argv[nArg]) == "-GND") {
			nArg++;
			fGND = atof(argv[nArg]);
		} else if (string(argv[nArg]) == "-r") {
			nArg++;
			fR = atof(argv[nArg]);
		} else if (string(argv[nArg]) == "-d") {
			nArg++;
			fD = atof(argv[nArg]);
		} else if (string(argv[nArg]) == "-o" || string(argv[nArg]) == "--output") {
			nArg++;
			strOFileName = argv[nArg];
		} else if (string(argv[nArg]) == "-p" || string(argv[nArg]) == "--precision") {
			nArg++;
			fPrecission = atof(argv[nArg]);
		} else if (string(argv[nArg]) == "-m" || string(argv[nArg]) == "--maxIteration") {
			nArg++;
			nMaxIteration = atoi(argv[nArg]);
		} else if (string(argv[nArg]) == "-v" || string(argv[nArg]) == "--verbose") {
			bVerbose = true;
		} else if (string(argv[nArg]) == "-ns" || string(argv[nArg]) == "--nosim") {
			bNoSim = true;
		} else if (string(argv[nArg]) == "-pot") {
			bPot = true;
		} else if (string(argv[nArg]) == "-map") {
			bMap = true;
		} else if (string(argv[nArg]) == "-fl" || string(argv[nArg]) == "--fieldlines") {
			bFL = true;
		} else if (string(argv[nArg]) == "-epl" || string(argv[nArg]) == "--equipotlines") {
			bEPL = true;
		} else if (string(argv[nArg]) == "-diff") {
			nArg++;
			strDiffFileName = argv[nArg];
			nDiff = DIFF_F;
		} else if (string(argv[nArg]) == "-diffA") {
			nDiff = DIFF_A;
		} else if (string(argv[nArg]) == "-diffo") {
			nArg++;
			strDiffOFileName = argv[nArg];
		} else if (string(argv[nArg]) == "-h" || string(argv[nArg]) == "--help") {
			help();
			return 0;
		} else {
			cerr << "Unknown argument " << argv[nArg] << "!" << endl;
			cerr << "Please use option -h or --help to see argument syntax." << endl;
			return 0;
		}
	}

	switch (nGrid) {
	case F_IMPORT:
		try {
			g = File::LoadDataFile(strFileName);
		} catch (runtime_error &e) {
			cerr << "File Error: " << e.what() << endl;
			return 0;
		}
		break;
	case NUM_A:
		g = Grid::CreateNumericA(nSizeX, nSizeY, fVp, fVn, fGND, fR);
		break;
	case ANA_A:
		g = Grid::CreateAnalyticA(nSizeX, nSizeY, fVp, fVn, fGND, fR, fD);
		break;
	case NUM_C:
		g = Grid::CreateNumericC(nSizeX, nSizeY, fVp, fGND);
		break;
	default:
		cerr << "No input specified!" << endl;
		cerr << "Please use option -f FILENAME to import data from file." << endl;
		cerr << "Use --help to see more options." << endl;
		return 0;
	}

	if (!bNoSim) {
		sim = new Simulation(g);
		sim->SetMaxIteration(nMaxIteration);
		sim->SetThreshold(fPrecission);
		sim->Run(bVerbose);
		File::SaveDataFile(g, strOFileName, sim->GetSimulationTime(), sim->GetIterationCount());
	} else {
		File::SaveDataFile(g, strOFileName);
	}

	// TODO gnuploting
	if (bPot) {

	}
	if (bMap) {

	}
	if (bFL) {

	}
	if (bEPL) {

	}

	switch (nDiff) {
	case DIFF_F:
		try {
			g2 = File::LoadDataFile(strDiffFileName);
		} catch (runtime_error &e) {
			cerr << "File Error: " << e.what() << endl;
			return 0;
		}
		break;
	case DIFF_A:
		g2 = Grid::CreateAnalyticA(nSizeX, nSizeY, fVp, fVn, fGND, fR, fD);
		break;
	}
	if (nDiff) {
		diff = g->Diff(g2);
		File::SaveDiffFile(diff, strDiffOFileName);
		//
	}

	return 0;
}
