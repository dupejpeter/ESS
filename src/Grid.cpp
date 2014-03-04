/*
 * Grid.cpp
 *
 *  Created on: 2 Mar 2014
 *      Author: Peter
 */

#include "Grid.h"
#include <cassert>

Grid::Grid(int nSizeX, int nSizeY) {
	assert(nSizeX > 0 && nSizeY > 0); // TODO rework to exceptions
	m_nSizeX = nSizeX;	// columns
	m_nSizeY = nSizeY;	// rows

	m_afPotential = new float*[m_nSizeY];
	m_abFixed = new bool*[m_nSizeY];

	for (int y = 0; y < m_nSizeY; y++) {
		m_afPotential[y] = new float[m_nSizeX];
		m_abFixed[y] = new bool[m_nSizeX];
		for (int x = 0; x < m_nSizeX; x++) {
			m_afPotential[y][x] = 0;
			m_abFixed[y][x] = 0;
		}
	}
}

Grid::Grid(int nSizeX, int nSizeY, float ** afPotential, bool ** abFixed) {
	assert(nSizeX > 0 && nSizeY > 0); // TODO rework to exceptions
	m_nSizeX = nSizeX;
	m_nSizeY = nSizeY;
	m_afPotential = afPotential;
	m_abFixed = abFixed;
	// TODO check memory consistency
}

int Grid::getSizeX() {
	return m_nSizeX;
}

int Grid::getSizeY() {
	return m_nSizeY;
}

float Grid::getPot(int nX, int nY) {
	// TODO check for index X,Y out of bounds
	return m_afPotential[nY][nX];
}

void Grid::setPot(int nX, int nY, float fPot) {
	// TODO check for index X,Y out of bounds
	m_afPotential[nY][nX] = fPot;
}

bool Grid::isFixed(int nX, int nY) {
	// TODO check for index X,Y out of bounds
	return m_abFixed[nY][nX];
}

void Grid::setFixed(int nX, int nY, bool bFixed) {
	// TODO check for index X,Y out of bounds
	m_abFixed[nY][nX] = bFixed;
}
