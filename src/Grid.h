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

	void CheckSize(int nSizeX, int nSizeY);
	void CheckBounds(int nX, int nY);

public:
	Grid(int nSizeX, int nSizeY);
	Grid(int nSizeX, int nSizeY, float ** afPotential, bool ** abFixed);
	~Grid();
	int GetSizeX();
	int GetSizeY();
	float GetPot(int nX, int nY);
	void SetPot(int nX, int nY, float fPot);
	bool IsFixed(int nX, int nY);
	void SetFixed(int nX, int nY, bool bFixed);
};

#endif /* Grid_H */
