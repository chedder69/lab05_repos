
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void Sort(int** a, const int rowCount, const int colCount);
void Change(int** a, const int col1, const int col2, const int rowCount);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k);

int main()
{
    srand((unsigned)time(NULL));

    int Low = 7;
    int High = 62;

    int rowCount = 7;
    int colCount = 6;

    int** Q = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        Q[i] = new int[colCount];

    Create(Q, rowCount, colCount, Low, High);
    Print(Q, rowCount, colCount);
    Sort(Q, rowCount, colCount);
    Print(Q, rowCount, colCount);

    int S = 0;
    int k = 0;
    Calc(Q, rowCount, colCount, S, k);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    Print(Q, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] Q[i];
    delete[] Q;

    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void Sort(int** a, const int rowCount, const int colCount)
{
    for (int i0 = 0; i0 < colCount - 1; i0++)
        for (int i1 = 0; i1 < colCount - i0 - 1; i1++)
            if ((a[0][i1] < a[0][i1 + 1])
                ||
                (a[0][i1] == a[0][i1 + 1] &&
                    a[1][i1] > a[1][i1 + 1])
                ||
                (a[0][i1] == a[0][i1 + 1] &&
                    a[1][i1] == a[1][i1 + 1] &&
                    a[2][i1] > a[2][i1 + 1]))
                Change(a, i1, i1 + 1, rowCount);
}

void Change(int** a, const int col1, const int col2, const int rowCount)
{
    int tmp;
    for (int i = 0; i < rowCount; i++)
    {
        tmp = a[i][col1];
        a[i][col1] = a[i][col2];
        a[i][col2] = tmp;
    }
}

void Calc(int** a, const int rowCount, const int colCount, int& S, int& k)
{
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            if (a[i][j] % 2 == 0 && (i + j) % 8 != 0)
            {
                S += a[i][j];
                k++;
                a[i][j] = 0;
            }
}