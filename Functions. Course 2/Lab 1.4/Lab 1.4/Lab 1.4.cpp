#include <iostream>
#include <cmath>
using namespace std;

double funcA(double x) {
    return (x - 1) * (x - 1) * (x - 1) - 1;
}

double funcB(double x, double s) {
    double pi = 3.1415;
    return s*x - cos(pi * x) * cos(pi * x);
}

double funcB_s1(double x) {
    return funcB(x, 1);
}

double funcB_s2(double x) {
    return funcB(x, 2);
}

double funcB_s3(double x) {
    return funcB(x, 3);
}

double findRoot(double (*f)(double), int& iter, double a = 0, double b = 3, double eps = 1e-6) {
    iter = 0;
    for (double i = (a+b)/2; (b-a) > eps; i=(a+b)/2) {
        iter++;
        if (f(i) == 0) {
            break;
        }
        else if(f(a) * f(i) < 0) {
            b = i;
        }
        else {
            a = i;
        }
    }
    return (a+b)/2;
}

int main() {
    double a = 0;
    double b = 0;
    double eps = 1e-6;
    int iter1 = 0;
    int iter2 = 0;
    int iter3 = 0;
    int iter4 = 0;
    cout << "Enter range: " << endl;
    cout << "From: ";
    cin >> a;
    cout << "To:";
    cin >> b;
    
    double root1 = findRoot(funcA, iter1, a, b, eps);
    cout << "Root from A: " << root1 << endl;
    cout << "Iterations: " << iter1 << endl;
    double root2 = findRoot(funcB_s1, iter2, -1, 0.7, eps);
    double root3 = findRoot(funcB_s2, iter3, -1, 0.7, eps);
    double root4 = findRoot(funcB_s3, iter4, -1, 0.7, eps);

    cout << "|   s   |   x   |   f(x)   |  iter  |\n";
    cout << "--------------------------------------\n";
    cout << "|   " << 1 << "   | " << root2 << " | " << funcB_s1(root2) << " |  " << iter2 << "  |\n";
    cout << "|   " << 2 << "   | " << root3 << " | " << funcB_s2(root3) << " |  " << iter3 << "  |\n";
    cout << "|   " << 3 << "   | " << root4 << " | " << funcB_s3(root4) << " |  " << iter4 << "  |\n";

    return 0;
}