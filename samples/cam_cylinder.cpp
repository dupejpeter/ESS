#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>
#include <unistd.h>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

class Cylinder
{
    public:
        int c_MatrixSize;
        float c_Radius;
        float x_centre;
        float y_centre;
        float cylinder_potential;
        float **potential;
        bool **fixed;
        
    void SetMatrixSize()
    {
       int M;
       cout << "Enter Matrix Size:" << endl;
       cin >> M;
       c_MatrixSize = M;

       potential = new float*[c_MatrixSize];
       for (int i = 0; i < c_MatrixSize; ++i)
       potential[i] = new float[c_MatrixSize];

       fixed = new bool*[c_MatrixSize];
       for (int i = 0; i < c_MatrixSize; ++i)
       fixed[i] = new bool[c_MatrixSize];
    }
    
    void set_cylinder_potential()
    {
        cout << "Please enter the CYLINDER's potential - enter ZERO for it to be grounded" << endl;
        cin >> cylinder_potential;
    }
        
    
    void setCylinder()
    {
        int M = c_MatrixSize;
        cout << "enter cylinder radius" << endl;
        cin >> c_Radius;
        cout << "Enter x component of the cylinder centre" << endl;
        cin >> x_centre;
        cout << "Enter y component of the cylinder centre" << endl;
        cin >> y_centre;
        
        for(int i=0; i<M; i++)
        {
            for(int j=1; j<M-1; j++)
            {
                if((pow((i-x_centre),2)+pow((j-y_centre),2))<=(pow(c_Radius,2)))
                potential[i][j] = cylinder_potential;
                fixed[i][j] = 1;
            }
        }
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
    Cylinder cylinder;
    cylinder.SetMatrixSize();
    cylinder.set_cylinder_potential();
    cylinder.setCylinder();
    cylinder.OutputMatrix();
    system("gnuplot -p -e \"splot 'FDM_Data.dat' matrix with lines\"");
return 0;
}