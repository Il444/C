#include <iostream>
using namespace std;

int main()
{
    double a, b, c, d, e, f, s, t, u, dot1, dot2, dot3;

    cout << "Write down first dot's coordinates" << endl;
    cin >> a;
    cin >> b;
    cout << "Write down second dot's coordinates" << endl;
    cin >> c;
    cin >> d;
    cout << "Write down third dot's coordinates" << endl;
    cin >> e;
    cin >> f;
    cout << "Write down the coeficients of the straight line" << endl;
    cin >> s;
    cin >> t;
    cin >> u;

    dot1 = s * a + t * b + u;
    dot2 = s * c + t * d + u;
    dot3 = s * e + t * f + u;

    if ((dot1 < 0 && dot2 < 0 && dot3 < 0) || (dot1 > 0 && dot2 > 0 && dot3 > 0)) {
        cout << "Triangle lies on the one plane" << endl;
    }
    else if ((dot1 == 0 || dot2 == 0 || dot3 == 0)) {
        cout << "Coordinates are incorrect" << endl;
    }
    else {
        cout << "Triangle does not lie on the one plane" << endl;
    }
    return 0;
}