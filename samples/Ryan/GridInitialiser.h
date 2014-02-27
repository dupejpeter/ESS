#ifndef GridInitialiser_H
#define GridInitialiser_H

using namespace std;

class Grid

{
public:
    int nrows;
    int ncolumns;
    float **potential;
    bool **fixed;

        Grid(int x=31, int y=31);
        void ObjectInclusion(float **A, bool **B);
        float GetPotential(Grid& A, int i, int j);
        int GetRowSize();
        int GetColSize();
        void SetPlatePotentials(float np, char plate);
        void Circle(Grid& A, float radius, int icentre, int jcentre, float pot);
        void Rectangle(Grid& A, int i1, int i2, int j1, int j2, float pot);

};

    #endif

