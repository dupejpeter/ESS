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
	float ** m_afPotential;
	bool ** m_abFixed;

	void checkSize(int nSizeX, int nSizeY);
	void checkBounds(int nX, int nY);

public:
	Grid(int nSizeX, int nSizeY);
	Grid(int nSizeX, int nSizeY, float ** afPotential, bool ** abFixed);
	int getSizeX();
	int getSizeY();
	float getPot(int nX, int nY);
	void setPot(int nX, int nY, float fPot);
	bool isFixed(int nX, int nY);
	void setFixed(int nX, int nY, bool bFixed);
};

#endif /* Grid_H */
