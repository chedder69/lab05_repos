#include <iostream>
#include <iomanip>
#include <cmath>


using namespace std;


double A(const double x, const int n, const double a);
double S(const double x, const double eps, int& n);

int main()
{

    double xp, xk, dx, eps;

    cout << "xp = ";
    cin >> xp;

    cout << "xk = ";
    cin >> xk;

    cout << "dx = ";
    cin >> dx;

    cout << "eps = ";
    cin >> eps;
    
   
    if (!cin || xp > xk || dx <= 0 || eps <= 0 ||
        !((xp > 1 && xk > 1) || (xp < -1 && xk < -1)))
    {
        cout << "Invalid input. Required: |x| > 1, "
            << "xp <= xk, dx > 0, eps > 0." << endl;
        return 1;
    }

    cout << "\nArcth(x) = 1/x + 1/(3*x^3) + "
        << "1/(5*x^5) + ...\n";

    cout << "--------------------------------------------------------\n";

    cout << "|" << setw(9) << "x"
        << " |" << setw(14) << "Arcth(x)"
        << " |" << setw(14) << "S(x)"
        << " |" << setw(7) << "n" << " |\n";

    cout << "--------------------------------------------------------\n";

    for (int i = 0; ; ++i)
    {
        double x = xp + i * dx;

        if (x > xk + 1e-10)
            break;

        int n = 0;

        double s = S(x, eps, n);

        double exact = 0.5 * log((x + 1) / (x - 1));

        cout << fixed << setprecision(5)
            << "|" << setw(9) << x
            << " |" << setw(14) << exact
            << " |" << setw(14) << s
            << " |" << setw(7) << n
            << " |\n";
    }

    cout << "--------------------------------------------------------\n";

    return 0;
}


double S(const double x, const double eps, int& n)
{
    double a = 1.0 / x;
    double s = a;

    n = 1;

    while (abs(a) >= eps)
    {
        a = A(x, n, a);
        s += a;
        ++n;
    }

    return s;
}

double A(const double x, const int n, const double a)
{
    double R = (2.0 * n - 1) /
        ((2.0 * n + 1) * x * x);

    return a * R;
}