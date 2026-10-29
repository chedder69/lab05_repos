#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
void Print(T* a, const int size, int i)
{
    cout << setw(6) << a[i];

    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

void Sort(int* a, const int size, int i, int j)
{
    if (a[j] > a[j + 1])
    {
        int tmp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = tmp;
    }

    if (j < size - i - 1)
        Sort(a, size, i, j + 1);
    else if (i < size - 1)
        Sort(a, size, i + 1, 0);
}

template <typename T>
void Sort(T* a, const int size, int i, int j)
{
    if (a[j] > a[j + 1])
    {
        T tmp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = tmp;
    }

    if (j < size - i - 1)
        Sort<T>(a, size, i, j + 1);
    else if (i < size - 1)
        Sort<T>(a, size, i + 1, 0);
}

int main()
{
    const int n = 5;

    int a[n] = { 9, 3, 7, 5, 8 };
    int b[n] = { 9, 3, 7, 5, 8 };
    double c[n] = { 9.2, 3.1, 7.3, 5.4, 8.5 };

    Print(a, n, 0);
    Sort(a, n, 1, 0);
    Print(a, n, 0);

    Print(b, n, 0);
    Sort<int>(b, n, 1, 0);
    Print(b, n, 0);

    Print(c, n, 0);
    Sort<double>(c, n, 1, 0);
    Print(c, n, 0);

    return 0;
}