
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount,
    const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
int MinCol(int** a, const int rowCount, const int colNo);
int SumMinEvenCols(int** a, const int rowCount, const int colCount);

int main()
{
    srand((unsigned)time(NULL));

    int Low = 7;
    int High = 62;

    int rowCount = 7;
    int colCount = 6;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Create(a, rowCount, colCount, Low, High);
    Print(a, rowCount, colCount);

    int S = SumMinEvenCols(a, rowCount, colCount);
    cout << "S = " << S << endl;

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int rowCount, const int colCount,
    const int Low, const int High)
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

int MinCol(int** a, const int rowCount, const int colNo)
{
    int min = a[0][colNo];

    for (int i = 1; i < rowCount; i++)
        if (a[i][colNo] < min)
            min = a[i][colNo];

    return min;
}

int SumMinEvenCols(int** a, const int rowCount, const int colCount)
{
    int S = 0;

    for (int j = 1; j < colCount; j += 2)
        S += MinCol(a, rowCount, j);

    return S;
}