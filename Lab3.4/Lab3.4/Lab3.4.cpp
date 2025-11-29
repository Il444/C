#include <iostream>
using namespace std;

int main()
{
    const int razmer = 1000;
    long long int a[razmer] = { 0 };
    int zeroes = 0;
    int k = 0;
    long long number = 0;
    long long temp = 0;
    int amount = 0;
    bool yes = false;
    cout << "Enter the amount of zeros you wanna get: ";
    cin >> k;

    if (k == 0) {
        cout << "N = " << 0 << endl;
    }
    else {
        for (int N = 0; yes != true; N++) {
            number = pow(5, N);
            temp = number;
            amount = 0;
            zeroes = 0;
            cout << temp << endl;
            while (temp != 0) {
                a[amount] = temp % 10;
                temp /= 10;
                amount++;
            }
            for (int i = amount - 1; i >= 0; i--) {
                if (a[i] == 0) {
                    zeroes++;
                    if (zeroes >= k) {
                        cout << "N = " << N << endl;
                        yes = true;
                        return 0;
                    }
                }
                else {
                    zeroes = 0;;
                }
            }
        }
    }

    return 0;
}