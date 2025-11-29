#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    int num4 = 0;
    int raschet1 = 0;
    int raschet2 = 0;
    const int N = 10000;
    bool a[N] = { 0 };

    for (int i = 2; i < N; i++) {
        a[i] = true;
    }

    unsigned int n = sqrt(double(N));

    for (int i = 2; i <= n; i++) {
        if (a[i]) {
            for (int j = i * 2; j < N; j += i) {
                a[j] = false;
            }
        }
    }
    for (int i = 1000; i < N; i++) {
        if (a[i]) {
            num1 = i % 10;
            raschet1 = i / 10;
            num2 = raschet1 % 10;
            raschet2 = raschet1 / 10;
            num3 = raschet2 % 10;
            num4 = raschet2 / 10;
            if ((num1 + num2) == (num3 + num4)) {
                cout << i << endl;
            }
            else {
                a[i] = false;
            }
        }
    }
    for (int i = N - 1; i >= 2; i--) {
        if (a[i]) {
            cout << "The simplest number: " << i << endl;
            break;
        }
    }
}