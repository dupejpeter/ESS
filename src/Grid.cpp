/*
 * Grid.cpp
 *
 *  Created on: 2 Mar 2014
 *      Author: Peter
 */

#include "Grid.h"
#include <stdexcept>	//	invalid_argument, out_of_range

using namespace std;

Grid::Grid(int nSizeX, int nSizeY) {
	checkSize(nSizeX, nSizeY);
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
	checkSize(nSizeX, nSizeY);
	m_nSizeX = nSizeX;
	m_nSizeY = nSizeY;
	m_afPotential = afPotential;
	m_abFixed = abFixed;
}

Grid::~Grid() {
	for (int y = 0; y < m_nSizeY; y++) {
		delete[] m_afPotential[y];
		delete[] m_abFixed[y];
	}

	delete[] m_afPotential;
	delete[] m_abFixed;

	m_nSizeX = 0;
	m_nSizeY = 0;
}

void Grid::checkSize(int nSizeX, int nSizeY) {
	if (nSizeX < 1)
		throw invalid_argument("Argument nSizeX is less than 1!");
	if (nSizeY < 1)
		throw invalid_argument("Argument nSizeY is less than 1!");
}

void Grid::checkBounds(int nX, int nY){
	if (nX < 0 || nX >= m_nSizeX)
		throw out_of_range("Index nX is out of range!");
	if (nY < 0 || nY >= m_nSizeY)
		throw out_of_range("Index nY is out of range!");
}

int Grid::getSizeX() {
	return m_nSizeX;
}

int Grid::getSizeY() {
	return m_nSizeY;
}

float Grid::getPot(int nX, int nY) {
	checkBounds(nX, nY);
	return m_afPotential[nY][nX];
}

void Grid::setPot(int nX, int nY, float fPot) {
	checkBounds(nX, nY);
	m_afPotential[nY][nX] = fPot;
}

bool Grid::isFixed(int nX, int nY) {
	checkBounds(nX, nY);
	return m_abFixed[nY][nX];
}

void Grid::setFixed(int nX, int nY, bool bFixed) {
	checkBounds(nX, nY);
	m_abFixed[nY][nX] = bFixed;
}
