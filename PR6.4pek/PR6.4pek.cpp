#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <time.h>

using namespace std;

void Create(double* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + (double)rand() / RAND_MAX * (High - Low);

    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

void Print(double* a, const int size, int i)
{
    cout << setw(8) << fixed << setprecision(2) << a[i];

    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

int MinAbsIndex(double* a, const int size, int i, int imin)
{
    if (fabs(a[i]) < fabs(a[imin]))
        imin = i;

    if (i < size - 1)
        return MinAbsIndex(a, size, i + 1, imin);
    else
        return imin;
}

double SumAbsAfterFirstNegative(double* a, const int size, int i, bool found)
{
    if (i >= size)
        return 0;

    if (found)
        return fabs(a[i]) + SumAbsAfterFirstNegative(a, size, i + 1, true);

    if (a[i] < 0)
        return SumAbsAfterFirstNegative(a, size, i + 1, true);

    return SumAbsAfterFirstNegative(a, size, i + 1, false);
}

void Compress(double* a, const int size, double A, double B, int i, int j)
{
    if (i < size)
    {
        if (a[i] < A || a[i] > B)
        {
            a[j] = a[i];
            j++;
        }

        Compress(a, size, A, B, i + 1, j);
    }
    else if (j < size)
    {
        a[j] = 0;
        Compress(a, size, A, B, i, j + 1);
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int n;
    double A, B;

    cout << "n = ";
    cin >> n;

    if (n <= 0)
        return 0;

    cout << "A = ";
    cin >> A;
    cout << "B = ";
    cin >> B;

    if (A > B)
        return 0;

    double* a = new double[n];

    int Low = -10;
    int High = 10;

    Create(a, n, Low, High, 0);
    Print(a, n, 0);

    cout << "MinAbsIndex = " << MinAbsIndex(a, n, 0, 0) << endl;
    cout << "Sum = " << SumAbsAfterFirstNegative(a, n, 0, false) << endl;

    Compress(a, n, A, B, 0, 0);
    Print(a, n, 0);

    delete[] a;

    return 0;
}