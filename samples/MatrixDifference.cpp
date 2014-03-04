/*#include <stdafx.h> - use when working with Visual Studio*/
#include <iostream>
#include <conio.h>
#include <math.h>
#include <stdlib.h>



using namespace std;


class matrix
{
public:
	int i, j, nRank;
	double adArray[100][100];

	matrix operator-(matrix m1);
	void input();
	void output();
	void maximum(matrix m1);
};

void matrix::input()
{
	cout << "\nEnter rank: ";
	cin >> nRank;
	cout << "\nEnter the elements:\n\n";
	for (i = 0; i < nRank; i++)
	{
		for (j = 0; j < nRank; j++)
		{
			cin >> adArray[i][j];
			cout << "\t";
		}
		cout << "\n";
	}
}
matrix matrix::operator-(matrix m1)
{
	matrix temp;
	temp.nRank = nRank;

	for (i = 0; i < temp.nRank; i++)
	for (j = 0; j < temp.nRank; j++)
	
	if (adArray[i][j] != 0) // Fraction is only defined when denominator is non-zero.
	
		temp.adArray[i][j] = (m1.adArray[i][j] - adArray[i][j]) / abs(adArray[i][j])*100;
		
	else // Use zero as placeholder as infinite increase / decrease cannot be used for proper comparison, anyway.

		temp.adArray[i][j] = 0;

	return temp;
}

void matrix::output()
{
	cout << "Matrix is:\n\n";
	for (i = 0; i < nRank; i++)
	{
		for (j = 0; j < nRank; j++)
			cout << adArray[i][j] << "\t";
		cout << "\n";
	}

}

void matrix::maximum(matrix m1)
{
	int index1 = 0;
	int index2 = 0;

	for (i = 0; i < nRank; i++)
	for (j = 0; j < nRank; j++)
	if (abs(m1.adArray[i][j]) > abs(m1.adArray[index1][index2]))
	{
		index1 = i;
		index2 = j;

	}

	cout << "The maximum value is attained for element " << index1 + 1 << "-" <<
		index2 + 1 << ", corresponding to a value of " << m1.adArray[index1][index2] << ".\n";
}

int main()
{
	matrix m1, m2, m3;

	m1.input();
	m2.input();

	m3 = m1 - m2;

	m3.output();
	m3.maximum(m3);

	getch(); //_getch when using Visual Studio

	return 0;

}
