#include <iostream>
#include <iomanip>
#include <time.h>
#include <cstdlib>

using namespace std;

void Create(int* c, const int size, const int Low, const int High, int i)
{
    c[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(c, size, Low, High, i + 1);
}

void Print(int* c, const int size, int i)
{
    cout << setw(4) << c[i];
    if (i < size - 1)
        Print(c, size, i + 1);
    else
        cout << endl;
}

int Count(int* c, const int size, int i)
{
    if (i < size)
    {
        if (c[i] > 0 || c[i] % 2 != 0)
            return 1 + Count(c, size, i + 1);
        else
            return Count(c, size, i + 1);
    }
    else
        return 0;
}

int Sum(int* c, const int size, int i)
{
    if (i < size)
    {
        if (c[i] > 0 || c[i] % 2 != 0)
            return c[i] + Sum(c, size, i + 1);
        else
            return Sum(c, size, i + 1);
    }
    else
        return 0;
}

void ReplaceZero(int* c, const int size, int i)
{
    if (c[i] > 0 || c[i] % 2 != 0)
        c[i] = 0;

    if (i < size - 1)
        ReplaceZero(c, size, i + 1);
}

int main()
{
    srand((unsigned)time(NULL));

    const int n = 27;
    int c[n];

    int Low = -35;
    int High = 25;

    Create(c, n, Low, High, 0);
    Print(c, n, 0);

    cout << "Count = " << Count(c, n, 0) << endl;
    cout << "Sum = " << Sum(c, n, 0) << endl;

    ReplaceZero(c, n, 0);
    Print(c, n, 0);

    return 0;
}