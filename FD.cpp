// Numerical Evaluation of our electrostatics problem
// Finite Difference Method
//
//
// 03/02/2014
// Brobee


//Things to do: Output file to graph, compare with numerical, stop loop once within error bounds. 


#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <cmath>

using namespace std;

int main()
{

  //Defining Matrix Size

  cout << "Please enter the size of matrix you desire. (nxn)"<< endl;
  int nMatSize;
  cin >> nMatSize;
  nMatSize = nMatSize;
  

  // Defining Potentials
 
  cout << "Enter Potential of Left hand Plate:" << endl;
  double dPlateL;
  cin >> dPlateL;

  
  cout << "And the Right Hand Plate:" << endl;
  double dPlateR;
  cin >> dPlateR;

  cout << "And the cylinder:" << endl;
  double dCylP;
  cin >> dCylP;

  // Defining radius of cylinder.

  cout << "Enter cylinder radius:" << endl;
  int nCylR;
  cin >> nCylR;

  // Deviation of cylinder from centre

  cout << "Enter deviation of cylinder from the centre(+ve right, -ve left)" << endl;
  int nDev;
  cin >> nDev;

  // Centre of cylinder

  int nCylCentX;
  nCylCentX = (nMatSize / 2) + nDev;
  int nCylCentY;
  nCylCentY = nMatSize / 2;

  //  Defining the linear difference for the initial matrix and in the limit

  double dLinearDiff;
  dLinearDiff = (dPlateR - dPlateL)/(nMatSize-1);

  //Defining the starting array

  double pX [nMatSize][nMatSize];
  for (int iii = 1; iii < nMatSize; iii++ )
    for (int jjj = 0; jjj < nMatSize; jjj++ )
      {
	pX[0][jjj] = dPlateL;
	if (pow(iii - nCylCentX,2) + pow(jjj - nCylCentY,2) > pow(nCylR,2))
	  pX[iii][jjj] =  dPlateL + iii * dLinearDiff;
	else
	  pX[iii][jjj] = dCylP;
      }


 // Iterations

 cout << "How many iterations would you like?" << endl;
 int nI;
 cin >> nI; 
 
 for (int nnn = 1; nnn <= nI; nnn++)
   for (int iii = 1; iii < nMatSize - 1; iii++)
     for (int jjj = 0; jjj < nMatSize; jjj++)
       {

	 // Neumann at top and bottom

	 if (jjj == 0)
	   pX[iii][0] = 0.25*(2*pX[iii][0]+2*((pX[iii][1]-pX[iii][0]))+pX[iii+1][0]+pX[iii-1][0]);

	 else if (jjj == nMatSize - 1)
	   pX[iii][nMatSize - 1] = 0.25*(2*pX[iii][nMatSize - 1]+2*((pX[iii][nMatSize - 2]-pX[iii][nMatSize - 1]))+pX[iii+1][nMatSize - 1]+pX[iii-1][nMatSize - 1]);

	 // Iterations on all except the cylinder

	 else if (pow(iii - nCylCentX,2) + pow(jjj - nCylCentY,2) > pow(nCylR,2))
	   pX[iii][jjj] =  0.25 * (pX[iii+1][jjj] + pX[iii-1][jjj] + pX[iii][jjj+1] + pX[iii][jjj-1]);
       }
   
  //Display matrix

  cout << "Here is your matrix after " << nI << " iterations:" << endl;

  cout << setprecision(2);

  for (int jjj = 0; jjj < nMatSize; jjj++ )
    {
    for (int iii = 0; iii < nMatSize; iii++ )
      {
	cout << pX[iii][jjj] << " ";
      }
    cout << endl;
    }
}
