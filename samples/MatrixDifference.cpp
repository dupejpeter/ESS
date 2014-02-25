#include <iostream>


using namespace std;


class matrix
{
public:
    int i, j, nRank;
    double adArray[100][100];

    void input();
    matrix operator-(matrix mm2);

    void output();
};

void matrix::input()
{
    cout << "\nEnter rank: ";
    cin >> nRank;
    cout << "\nEnter the elements : ";
    for(i = 0; i < nRank; i++)
    {
        for(j = 0; j < nRank; j++)
        {
            cin >> adArray[i][j];
            cout << "\t";
        }
        cout << "\n";
    }
}
matrix matrix::operator-(matrix mm2)
{
    matrix temp;
    temp.nRank = nRank;

    for(i = 0; i < temp.nRank; i++)
        for(j = 0; j < temp.nRank; j++)
            temp.adArray[i][j] = adArray[i][j] - mm2.adArray[i][j];
return temp;
}

void matrix::output()
{
    cout << "Matrix is : ";
    for(i = 0; i < nRank; i++)
    {
        for(j = 0;j < nRank; j++)
            cout << adArray[i][j]<<"\t";
        cout << "\n";
    }

}

int main(){
matrix m1, m2, m3;
m1.input();
m2.input();
m3=m1-m2;
m3.output();
return 0;
}
