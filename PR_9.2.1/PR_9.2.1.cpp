#include <iostream>
#include "macros.h"

using namespace std;

int main() {
    double x, y, w;

    cout << "x = "; cin >> x;
    cout << "y = "; cin >> y;
    cout << "z = " << Z << endl;

#if Z > 0 && Z < 5

    w = MIN(SQR(x) + y + Z, x * y * Z);

#else

    w = MAX(SQR(x) + SQR(y + Z), x * y);

#endif

    PRINT(w);

    return 0;
}