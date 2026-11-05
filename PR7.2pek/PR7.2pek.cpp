
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

void CreateRow(int** a, const int rowNo, const int colCount,
    const int Low, const int High, int colNo);
void CreateRows(int** a, const int rowCount, const int colCount,
    const int Low, const int High, int rowNo);
void PrintRow(int** a, const int rowNo, const int colCount, int colNo);
void PrintRows(int** a, const int rowCount, const int colCount, int rowNo);
int MinCol(int** a, const int rowCount, const int colNo, int rowNo);
int SumMinEvenCols(int** a, const int rowCount, const int colCount, int colNo);

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

    CreateRows(a, rowCount, colCount, Low, High, 0);
    PrintRows(a, rowCount, colCount, 0);

    int S = SumMinEvenCols(a, rowCount, colCount, 1);
    cout << "S = " << S << endl;

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void CreateRow(int** a, const int rowNo, const int colCount,
    const int Low, const int High, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);

    if (colNo < colCount - 1)
        CreateRow(a, rowNo, colCount, Low, High, colNo + 1);
}

void CreateRows(int** a, const int rowCount, const int colCount,
    const int Low, const int High, int rowNo)
{
    CreateRow(a, rowNo, colCount, Low, High, 0);

    if (rowNo < rowCount - 1)
        CreateRows(a, rowCount, colCount, Low, High, rowNo + 1);
}

void PrintRow(int** a, const int rowNo, const int colCount, int colNo)
{
    cout << setw(4) << a[rowNo][colNo];

    if (colNo < colCount - 1)
        PrintRow(a, rowNo, colCount, colNo + 1);
    else
        cout << endl;
}

void PrintRows(int** a, const int rowCount, const int colCount, int rowNo)
{
    PrintRow(a, rowNo, colCount, 0);

    if (rowNo < rowCount - 1)
        PrintRows(a, rowCount, colCount, rowNo + 1);
    else
        cout << endl;
}

int MinCol(int** a, const int rowCount, const int colNo, int rowNo)
{
    int min = a[rowNo][colNo];

    if (rowNo < rowCount - 1)
    {
        int minRest = MinCol(a, rowCount, colNo, rowNo + 1);

        if (minRest < min)
            min = minRest;
    }

    return min;
}

int SumMinEvenCols(int** a, const int rowCount, const int colCount, int colNo)
{
    int S = MinCol(a, rowCount, colNo, 0);

    if (colNo + 2 < colCount)
        S += SumMinEvenCols(a, rowCount, colCount, colNo + 2);

    return S;
}