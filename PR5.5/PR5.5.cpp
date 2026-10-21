#include <iostream>
#include <iomanip>

using namespace std;



int main()
{
    int n, depth = 0;

    cout << "n = ";
    cin >> n;

    cout << "\nPascal triangle:\n";

    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n - i - 1; k++)
            cout << "  ";

        for (int j = 0; j <= i; j++)
            cout << setw(4) << C(i, j, 1, depth);

        cout << endl;
    }

    cout << "\nRecursion levels: ";
    for (int i = 1; i <= depth; i++)
        cout << i << " ";

    cout << "\nRecursion depth = " << depth << endl;

    return 0;
}
long long C(const int i, const int j,
    const int level, int& depth)
{
    if (level > depth)
        depth = level;

    if (j == 0 || j == i)
        return 1;
    else
        return C(i - 1, j - 1, level + 1, depth)
        + C(i - 1, j, level + 1, depth);
}


