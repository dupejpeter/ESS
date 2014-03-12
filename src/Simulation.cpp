/*
 * Simulation.cpp
 *
 *  Created on: 5 Mar 2014
 *      Author: Peter
 */

#include "Simulation.h"
#include "File.h"
#include <iostream>
#include <time.h>
#include <cmath>

Simulation::Simulation(Grid * g) {
	m_grid = g;
	m_nMaxIteration = 100;
	m_nIterationCount = 0;
	m_fThreshold = 0.00001;
	m_fTime = 0;
}

void Simulation::SetMaxIteration(int nMaxIteration) {
	m_nMaxIteration = nMaxIteration;
}

int Simulation::GetMaxIteration() {
	return m_nMaxIteration;
}

int Simulation::GetIterationCount() {
	return m_nIterationCount;
}

void Simulation::SetThreshold(float fThreshold) {
	m_fThreshold = fThreshold;
}

float Simulation::GetThreshold() {
	return m_fThreshold;
}

void Simulation::Run(bool bVerbose) {
	cout << "Simulation running";
	float fError;
	float fNewPot;

	clock_t tStart = clock();
	do {
		m_nIterationCount++;
		if (bVerbose) {
			//if (m_nIterationCount % (m_nMaxIteration / 100) == 0) {
			cout << ".";
			//}
		}
		fError = 0;
		for (int y = 0; y < m_grid->GetSizeY(); y++) {
			for (int x = 0; x < m_grid->GetSizeX(); x++) {
				if (!m_grid->IsFixed(x, y)) {
					fNewPot = 0;
					if (x == 0 || x == m_grid->GetSizeX() - 1) {
						fNewPot += 2*m_grid->GetPot(x, y);
					} else {
						fNewPot += m_grid->GetPot(x - 1, y) + m_grid->GetPot(x + 1, y);
					}
					if (y == 0 || y == m_grid->GetSizeX() - 1) {
						fNewPot += 2*m_grid->GetPot(x, y);
					} else {
						fNewPot += m_grid->GetPot(x, y - 1) + m_grid->GetPot(x, y + 1);
					}
					fNewPot /= 4;
					if (fError < (abs(fNewPot - m_grid->GetPot(x, y))))
					{
						fError = abs(fNewPot - m_grid->GetPot(x, y));
					}
					m_grid->SetPot(x, y, fNewPot);
				}
			}
		}
	} while (fError > m_fThreshold && m_nIterationCount < m_nMaxIteration);
	m_fTime = (float)(clock() - tStart)/CLOCKS_PER_SEC;

	cout << endl;
	cout << "Stopped after " << GetSimulationTime() << " ms and " << m_nIterationCount << " iterations." << endl;
}

Grid * Simulation::GetGrid() {
	return m_grid;
}

float Simulation::GetSimulationTime() {
	return m_fTime;
}
