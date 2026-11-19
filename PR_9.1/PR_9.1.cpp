#include <iostream>  
#include <cmath>    
#include <iomanip>   

#include "dod.h"     // Функція обчислення доданка ряду
#include "sum.h"     // Функція обчислення суми ряду
#include "var.h"     // Глобальні змінні

using namespace std;
using namespace nsDod;
using namespace nsSum;
using namespace nsVar;

int main() {
    cout << "x_p = "; cin >> x_p;
    cout << "x_k = "; cin >> x_k;
    cout << "dx = "; cin >> dx;
    cout << "e = "; cin >> e;
    cout << endl;

    // Перевірка правильності введених значень
    if (!cin || x_p <= 1 || x_k < x_p || dx <= 0 || e <= 0) {
        cout << "Invalid input!" << endl;
        return 1; 
    }


    cout << "Arcth(x)" << endl;
    cout << setw(12) << "x"
        << setw(18) << "Series sum"
        << setw(18) << "Arcth(x)"
        << setw(12) << "n" << endl;

    cout << fixed << setprecision(8); 

    x = x_p; 

    // Цикл обчислення для кожного значення x
    while (x <= x_k) {
        sum(); // Обчислення суми ряду Тейлора

       
        cout << setw(12) << x
            << setw(18) << s
            << setw(18) << 0.5 * log((x + 1) / (x - 1))
            << setw(12) << n + 1 << endl;

        x += dx; 
    }

    return 0; 
}