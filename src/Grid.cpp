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
	CheckSize(nSizeX, nSizeY);
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

void Grid::CheckSize(int nSizeX, int nSizeY) {
	if (nSizeX < 1)
		throw invalid_argument("Argument nSizeX is less than 1!");
	if (nSizeY < 1)
		throw invalid_argument("Argument nSizeY is less than 1!");
}

void Grid::CheckBounds(int nX, int nY){
	if (nX < 0 || nX >= m_nSizeX)
		throw out_of_range("Index nX is out of range!");
	if (nY < 0 || nY >= m_nSizeY)
		throw out_of_range("Index nY is out of range!");
}

int Grid::GetSizeX() {
	return m_nSizeX;
}

int Grid::GetSizeY() {
	return m_nSizeY;
}

float Grid::GetPot(int nX, int nY) {
	CheckBounds(nX, nY);
	return m_afPotential[nY][nX];
}

void Grid::SetPot(int nX, int nY, float fPot) {
	CheckBounds(nX, nY);
	m_afPotential[nY][nX] = fPot;
}

bool Grid::IsFixed(int nX, int nY) {
	CheckBounds(nX, nY);
	return m_abFixed[nY][nX];
}

void Grid::SetFixed(int nX, int nY, bool bFixed) {
	CheckBounds(nX, nY);
	m_abFixed[nY][nX] = bFixed;
}

Grid * Grid::Diff(Grid * g2) {
	if (m_nSizeX != g2->GetSizeX() || m_nSizeY != g2->GetSizeY())
		throw invalid_argument("Grid sizes do not match!");

	Grid * diff = new Grid(m_nSizeX, m_nSizeY);

	for (int y = 0; y < m_nSizeY; y++) {
		for (int x = 0; x < m_nSizeX; x++) {
			diff->SetPot(x, y, (GetPot(x, y) / g2->GetPot(x, y) - 1));
		}
	}

	return diff;
}

Grid * Grid::CreateAnalyticProbA(int nSizeX, int nSizeY, float fVp, float fVn, float fGND, float fR, float fD) {
	Grid * g = new Grid(nSizeX, nSizeY);

	return g;
}

Grid * Grid::CreateNumericProbA(int nSizeX, int nSizeY, float fVp, float fVn, float fGND, float fR) {
	Grid * g = new Grid(nSizeX, nSizeY);

	return g;
}

Grid * Grid::CreateNumericProbC(int nSizeX, int nSizeY, float fVp, float fVn, float fGND) {
	Grid * g = new Grid(nSizeX, nSizeY);

	return g;
}
