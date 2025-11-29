#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    int coeficient;
    double x_m = 3.0;
    double dx = 0.2;
    double x_0 = 1.0;
    double x_i = x_0;
    double xPower;
    double result;
    int count_sum = 0;
    int count_mult = 0;

    cout << "Enter the number: ";
    cin >> n;

    for (x_i = x_0; x_i <= x_m; x_i += dx) {
        result = 6 - x_i * x_i;
        xPower = x_i * x_i;

        count_sum += 1;
        count_mult += 2;

        for (int i = 2; i <= n; i++) {
            xPower *= x_i * x_i;
            if (i % 2 == 0) {
                coeficient = i;
            }
            else {
                coeficient = -i;
            }
            result += coeficient * xPower;
            count_sum += 1;
            count_mult += 1;
        }
        cout << "When x = " << x_i << ": " << result << ". The amuont of sum is " << count_sum << ", and the multiplication is " << count_mult << endl;
    }

    // HORNER'S WAY:

    cout << "" << endl;
    cout << "HORNER'S WAY:" << endl;

    for (x_i = x_0; x_i <= x_m; x_i += dx) {
        int count_sum1 = 0;
        int count_mult1 = 0;
        double t = x_i * x_i;
        double firstCoef;

        count_mult1++;

        if (n % 2 == 0) {
            firstCoef = n;
        }
        else {
            firstCoef = -n;
        }

        result = firstCoef;

        for (int j = n - 1; j >= 1; j--) {
            double coef;
            if (j % 2 == 0) {
                coef = j;
            }
            else {
                coef = -j;
            }
            result = result * t + coef;
            count_mult1++;
            count_sum1++;
        }

        result = result * t + 6;
        count_mult1++;
        count_sum1++;
        cout << "When x = " << x_i << ": " << result << ". The amuont of sum is " << count_sum1 << ", and the multiplication is " << count_mult1 << endl;
    }
}