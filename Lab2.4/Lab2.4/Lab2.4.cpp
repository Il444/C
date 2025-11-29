#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int length;
    int count = 1;
    int maxCount = 0;
    int previous = 0;
    int current = 0;

    cout << "Enter the number of elements: ";
    cin >> length;

    if (length <= 0) {
        cout << "Invalid number of elements!" << endl;
    }

    cout << "Enter sequence: ";
    cin >> previous;

    for (int i = 0; i < length-1; i++) {
        cin >> current;

        if ((current > 0 && previous > 0) || (current < 0 && previous < 0)) {
            count++;
        }
        else {
            count = 1;
        }

        if (count > maxCount) {
            maxCount = count;
        }

        previous = current;
    }

    cout << "maxCount: " << maxCount;
    cin >> count;
}