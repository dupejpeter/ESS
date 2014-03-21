/*
 * Grid.cpp
 *
 *  Created on: 2 Mar 2014
 *      Author: Peter
 */

#include "Grid.h"
#include <stdexcept>	//	invalid_argument, out_of_range
#include <math.h>
#include <iostream>

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
			diff->SetPot(x, y, (GetPot(x, y) - g2->GetPot(x, y)));
		}
	}

	return diff;
}

Grid * Grid::CreateAnalyticA(int nSizeX, int nSizeY, float fV, float fGND, float fR) {
	Grid * g = new Grid(nSizeX, nSizeY);

	for (int y = 0; y < nSizeY; y++) {
		for (int x = 0; x < nSizeX; x++) {
			if (x == 0) {
				g->SetPot(x, y, fGND + fV);
				g->SetFixed(x, y, 1);
			} else if (x == nSizeX - 1) {
				g->SetPot(x, y, fGND -fV);
				g->SetFixed(x, y, 1);
			} else if ((x - (nSizeX - 1)/2.0)*(x - (nSizeX - 1)/2.0) + (y - (nSizeY - 1)/2.0)*(y - (nSizeY - 1)/2.0) < fR*fR*nSizeX*nSizeX) {
				g->SetPot(x, y, fGND);
				g->SetFixed(x, y, 1);
			} else {
				float fPot = fGND + (2*fV) / (nSizeX - 1) * (fR*fR*nSizeX*nSizeX/((x - (nSizeX - 1)/2.0)*(x - (nSizeX - 1)/2.0) + (y - (nSizeY - 1)/2.0)*(y - (nSizeY - 1)/2.0)) - 1)*(x - (nSizeX - 1)/2.0);
				g->SetPot(x, y, fPot);
				g->SetFixed(x, y, 1);
			}
		}
	}

	return g;
}

Grid * Grid::CreateNumericA(int nSizeX, int nSizeY, float fV, float fGND, float fR) {
	Grid * g = new Grid(nSizeX, nSizeY);

	for (int y = 0; y < nSizeY; y++) {
		for (int x = 0; x < nSizeX; x++) {
			if (x == 0) {
				g->SetPot(x, y, fGND + fV);
				g->SetFixed(x, y, 1);
			} else if (x == nSizeX - 1) {
				g->SetPot(x, y, fGND - fV);
				g->SetFixed(x, y, 1);
			} else if ((x - (nSizeX - 1)/2.0)*(x - (nSizeX - 1)/2.0) + (y - (nSizeY - 1)/2.0)*(y - (nSizeY - 1)/2.0) < fR*fR*nSizeX*nSizeX) {
				g->SetPot(x, y, fGND);
				g->SetFixed(x, y, 1);
			} else {
				g->SetPot(x, y, 0.0);
				g->SetFixed(x, y, 0);
			}
		}
	}

	return g;
}

Grid * Grid::CreateNumericC(int nSizeX, int nSizeY, float fV, float fGND) {
	Grid * g = new Grid(nSizeX, nSizeY);

	float fHeight = 0.2;
	float fWidth = 0.2;
	int nCount = 3;

	//Magic in Slovak language follows :D :D
	//I'm not kidding ... I have no idea how it works ...
	//It works and when I tried to change anything it stopped :D
	int blok = nSizeX/nCount;
	int sirka = fWidth*nSizeX;
	int posun = ceil((blok - sirka)/2.0) - blok;
	//(x - posun) % blok < sirka

	for (int y = 0; y < nSizeY; y++) {
		for (int x = 0; x < nSizeX; x++) {
			if (y == nSizeY - 1) {
				g->SetPot(x, y, fV);
				g->SetFixed(x, y, 1);
			} else if ((y == 0 || y < fHeight*nSizeY) && ((x - posun) % blok < sirka)) {
				g->SetPot(x, y, fGND);
				g->SetFixed(x, y, 1);
			} else {
				g->SetPot(x, y, 0.0);
				g->SetFixed(x, y, 0);
			}
		}
	}

	return g;
}
