#include <iostream>
using namespace std;

int main()
{
    int k;
    int raschet = 0;
    int previous = 0;
    int current = 1;
    int fib1 = 1;

    cout << "Enter your number: ";
    cin >> k;
    cout << "" << endl;

    if (k == 1) {
        cout << "Number " << fib1 << " is on position " << k << endl;
        return 0;
    }
    else if (k == 2) {
        cout << "Number " << current << " is on position " << k << endl;
        return 0;
    }
    else {
        for (int i = 2; i <= k; i++) {
            raschet = current;
            current += previous;
            previous = raschet;
            if (k == i) {
                cout << "Number " << current << " is on position " << k << endl;
                return 0;
            }
        }
    }
}