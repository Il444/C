#include <iostream>
using namespace std;

int main()
{
    double x1, x2, x3, x4, a;

    cin >> x1;
    cin >> x2;
    cin >> x3;
    cin >> x4;

    if (x1 > x2) {
        a = x2;
        x2 = x1;
        x1 = a;
    }

    if (x3 > x2) {
        a = x2;
        x2 = x3;
        x3 = a;
    }
    if (x4 > x2) {
        a = x2;
        x2 = x4;
        x4 = a;
    }
    if (x4 > x3) {
        a = x3;
        x3 = x4;
        x4 = a;
    }

    cout << "X1 = " << x1 << endl;
    cout << "X2 = " << x2 << endl;
    cout << "X3 = " << x3 << endl;
    cout << "X4 = " << x4 << endl;
}

