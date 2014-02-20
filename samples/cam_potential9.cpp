#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <ctype.h>
#include <vector>
#include <unistd.h>
#include <cmath>

using namespace std;

int main()
{
    int i, j, k, MatrixSize, M, n, x, y;
    cout << "Enter Matrix Size:" << endl;
    cin >> M;
    
    double V[M][M],l,r,t,b,h,radius,x_centre, y_centre;
    
    ofstream FDM_data("FDM_Data.dat");
    
    cout << "enter boundary conditions" << endl;
    cout << "LHS value" << endl;
    cin >> l;
    cout << "RHS value" << endl;
    cin >> r;
    cout << "Enter radius of Cylinder" << endl;
    cin >> radius;
    cout << "Enter x component of the cylinder centre" << endl;
    cin >> x_centre;
    cout << "Enter y component of the cylinder centre" << endl;
    cin >> y_centre;
    
    for(i=0; i<M; i++)
    {
        V[i][0] = l;
        V[i][M-1] = r;

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
                V[i][j] = 0;
            	
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
    for(i=0; i<M; i++)
    {
        for(j=0; j<M; j++)
        {
            if (FDM_data != NULL)
                FDM_data << V[i][j] << "\t";
            cout << V[i][j] << "\t";
        }
        cout << endl;
    }
return 0;
}