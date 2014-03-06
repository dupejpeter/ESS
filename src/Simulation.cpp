/*
 * Simulation.cpp
 *
 *  Created on: 5 Mar 2014
 *      Author: Peter
 */

#include "Simulation.h"
#include "File.h"
#include <iostream>

Simulation::Simulation(Grid * g) {
	m_grid = g;
	m_nMaxIteration = 1000;
	m_nIterationCount = 0;
	m_fThreshold = 0.1;
	m_fTimeStart = 0;
	m_fTimeEnd = 0;
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

void Simulation::Run() {
	//cout << m_grid->GetSizeX() << endl;
	//cout << "Simulation running" << endl;
	//m_grid->SetFixed(1,1,1);
}

Grid * Simulation::GetGrid() {
	return m_grid;
}

float Simulation::GetSimulationTime() {
	return m_fTimeEnd - m_fTimeStart;
}
