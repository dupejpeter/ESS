/*
 * Grid.h
 *
 *  Created on: 2 Mar 2014
 *      Author: Peter
 */

#ifndef Grid_H
#define Grid_H

class Grid {
private:
	int m_nSizeX, m_nSizeY;
	float ** m_fPotential;
	bool ** m_bFixed;

	Grid();

public:
	Grid(int nSizeX, int nSizeY);
	Grid(int nSizeX, int nSizeY, float ** fPotential, bool ** bFixed);
	int getSizeX();
	int getSizeY();
	float getPot(int nX, int nY);
	void setPot(int nX, int nY, float fPot);
	bool isFixed(int nX, int nY);
};

#endif /* Grid_H */
