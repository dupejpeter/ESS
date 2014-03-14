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
	~Grid();
	int GetSizeX();
	int GetSizeY();
	float GetPot(int nX, int nY);
	void SetPot(int nX, int nY, float fPot);
	bool IsFixed(int nX, int nY);
	void SetFixed(int nX, int nY, bool bFixed);
	Grid * Diff(Grid * g2);
	static Grid * CreateAnalyticA(int nSizeX, int nSizeY, float fV, float fGND, float fR);
	static Grid * CreateNumericA(int nSizeX, int nSizeY, float fV, float fGND, float fR);
	static Grid * CreateNumericC(int nSizeX, int nSizeY, float fV, float fGND);
};

#endif /* Grid_H */
