#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x_n = 2 * 3.1415;
    double dx = 0.1;

    for (double x = 0; x <= x_n; x += dx) {
        double sum = 0.0;
        double factorial = 1.0;
        int term_count = 0;

        for (int n = 0; n < 20; n++) {
            if (n > 0) {
                factorial *= n;
            }

            double term;
            if (n % 2 == 0) {
                int k = n / 2;
                term = pow(-1, k) * pow(x, n) / factorial;
            }
            else {
                int k = (n - 1) / 2;
                term = pow(-1, k) * pow(x, n) / factorial;
            }

            sum += term;
            term_count++;
        }

        double exact = cos(x) + sin(x);

        cout << "x = " << x << " : Taylor = " << sum << " Exact = " << exact << endl;
    }

    return 0;
}