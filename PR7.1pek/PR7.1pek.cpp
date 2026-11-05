
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount,
    const int Low, const int High, int i, int j);
void Print(int** a, const int rowCount, const int colCount,
    int i, int j);
void Sort(int** a, const int rowCount, const int colCount,
    int i0, int i1);
void Change(int** a, const int col1, const int col2,
    const int rowCount, int i);
void Calc(int** a, const int rowCount, const int colCount,
    int i, int j, int& S, int& k);

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

    Create(Q, rowCount, colCount, Low, High, 0, 0);
    cout << endl;
    Print(Q, rowCount, colCount, 0, 0);

    Sort(Q, rowCount, colCount, 0, 0);
    cout << endl;
    Print(Q, rowCount, colCount, 0, 0);

    int S = 0;
    int k = 0;
    Calc(Q, rowCount, colCount, 0, 0, S, k);

    cout << "S = " << S << endl;
    cout << "k = " << k << endl << endl;

    Print(Q, rowCount, colCount, 0, 0);

    for (int i = 0; i < rowCount; i++)
        delete[] Q[i];
    delete[] Q;

    return 0;
}

void Create(int** a, const int rowCount, const int colCount,
    const int Low, const int High, int i, int j)
{
    a[i][j] = Low + rand() % (High - Low + 1);

    if (j < colCount - 1)
        Create(a, rowCount, colCount, Low, High, i, j + 1);
    else if (i < rowCount - 1)
        Create(a, rowCount, colCount, Low, High, i + 1, 0);
}

void Print(int** a, const int rowCount, const int colCount,
    int i, int j)
{
    cout << setw(4) << a[i][j];

    if (j < colCount - 1)
        Print(a, rowCount, colCount, i, j + 1);
    else if (i < rowCount - 1)
    {
        cout << endl;
        Print(a, rowCount, colCount, i + 1, 0);
    }
    else
        cout << endl << endl;
}

void Sort(int** a, const int rowCount, const int colCount,
    int i0, int i1)
{
    if ((a[0][i1] < a[0][i1 + 1])
        ||
        (a[0][i1] == a[0][i1 + 1] &&
            a[1][i1] > a[1][i1 + 1])
        ||
        (a[0][i1] == a[0][i1 + 1] &&
            a[1][i1] == a[1][i1 + 1] &&
            a[2][i1] > a[2][i1 + 1]))
        Change(a, i1, i1 + 1, rowCount, 0);

    if (i1 < colCount - i0 - 2)
        Sort(a, rowCount, colCount, i0, i1 + 1);
    else if (i0 < colCount - 2)
        Sort(a, rowCount, colCount, i0 + 1, 0);
}

void Change(int** a, const int col1, const int col2,
    const int rowCount, int i)
{
    int tmp = a[i][col1];
    a[i][col1] = a[i][col2];
    a[i][col2] = tmp;

    if (i < rowCount - 1)
        Change(a, col1, col2, rowCount, i + 1);
}

void Calc(int** a, const int rowCount, const int colCount,
    int i, int j, int& S, int& k)
{
    if (a[i][j] % 2 == 0 && (i + j) % 8 != 0)
    {
        S += a[i][j];
        k++;
        a[i][j] = 0;
    }

    if (j < colCount - 1)
        Calc(a, rowCount, colCount, i, j + 1, S, k);
    else if (i < rowCount - 1)
        Calc(a, rowCount, colCount, i + 1, 0, S, k);
}