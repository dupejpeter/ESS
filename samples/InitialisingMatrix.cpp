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

// Global Variables.
int kkk=0;
double derror=0;

class Grid
{
public:
    int c_MatrixSize;
    int tolerance;
    float **potential;
    bool **fixed;

    void SetMatrixSize()
    {
       cout << "Enter Matrix Size:" << endl;
       cin >> c_MatrixSize;

       potential = new float*[c_MatrixSize];
       for (int i = 0; i < c_MatrixSize; ++i)
       potential[i] = new float[c_MatrixSize];

       fixed = new bool*[c_MatrixSize];
       for (int i = 0; i < c_MatrixSize; ++i)
       fixed[i] = new bool[c_MatrixSize];

       for(int a=0; a<c_MatrixSize; a++)
        {
         for(int b=0; b<c_MatrixSize; b++)
          {
            potential[a][b] = 0;
            fixed[a][b] = 0;
          }
        }
    }

    void SetTolerance()
    {
           int d;
           cout << "How many digits would you like your accuracy to?" << endl;
           cin >> d;
           tolerance = d;
    }

        void SetPlatePotentials(int PlateNumber)
    {
        if (PlateNumber == 0)
        {
            float nl;
            cout << "Enter potential of the left plate" << endl;
            cin >> nl;
             for(int i=0; i<c_MatrixSize; i++)
                {
                potential[i][0] = nl;
                fixed[i][0] = 1;
                }
        }

                else if (PlateNumber == 1)
        {
            float nr;
            cout << "Enter potential of the right plate" << endl;
            cin >> nr;

            for(int i=0; i<c_MatrixSize; i++)
                {
                potential[i][c_MatrixSize-1] = nr;
                fixed[i][c_MatrixSize-1] = 1;
                }
        }

            else if (PlateNumber == 2)
        {
            float nt;
            cout << "Enter potential of the top plate" << endl;
            cin >> nt;

            for(int j=0; j<c_MatrixSize; j++)
                {
                potential[0][j] = nt;
                fixed[0][j] = 1;
                }
        }

            else if (PlateNumber == 3)
        {
            float nb;
            cout << "Enter potential of the bottom plate" << endl;
            cin >> nb;

            for(int j=0; j<c_MatrixSize; j++)
                {
                potential[c_MatrixSize-1][j] = nb;
                fixed[c_MatrixSize-1][j] = 1;
                }
        }
    }

    void SetPlateBoundaries()
    {
        char response;
        tryagain:
        cout << "Would you like a left plate boundary? (y/n)" <<endl;
        cin >> response;

         switch (response)
            {
                case 'y':
                SetPlatePotentials(0);
                    break;
                case 'n':
                    break;
                default:
                    cout << "Incorrect response, please retry." << endl;
                    goto tryagain;
                    break;
            }

        tryagain2:
        cout << "Would you like a right plate boundary? (y/n)" <<endl;
        cin >> response;

                 switch (response)
            {
                case 'y':
                    SetPlatePotentials(1);
                    break;
                case 'n':
                    break;
                default:
                    cout << "Incorrect response, please retry." << endl;
                    goto tryagain2;
                    break;
            }

        tryagain3:
        cout << "Would you like a top plate boundary? (y/n)" <<endl;
        cin >> response;

                 switch (response)
            {
                case 'y':
                    SetPlatePotentials(2);
                    break;
                case 'n':
                    break;
                default:
                    cout << "Incorrect response, please retry." << endl;
                    goto tryagain3;
                    break;
            }

        tryagain4:
        cout << "Would you like a bottom plate boundary? (y/n)" <<endl;
        cin >> response;

                 switch (response)
            {
                case 'y':
                    SetPlatePotentials(3);
                    break;
                case 'n':
                    break;
                default:
                    cout << "Incorrect response, please retry." << endl;
                    goto tryagain4;
                    break;
            }
    }

/*
    float NeumannBoundaries(int A, int B)
    {
        if (A==0)
        {
        potential[A][B] = potential[]
        }
    }
    */


