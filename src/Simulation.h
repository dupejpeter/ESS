/*
 * Simulation.h
 *
 *  Created on: 5 Mar 2014
 *      Author: Peter
 */

#ifndef SIMULATION
#define SIMULATION

#include "Grid.h"

class Simulation {
	Grid * m_grid;
	int m_nMaxIteration;
	int m_nIterationCount;
	float m_fThreshold;
	float m_fTimeStart;
	float m_fTimeEnd;

public:
	Simulation(Grid * g);
	void SetMaxIteration(int nMaxIteration);
	int GetMaxIteration();
	int GetIterationCount();
	void SetThreshold(float fThreshold);
	float GetThreshold();
	void Run();
	Grid * GetGrid();
	float GetSimulationTime();
};

#endif /* SIMULATION */
