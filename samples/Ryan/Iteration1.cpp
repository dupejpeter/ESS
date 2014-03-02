#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <ctype.h>
#include <vector>
#include <unistd.h>
#include <cmath>
#include <iomanip>
#include "Iteration1.h"

using namespace std;
// tolerance is the number of decimal places desired.

    void Iteration(Grid& A, int tolerance, int maxiterations)
    {
        int kkk=0;
        double derror=0;

        do
    {
        double dold;
        double dnew;

        for(int i=0; i<A.nrows; i++)
        {
            for(int j=0; j<A.ncolumns; j++)
            {
                if(A.fixed[i][j]==0 && (i != 0) && (i != A.nrows-1) && (j != 0) && (j != A.ncolumns-1))

                {
                    dold = A.potential[i][j];
                	A.potential[i][j] = 0.25*(A.potential[i][j-1] + A.potential[i][j+1] + A.potential[i-1][j] + A.potential[i+1][j]);
                	dnew = A.potential[i][j];
            		if (derror < (abs (dnew-dold)))
                    {
                        derror = abs (dnew-dold);
                    }
                }

                //next four conditions deal with the four sides excluding corner values.

            	else if(A.fixed[i][j]==0 && (i == 0) && (j != 0) && (j != A.ncolumns-1))
            	{
            	    dold = A.potential[0][j];
            		A.potential[0][j] = 0.25*(2*A.potential[1][j]+2*((A.potential[0][j]-A.potential[1][j]))+A.potential[0][j+1]+A.potential[0][j-1]);
            		dnew = A.potential[0][j];
            		if (derror < (abs (dnew-dold)))
                    {
                        derror = abs (dnew-dold);
                    }
            	}

            	else if(A.fixed[i][j]==0 && (i==A.nrows-1) && (j!=A.ncolumns-1) && (j!=0))
            	{
            	    dold = A.potential[A.nrows-1][j];
         		    A.potential[A.nrows-1][j] = 0.25*(2*A.potential[A.nrows-2][j]+2*((A.potential[A.nrows-1][j]-A.potential[A.nrows-2][j]))+A.potential[A.nrows-1][j+1]+A.potential[A.nrows-1][j-1]);
         		    dnew = A.potential[A.nrows-1][j];
            		if (derror < abs (dnew-dold))
                    {
                        derror = abs (dnew-dold);
                    }
            	}

                else if(A.fixed[i][j]==0 && (j==0) && (i!=0) && (i!=A.nrows-1))
            	{
                    dold = A.potential[i][0];
            		A.potential[i][0] = 0.25*(2*A.potential[i][1]+2*((A.potential[i][0]-A.potential[i][1]))+A.potential[i+1][0]+A.potential[i-1][0]);
            		dnew = A.potential[i][0];
            		if (derror < (abs (dnew-dold)))
                    {
                        derror = abs (dnew-dold);
                    }
                }

                else if(A.fixed[i][j]==0 && (j==A.ncolumns-1) && (i!=0) && (i!=A.nrows-1))
            	{
            	    dold = A.potential[i][A.ncolumns-1];
         		    A.potential[i][A.ncolumns-1] = 0.25*(2*A.potential[i][A.ncolumns-2]+2*((A.potential[i][A.ncolumns-1]-A.potential[i][A.ncolumns-2]))+A.potential[i+1][A.ncolumns-1]+A.potential[i-1][A.ncolumns-1]);
         		    dnew = A.potential[i][A.ncolumns-1];
            		if (derror < abs (dnew-dold))
                    {
                        derror = abs (dnew-dold);
                    }
            	}


            	//next four conditions deal with the four corner points.

                else if(A.fixed[i][j]==0 && (i == 0) && (j == 0))
            	{
            	    dold = A.potential[i][j];
            		A.potential[i][j] = 0.5*(A.potential[1][0]+((A.potential[0][0]-A.potential[1][0]))+A.potential[0][1]+((A.potential[0][0]-A.potential[0][1])));
            		dnew = A.potential[i][j];
            		if (derror < (abs (dnew-dold)))
                    {
                        derror = abs (dnew-dold);
                    }
                    cout << A.potential[i][j] << endl;
            	}

                else if(A.fixed[i][j]==0 && (i == A.nrows-1) && (j == 0))
            	{
            	    dold = A.potential[i][j];
            		A.potential[i][j] = 0.5*(A.potential[A.nrows-2][j]+((A.potential[A.nrows-1][j]-A.potential[A.nrows-2][j]))+A.potential[A.nrows-1][j+1]+((A.potential[A.nrows-1][j]-A.potential[A.nrows-1][j+1])));
            		dnew = A.potential[i][j];
            		if (derror < (abs (dnew-dold)))
                    {
                        derror = abs (dnew-dold);
                    }
            	}

                else if(A.fixed[i][j]==0 && (i == 0) && (j == A.ncolumns-1))
            	{
            	    dold = A.potential[i][j];
            		A.potential[i][j] = 0.5*(A.potential[i][A.ncolumns-2]+((A.potential[i][A.ncolumns-1]-A.potential[i][A.ncolumns-2]))+A.potential[i+1][A.ncolumns-1]+((A.potential[i][A.ncolumns-1]-A.potential[i+1][A.ncolumns-1])));
            		dnew = A.potential[i][j];
            		if (derror < (abs (dnew-dold)))
                    {
                        derror = abs (dnew-dold);
                    }
            	}

                else if(A.fixed[i][j]==0 && (i == A.nrows-1) && (j == A.ncolumns-1))
            	{
            	    dold = A.potential[i][j];
            		A.potential[i][j] = 0.5*(A.potential[A.nrows-2][j]+((A.potential[A.nrows-1][j]-A.potential[A.nrows-2][j]))+A.potential[i][A.ncolumns-2]+((A.potential[i][A.ncolumns-1]-A.potential[i][A.ncolumns-2])));
            		dnew = A.potential[i][j];
            		if (derror < (abs (dnew-dold)))
                    {
                        derror = abs (dnew-dold);
                    }
            	}


            }
        }
        ++kkk;
    }
    while ((derror > pow(10,-tolerance) && kkk < maxiterations));

    }


