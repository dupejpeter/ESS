#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <ctype.h>
#include <vector>
#include <unistd.h>
#include <cmath>
#include <iomanip>
#include <stdlib.h>

using namespace std;

int main()
{
    int i, j, k, MatrixSize, M, n, x, y;
    cout << "Enter Matrix Size:" << endl;
    cin >> M;
    
    double V[M][M],left_plate,right_plate, cylinder_potential, radius, x_centre, y_centre;
    
    ofstream FDM_data("FDM_Data.dat");
    
    cout << "enter boundary conditions" << endl;
    cout << "Please enter the Left hand plate's potential" << endl;
    cin >> left_plate;
    cout << "Please enter the RIGHT hand plate's potential" << endl;
    cin >> right_plate;
    cout << "Please enter the CYLINDER's potential - enter ZERO for it to be grounded" << endl;
    cin >> cylinder_potential;
    cout << "Enter radius of the Cylinder" << endl;
    cin >> radius;
    cout << "Enter x component of the cylinder centre" << endl;
    cin >> x_centre;
    cout << "Enter y component of the cylinder centre" << endl;
    cin >> y_centre;
    
    for(i=0; i<M; i++)
    {
        V[i][0] = left_plate;
        V[i][M-1] = right_plate;

    }
    
    for(i=0; i<M; i++)
    {
        for(j=1; j<M-1; j++)
        {
            V[i][j] = 0;
        }
    }

    for(i=1; i<M-1; i++)
    {
        for(j=0; j<M; j++)
        {
            if((pow((i-x_centre),2)+pow((j-y_centre),2))<=(pow(radius,2)))
            V[i][j] = 0;
        }
    }
        
    for(k=0; k<100000; k++)
    {
        for(i=0; i<M; i++)
        {
            for(j=1; j<M-1; j++)
            {
                if((pow((i-x_centre),2)+pow((j-y_centre),2))<=(pow(radius,2)))
                V[i][j] = cylinder_potential;
            	
            	else if(i==0)
            	{
            		V[0][j] = 0.25*(2*V[1][j]+2*((V[1][j]-V[0][j]))+V[0][j+1]+V[0][j-1]);
            	}
            	else if(i==M-1)
            	{
         		    V[M-1][j] = 0.25*(2*V[M-1][j]+2*((V[M-2][j]-V[M-1][j]))+V[M-1][j+1]+V[M-1][j-1]);
            	}
            	else
            	{
                	V[i][j] = 0.25*(V[i][j-1] + V[i][j+1] + V[i-1][j] + V[i+1][j]);
                }
            }
        }
    }
    
    
    cout << "OUTPUT MATRIX" << endl;
//     cout << setprecision(5);   
    for(i=0; i<M; i++)
    {
        for(j=0; j<M; j++)
        {
            if (FDM_data != NULL)
               FDM_data << V[i][j] << "\t";
            cout << V[i][j] << "\t";
        }
        FDM_data << endl;
        cout << endl;
    }
return 0;
}