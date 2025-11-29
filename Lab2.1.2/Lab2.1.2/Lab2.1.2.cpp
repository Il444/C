#include <iostream>
using namespace std;

int main()
{
    int  temp_, a_, num2 = 0, n, count = 0, num1_;
    double number, num1 = 0, a, temp;
    bool up = false;

    cout << "Enter number: ";
    cin >> number;
    cout << "Enter amount of numbers you want to check: ";
    cin >> n;

    a = number;
    a_ = a;
    a = a - a_;

    for (int i = 1; i < n; i++) {
        num1 = a * 10;
        num1_ = num1;

        temp = num1 * 10;
        temp_ = temp;
        num2 = temp_ % 10;

        if (num1 < num2) {
            count++;
        }
        a = num1 - num1_;
    }

    if (count == n-1) {
       up = true;
    }

    if (up) {
        cout << "Your numbers are growing steadily";
    }
    else {
        cout << "Your numbers are not growing steadily";
    }
}