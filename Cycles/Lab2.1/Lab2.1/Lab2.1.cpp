#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    int k;

    cout << "Enter number: ";
    cin >> n;
    cout << "Enter amount of equal numbers: ";
    cin >> k;

    int number = n;
    int u = n;
    int kol = 0;
    int count = 0;
    int c = 0;
    int b = 0;
    int temp = 0;

    while (u != 0) {
        u = u / 10;
        kol += 1;
    }


    for (int i = 0; i < kol; i++) {
        b = number % 10;
        temp = number / 10;
        while(temp > 0) {
            c = temp % 10;
            if (b == c) {
                count++;
            }
            temp /= 10;
        }
        number /= 10;
    }

    if (k != count) {
        cout << "No, the amount of equal numbers is: " << count << endl;
        return 0;
    }
    else {
        cout << "Yes, you are absolutely right! The amount of equal numbers is: " << count << endl;
        return 0;
    }
}
