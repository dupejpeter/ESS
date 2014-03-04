#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <ctype.h>
#include <vector>
#include <unistd.h>
#include <cmath>
#include <iomanip>
#include <istream>
#include <ostream>
#include "Iteration1.h"
#include "GridInitialiser.h"
#include "Iteration2.h"

using namespace std;

void OutputMatrix(Grid& A)
{
        cout << "OUTPUT MATRIX" << endl;
        ofstream FDM_data("FDM_Data.dat");

    for(int i=0; i<A.nrows; i++)
    {
        for(int j=0; j<A.ncolumns; j++)
        {
            if (FDM_data != NULL)
            {
            FDM_data << fixed;
            FDM_data << setprecision(4);
            FDM_data << A.potential[i][j] << "\t";
            cout << fixed;
            cout << setprecision(3);
            cout << A.potential[i][j] << "\t";
            }
        }
        FDM_data << endl;
        cout << endl;
    }

}

int main()
{
    Grid cPotential(36,36);
    cPotential.SetPlatePotentials(100,'b');
    cPotential.Rectangle(0,4,3,9,0);
    cPotential.Rectangle(0,4,15,21,0);
    cPotential.Rectangle(0,4,27,33,0);
    Iteration2(cPotential, 3, 100000);
    OutputMatrix(cPotential);


return 0;
}


