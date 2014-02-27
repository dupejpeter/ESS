#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <ctype.h>
#include <vector>
#include <unistd.h>
#include <cmath>
#include <iomanip>

using namespace std;

class Grid

{
public:
    int nrows;
    int ncolumns;
    float **potential;
    bool **fixed;

        Grid(int x=31, int y=31)
    {
        nrows = x;
        ncolumns = y;

       potential = new float*[nrows];
       for (int i = 0; i < nrows; ++i)
       potential[i] = new float[ncolumns];

       fixed = new bool*[nrows];
       for (int i = 0; i < nrows; ++i)
       fixed[i] = new bool[ncolumns];

       for(int a=0; a<nrows; a++)
        {
         for(int b=0; b<ncolumns; b++)
          {
            potential[a][b] = 0;
            fixed[a][b] = 0;
          }
        }
    }


// setting Brody output matrices to grid for custom scenarios.

        void ObjectInclusion(float **A, bool **B)
    {
        for(int i=0; i<nrows; i++)
        {
            for(int j=0; j<ncolumns; j++)
            {
               potential[i][j]=A[i][j];
               fixed[i][j]=B[i][j];

            }
        }
    }

    float GetPotential(Grid& A, int i, int j)
    {
        return A.potential[i][j];
    }

    int GetRowSize()
    {
        return nrows;
    }

    int GetColSize()
    {
        return ncolumns;
    }

    void SetPlatePotentials(float np, char plate)
    {
        if (plate == 'l')
        {
             for(int i=0; i<nrows; i++)
                {
                potential[i][0] = np;
                fixed[i][0] = 1;
                }
        }

        else if (plate == 'r')
        {

            for(int i=0; i<nrows; i++)
                {
                potential[i][ncolumns-1] = np;
                fixed[i][ncolumns-1] = 1;
                }
        }

        else if (plate == 't')
        {

            for(int j=0; j<ncolumns; j++)
                {
                potential[0][j] = np;
                fixed[0][j] = 1;
                }
        }

        else if (plate == 'b')
        {

            for(int j=0; j<ncolumns; j++)
                {
                potential[nrows-1][j] = np;
                fixed[nrows-1][j] = 1;
                }
        }
    }

    void Circle(Grid& A, float radius, int icentre, int jcentre, float pot)
    {
            for(int i=0; i<A.nrows; i++)
    {
        for(int j=0; j<A.ncolumns; j++)
        {
            if(A.fixed[i][j]==0 &&((pow((i-icentre),2)+pow((j-jcentre),2))<=(pow (radius,2))))
            {
                A.potential[i][j]= pot;
                A.fixed[i][j]=1;
            }
        }
    }
    }

    void Rectangle(Grid& A, int i1, int i2, int j1, int j2, float pot)
    {
        for(int i=i1; i<i2+1; i++)
        {

            for(int j=j1; j<j2+1; j++)
            {
                if (A.fixed[i][j]==0)
                {
                  A.potential[i][j]= pot;
                  A.fixed[i][j]=1;
                }
            }
        }
    }




};

