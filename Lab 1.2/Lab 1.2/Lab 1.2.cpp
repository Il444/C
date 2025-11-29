#include <iostream>
using namespace std;

int main()
{
    double R, x, y, d;

    cout << "Enter R: ";
    cin >> R;
    cout << "Enter X: ";
    cin >> x;
    cout << "Enter Y: ";
    cin >> y;

    d = 2 * R;

    if ((x < 0 && y > 0) || (x > 0 && y < 0)) {
        cout << "The dot does not belong to the plane " << endl;
        return 0;
    }
    else if (x >= 0 && y >= 0) {
        if (((x * x + y * y <= R * R) && (x >= y))) {
            cout << "The dot belongs to the plane" << endl;
            return 1;
        }
        else {
            cout << "The dot does not belong to the plane" << endl;
            return 0;
        }
    }
    else if (x <= 0 && y <= 0) {
        if ((x * x + y * y < R * R) && (x <= y)) {
            cout << "The dot belongs to the plane" << endl;
            return 1;
        }
        else {
            cout << "The dot does not belong to the plane" << endl;
            return 0;
        }
    }
}
