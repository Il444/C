#include <iostream>
#include <math.h> 
#include <cmath>
using namespace std;


int main()
{
    // Косинус
    double x, cosin;

    cin >> x;
    cout << "X = " << x << endl;

    cosin = cos(x);

    cosin = pow(cos(x * x), 3);


    cout << "Cosinus = " << cosin << endl;

    // Знаменатель

    int s, t;
    long double znam;

    cin >> s;
    cin >> t;


    if (t % 2 == 0) {
        if (x >= 0) {
            znam = s * pow(x, 1.0 / t);
        }
        else {
            cout << "There can't be a negative value under the root!" << endl;
        }
    }
    else {
        znam = s * pow(x, 1.0 / t);
    }

    if (znam == 0) {
        cout << "The denominator can't be zero!" << endl;
        return 0;
    }
    if (x < 0) {
        znam = s * (-pow(-x, 1.0 / t));
    }



    cout << "Znam = " << znam << endl;

    // y

    long double y;

    y = cosin / znam;

    cout << "Y =" << y << endl;

}
