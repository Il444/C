#include <iostream>
#include <iomanip>
#include "integral.h"
using namespace std;

int main()
{
    double a = 1.3;
    double b = 2.621;
    double eps = 0.000001;
    int k_iter = 0;
    double result = 0;

    cout << fixed << setprecision(6);
    cout << "|   s   |   t   |   Int   |  k_iter  |\n";
    cout << "-------------------------------------\n";

    for (double s = 0; s <= 0.5; s += 0.1) {
        for (double t = 1; t <= 3; t += 0.5) {
            k_iter = 0;
            result = doubleReculculation(f, a, b, s, t, eps, k_iter);

            cout << "| " << setw(5) << s << " | " << setw(5) << t << " | "
                << setw(8) << result << " | " << setw(4) << k_iter << "  |\n";
        }
    }

    return 0;
}