    void Iteration()
    {

        do
    {
        double dold;
        double dnew;

        for(int i=0; i<c_MatrixSize; i++)
        {
            for(int j=0; j<c_MatrixSize; j++)
            {
                if(fixed[i][j]==0 && (i != 0) && (i != c_MatrixSize-1) && (j != 0) && (j != c_MatrixSize-1))

                {
                    dold = potential[i][j];
                	potential[i][j] = 0.25*(potential[i][j-1] + potential[i][j+1] + potential[i-1][j] + potential[i+1][j]);
                	dnew = potential[i][j];
            		if (derror < (abs (dnew-dold)))
                    {
                        derror = abs (dnew-dold);
                    }
                }

            	else if(fixed[i][j]==0 && (i == 0) && (j != 0) && (j != c_MatrixSize-1))
            	{
            	    dold = potential[0][j];
            		potential[0][j] = 0.25*(2*potential[1][j]+2*((potential[1][j]-potential[0][j]))+potential[0][j+1]+potential[0][j-1]);
            		dnew = potential[0][j];
            		if (derror < (abs (dnew-dold)))
                    {
                        derror = abs (dnew-dold);
                    }
            	}

                else if(fixed[i][j]==0 && (i == 0) && (j == 0))
            	{
            	    dold = potential[i][j];
            		potential[i][j] = 0.5*(potential[1][j]+((potential[1][j]-potential[0][j]))+potential[0][j+1]+((potential[i][1]-potential[i][0])));
            		dnew = potential[i][j];
            		if (derror < (abs (dnew-dold)))
                    {
                        derror = abs (dnew-dold);
                    }
            	}

            	else if(fixed[i][j]==0 && (i==c_MatrixSize-1) && (j!=c_MatrixSize-1) && (j!=0))
            	{
            	    dold = potential[c_MatrixSize-1][j];
         		    potential[c_MatrixSize-1][j] = 0.25*(2*potential[c_MatrixSize-1][j]+2*((potential[c_MatrixSize-2][j]-potential[c_MatrixSize-1][j]))+potential[c_MatrixSize-1][j+1]+potential[c_MatrixSize-1][j-1]);
         		    dnew = potential[c_MatrixSize-1][j];
            		if (derror < abs (dnew-dold))
                    {
                        derror = abs (dnew-dold);
                    }
            	}

                else if(fixed[i][j]==0 && (i == c_MatrixSize-1) && (j == 0))
            	{
            	    dold = potential[i][j];
            		potential[i][j] = 0.5*(potential[c_MatrixSize-2][j]+((potential[c_MatrixSize-2][j]-potential[c_MatrixSize-1][j]))+potential[c_MatrixSize-1][j+1]+((potential[c_MatrixSize-1][j+1]-potential[c_MatrixSize-1][j])));
            		dnew = potential[i][j];
            		if (derror < (abs (dnew-dold)))
                    {
                        derror = abs (dnew-dold);
                    }
            	}

                else if(fixed[i][j]==0 && (i == 0) && (j == c_MatrixSize-1))
            	{
            	    dold = potential[i][j];
            		potential[i][j] = 0.5*(potential[i][c_MatrixSize-2]+((potential[i][c_MatrixSize-2]-potential[i][c_MatrixSize-1]))+potential[i+1][c_MatrixSize-1]+((potential[i+1][c_MatrixSize-1]-potential[i][c_MatrixSize-1])));
            		dnew = potential[i][j];
            		if (derror < (abs (dnew-dold)))
                    {
                        derror = abs (dnew-dold);
                    }
            	}

                else if(fixed[i][j]==0 && (i == c_MatrixSize-1) && (j == c_MatrixSize-1))
            	{
            	    dold = potential[i][j];
            		potential[i][j] = 0.5*(potential[c_MatrixSize-2][j]+((potential[c_MatrixSize-2][j]-potential[c_MatrixSize-1][j]))+potential[i][c_MatrixSize-2]+((potential[i][c_MatrixSize-2]-potential[i][c_MatrixSize-1])));
            		dnew = potential[i][j];
            		if (derror < (abs (dnew-dold)))
                    {
                        derror = abs (dnew-dold);
                    }
            	}

            	else if(fixed[i][j]==0 && (j==0) && (i!=0) && (i!=c_MatrixSize-1))
            	{
                    dold = potential[i][0];
            		potential[i][0] = 0.25*(2*potential[i][1]+2*((potential[i][1]-potential[i][0]))+potential[i+1][0]+potential[i-1][0]);
            		dnew = potential[i][0];
            		if (derror < (abs (dnew-dold)))
                    {
                        derror = abs (dnew-dold);
                    }
                }

                else if(fixed[i][j]==0 && (j==c_MatrixSize-1) && (i!=0) && (i!=c_MatrixSize-1))
            	{
            	    dold = potential[i][c_MatrixSize-1];
         		    potential[i][c_MatrixSize-1] = 0.25*(2*potential[i][c_MatrixSize-1]+2*((potential[i][c_MatrixSize-2]-potential[i][c_MatrixSize-1]))+potential[i+1][c_MatrixSize-1]+potential[i-1][c_MatrixSize-1]);
         		    dnew = potential[i][c_MatrixSize-1];
            		if (derror < abs (dnew-dold))
                    {
                        derror = abs (dnew-dold);
                    }
            	}

            }
        }
        ++kkk;
    }
    while ((derror > pow(10,-tolerance) && kkk < 1000000));

    }



void OutputMatrix()
{
        cout << "OUTPUT MATRIX" << endl;
        ofstream FDM_data("FDM_Data.dat");

    for(int i=0; i<c_MatrixSize; i++)
    {
        for(int j=0; j<c_MatrixSize; j++)
        {
            if (FDM_data != NULL)
            {
            //FDM_data << fixed;
            //FDM_data << setprecision(4);
            FDM_data << potential[i][j] << "\t";
            //cout << fixed;
            //cout << setprecision(3);
            cout << potential[i][j] << "\t";
            }
        }
        FDM_data << endl;
        cout << endl;
    }
}


};

int main()
{
Grid cPotential;
cPotential.SetMatrixSize();
cPotential.SetTolerance();
cPotential.SetPlateBoundaries();
cPotential.Iteration();
cPotential.OutputMatrix();
return 0;
}
