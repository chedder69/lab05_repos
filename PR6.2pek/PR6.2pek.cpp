#include <iostream>
#include <iomanip>
#include <time.h>
#include <cstdlib>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);

    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i)
{
    cout << setw(4) << a[i];

    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

int FindMaxOdd(int* a, const int size, int i, int imax)
{
    if (a[i] % 2 != 0)
        if (imax == -1 || a[i] > a[imax])
            imax = i;

    if (i < size - 1)
        return FindMaxOdd(a, size, i + 1, imax);
    else
        return imax;
}

void SwapLastWithMaxOdd(int* a, const int size)
{
    int imax = FindMaxOdd(a, size, 0, -1);

    if (imax != -1)
    {
        int tmp = a[size - 1];
        a[size - 1] = a[imax];
        a[imax] = tmp;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    const int n = 10;
    int a[n];

    int Low = -20;
    int High = 20;

    Create(a, n, Low, High, 0);
    Print(a, n, 0);

    SwapLastWithMaxOdd(a, n);
    Print(a, n, 0);

    return 0;
}