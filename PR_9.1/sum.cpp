#include <cmath>

#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace nsDod;
using namespace nsVar;

double nsSum::sum() {
    n = 0;
    a = 1.0 / x;
    s = a;

    do {
        n++;
        dod();
        s += a;
    } while (fabs(a) > e);

    return s;
}