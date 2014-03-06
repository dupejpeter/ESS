#ifndef GridInitialiser_H
#define GridInitialiser_H


using namespace std;

class Grid
{
public:
    int nrows;
    int ncolumns;
    float **potential;
    float **Ex;
    float **Ey;
    bool **fixed;
    Grid();
    Grid(int x, int y);
    void ObjectInclusion(float **A, bool **B);
    float GetPotential(Grid& A, int i, int j);
    int GetRowSize();
    int GetColSize();
    void SetPlatePotentials(float np, char plate);
    void Circle(float radius, int icentre, int jcentre, float pot);
    void Rectangle(int i1, int i2, int j1, int j2, float pot);
    void SetElectricField();
    void OutputElectric();



};

    #endif

