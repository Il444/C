#include <iostream>
#include <cmath>
using namespace std;

double funcA(double x) {
    return (x - 1) * (x - 1) * (x - 1) - 1;
}

double funcB(double x, double s) {
    return s * x - cos(3.14159 * x) * cos(3.14159 * x);
}

double halfDivision(double a, double b, double s, double e, int& iter) {
    double c;
    iter = 0;

    while ((b - a) / 2 > e) {
        c = (a + b) / 2;
        iter++;

        if (funcB(a, s) * funcB(c, s) <= 0) {
            b = c;
        }
        else {
            a = c;
        }
    }

    return (a + b) / 2;
}

double tangent(double a, double b, double s, double e, int& iter) {
    double x = (a + b) / 2;
    double x2;
    double h = 0.0001;
    double der;
    iter = 0;

    for (int i = 0; i < 100; i++) {
        der = (funcB(x + h, s) - funcB(x - h, s)) / (2 * h);

        if (fabs(der) < 1e-10) break;

        x2 = x - funcB(x, s) / der;
        iter++;

        if (fabs(x2 - x) < e) {
            x = x2;
            break;
        }

        x = x2;
    }

    return x;
}

double chord(double a, double b, double s, double e, int& iter) {
    double x0 = a;
    double x1 = b;
    double x2;
    iter = 0;

    for (int i = 0; i < 100; i++) {
        x2 = x1 - funcB(x1, s) * (x1 - x0) / (funcB(x1, s) - funcB(x0, s));
        iter++;

        x0 = x1;
        x1 = x2;

        if (fabs(funcB(x1, s)) < e) break;
    }

    return x1;
}

int main() {
    double e = 0.000001;
    int m;

    double a1 = 0;
    double b1 = 3;

    cout << "Function a) f(x) = (x-1)^3 - 1 on [0, 3]" << endl;
    cout << "----------------------------------------" << endl;

    int iter1;
    double x1 = halfDivision(a1, b1, 1, e, iter1);
    double fx1 = funcA(x1);

    cout << "Root: " << x1 << endl;
    cout << "f(x): " << fx1 << endl;
    cout << "Iterations: " << iter1 << endl;

    cout << endl;

    double a2 = -1;
    double b2 = 0.7;
    double s1 = 1;
    double s2 = 3;
    double ds = 1;

    cout << "Function b) f(x) = s*x - cos^2(pi*x) on [-1, 0.7]" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Choose method (1-half, 2-tangent, 3-chord): ";
    cin >> m;

    cout << endl;
    cout << "|  s  |    x    |   f(x)   | iter |" << endl;
    cout << "----------------------------------------" << endl;

    for (double s = s1; s <= s2; s += ds) {
        int iter2;
        double x2;

        if (m == 1) {
            x2 = halfDivision(a2, b2, s, e, iter2);
        }
        else if (m == 2) {
            x2 = tangent(a2, b2, s, e, iter2);
        }
        else {
            x2 = chord(a2, b2, s, e, iter2);
        }

        double fx2 = funcB(x2, s);

        cout << "|  " << s << "  |  " << x2 << "  |  " << fx2 << "  |  " << iter2 << "  |" << endl;
    }

    cout << "----------------------------------------" << endl;

    return 0;
}