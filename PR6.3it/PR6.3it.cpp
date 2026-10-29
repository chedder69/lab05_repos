#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
void Print(T* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(6) << a[i];
    cout << endl;
}

void Sort(int* a, const int size)
{
    for (int i = 1; i < size; i++)
        for (int j = 0; j < size - i; j++)
            if (a[j] > a[j + 1])
            {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
}

template <typename T>
void Sort(T* a, const int size)
{
    for (int i = 1; i < size; i++)
        for (int j = 0; j < size - i; j++)
            if (a[j] > a[j + 1])
            {
                T tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
}

int main()
{
    const int n = 5;

    int a[n] = { 9, 3, 7, 5, 8 };
    int b[n] = { 9, 3, 7, 5, 8 };
    double c[n] = { 9.2, 3.1, 7.3, 5.4, 8.5 };

    Print(a, n);
    Sort(a, n);
    Print(a, n);

    Print(b, n);
    Sort<int>(b, n);
    Print(b, n);

    Print(c, n);
    Sort<double>(c, n);
    Print(c, n);

    return 0;
}