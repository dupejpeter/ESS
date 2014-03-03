/*
 * Grid.cpp
 *
 *  Created on: 2 Mar 2014
 *      Author: Peter
 */

#include "Grid.h"

Grid::Grid() {
	m_nSizeX = 0;
	m_nSizeY = 0;
	m_fPotential = 0;
	m_bFixed = 0;
}

Grid::Grid(int nSizeX, int nSizeY) {
	m_nSizeX = nSizeX;
	m_nSizeY = nSizeY;
	// TODO memory allocation for m_fPotential and m_bFixed
}

Grid::Grid(int nSizeX, int nSizeY, float ** fPotential, bool ** bFixed) {
	m_nSizeX = nSizeX;
	m_nSizeY = nSizeY;
	// TODO check memory consistency
	m_fPotential = fPotential;
	m_bFixed = bFixed;
}

int Grid::getSizeX() {
	return m_nSizeX;
}

int Grid::getSizeY() {
	return m_nSizeY;
}

float Grid::getPot(int nX, int nY) {
	return m_fPotential[nX][nY];
}

void Grid::setPot(int nX, int nY, float fPot) {
	m_fPotential[nX][nY] = fPot;
}

bool Grid::isFixed(int nX, int nY) {
	return m_bFixed[nX][nY];
}
