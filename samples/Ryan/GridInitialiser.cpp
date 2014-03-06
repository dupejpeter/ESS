#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <ctype.h>
#include <vector>
#include <unistd.h>
#include <cmath>
#include <iomanip>
#include "GridInitialiser.h"

using namespace std;

    Grid::Grid()
    {
        nrows = 31;
        ncolumns = 31;

       potential = new float*[nrows];
       for (int i = 0; i < nrows; ++i)
       potential[i] = new float[ncolumns];

       fixed = new bool*[nrows];
       for (int i = 0; i < nrows; ++i)
       fixed[i] = new bool[ncolumns];

       Ex = new float*[nrows];
       for (int i = 0; i < nrows; ++i)
       Ex[i] = new float[ncolumns];

       Ey = new float*[nrows];
       for (int i = 0; i < nrows; ++i)
       Ey[i] = new float[ncolumns];

       for(int a=0; a<nrows; a++)
        {
         for(int b=0; b<ncolumns; b++)
          {
            potential[a][b] = 0;
            fixed[a][b] = 0;
          }
        }
    }



    Grid::Grid(int x, int y)
    {
        nrows = x;
        ncolumns = y;

       potential = new float*[nrows];
       for (int i = 0; i < nrows; ++i)
       potential[i] = new float[ncolumns];

       fixed = new bool*[nrows];
       for (int i = 0; i < nrows; ++i)
       fixed[i] = new bool[ncolumns];

       Ex = new float*[nrows];
       for (int i = 0; i < nrows; ++i)
       Ex[i] = new float[ncolumns];

       Ey = new float*[nrows];
       for (int i = 0; i < nrows; ++i)
       Ey[i] = new float[ncolumns];

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

        void Grid::ObjectInclusion(float **A, bool **B)
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

    float Grid::GetPotential(Grid& A, int i, int j)
    {
        return A.potential[i][j];
    }

    int Grid::GetRowSize()
    {
        return nrows;
    }

    int Grid::GetColSize()
    {
        return ncolumns;
    }

    void Grid::SetPlatePotentials(float np, char plate)
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

    void Grid::Circle(float radius, int icentre, int jcentre, float pot)
    {
            for(int i=0; i<nrows; i++)
    {
        for(int j=0; j<ncolumns; j++)
        {
            if(fixed[i][j]==0 &&((pow((i-icentre),2)+pow((j-jcentre),2))<=(pow (radius,2))))
            {
                potential[i][j]= pot;
                fixed[i][j]=1;
            }
        }
    }
    }

    void Grid::Rectangle(int i1, int i2, int j1, int j2, float pot)
    {
        for(int i=i1; i<i2+1; i++)
        {

            for(int j=j1; j<j2+1; j++)
            {
                if (fixed[i][j]==0)
                {
                  potential[i][j]= pot;
                  fixed[i][j]=1;
                }
            }
        }
    }

    void Grid::SetElectricField()
    {
        float h = 1.0/(nrows-1);

        for (int i=1; i < nrows-1; i++)
        {
            for (int j=1; j < ncolumns-1; j++)
            {
                Ey[i][j]= -((potential[i+1][j]-potential[i-1][j])/(2*h));
                Ex[i][j]= -((potential[i][j+1]-potential[i][j-1])/(2*h));
            }
        }

        for (int i = 0; i < nrows; i++)
            {
                Ex[i][0] = 2 * Ex[i][1] - Ex[i][2];
                Ex[i][ncolumns-1] = 2 * Ex[i][ncolumns-2] - Ex[i][ncolumns-3];
            }

        for (int j =0; j < ncolumns; j++)
            {
                Ey[0][j] = 2 * Ey[1][j] - Ey[2][j];
                Ey[nrows-1][j] = 2 * Ey[nrows-2][j] - Ey[nrows-3][j];
            }
    }

    void Grid::OutputElectric()
    {
        float h = 1.0/(nrows-1);
        double Emax = 0;
        for (int i = 0; i < nrows; i++)
            for (int j = 0; j < ncolumns; j++)
                {
                    double E = sqrt(Ex[i][j]*Ex[i][j] + Ey[i][j]*Ey[i][j]);
                    if (E > Emax) Emax = E;
                }

        cout << " Electric filed in file electric.dat" << endl;
        ofstream dataFile("electric.dat");
        for (int i = 0; i < nrows; i++)
            {
                double y = i * h;
                for (int j = 0; j < ncolumns; j++)
                {
                    double x = j * h;

                            //dataFile << fixed;
                            dataFile << setprecision(4);
                            dataFile << x << '\t' << y << '\t' << (Ex[i][j] / Emax * h) << '\t' << (Ey[i][j] / Emax * h) << '\n';
                }
            }
        dataFile.close();

    }





