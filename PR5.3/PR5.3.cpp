#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

double f(const double x);
double calculateZ(const double t);

int main()
{
    double tp, tk;
    int n;

    cout << "tp = ";
    cin >> tp;

    cout << "tk = ";
    cin >> tk;

    cout << "n = ";
    cin >> n;

    
    if (!cin || n <= 0 || tp >= tk)
    {
        cout << "Invalid input: tp < tk and n > 0 are required.\n";
        return 1;
    }

    const double dt = (tk - tp) / n;

    cout << "\nLab 5.3, variant 11\n";
    cout << "------------------------------------\n";
    cout << "|" << setw(12) << "t"
        << " |" << setw(18) << "Z(t)" << " |\n";
    cout << "------------------------------------\n";

    cout << fixed << setprecision(6);

    for (int i = 0; i <= n; ++i)
    {
        const double t = tp + i * dt;
        const double z = calculateZ(t);

        cout << "|" << setw(12) << t << " |";

        if (isfinite(z))
            cout << setw(18) << z;
        else
            cout << setw(18) << "undefined";

        cout << " |\n";
    }

    cout << "------------------------------------\n";

    return 0;
}

double f(const double x)
{
    if (abs(x) >= 1.0)
    {
        const double c = cos(x);
        const double denominator = sin(x) + c * c;

        if (abs(denominator) < 1e-12)
            return numeric_limits<double>::quiet_NaN();

        return (sin(2.0 * x) + 1.0) / denominator;
    }

    const double x2 = x * x;
    const double x4 = x2 * x2;

    double a = x2;
    double sum = a;

    for (int k = 1; k <= 7; ++k)
    {
        a *= x4 / ((2.0 * k) * (2.0 * k + 1));
        sum += a;
    }

    return sum;
}

double calculateZ(const double t)
{
    const double a = f(2.0 * t);
    const double b = f(t * t + 1.0);

    return a + b * b;
}