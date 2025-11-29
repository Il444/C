#include <iostream>
using namespace std;

int main()
{
	double x, y, z, a;

	cin >> x;
	cin >> y;
	cin >> z;
	a = x;

	if (y > z && y > x) {
		if (x > z) {
			x = y;
			y = a;
			cout << "X = " << x << endl;
			cout << "Y = " << y << endl;
			cout << "Z = " << z << endl;
			return 0;
		}
		if (x == z) {
			x = y;
			y = a;
			cout << "X = " << x << endl;
			cout << "Y = " << y << endl;
			cout << "Z = " << z << endl;
			return 0;
		}
		if (z > x) {
			a = x;
			x = y;
			y = z;
			z = a;
			cout << "X = " << x << endl;
			cout << "Y = " << y << endl;
			cout << "Z = " << z << endl;
			return 0;
		}
	}
	if (z > y && z > x) {
		if (y > x) {
			x = z;
			z = a;
			cout << "X = " << x << endl;
			cout << "Y = " << y << endl;
			cout << "Z = " << z << endl;
			return 0;
		}
		if (x == y) {
			x = z;
			z = a;
			cout << "X = " << x << endl;
			cout << "Y = " << y << endl;
			cout << "Z = " << z << endl;
			return 0;
		}
		if (x > y) {
			a = y;
			y = x;
			x = z;
			z = a;
			cout << "X = " << x << endl;
			cout << "Y = " << y << endl;
			cout << "Z = " << z << endl;
			return 0;
		}
	}
	if (x > y && x > z) {
		if (y > z) {
			cout << "X = " << x << endl;
			cout << "Y = " << y << endl;
			cout << "Z = " << z << endl;
			return 0;
		}
		if (y == z) {
			cout << "X = " << x << endl;
			cout << "Y = " << y << endl;
			cout << "Z = " << z << endl;
			return 0;
		}
		if (z > y) {
			a = y;
			y = z;
			z = a;
			cout << "X = " << x << endl;
			cout << "Y = " << y << endl;
			cout << "Z = " << z << endl;
			return 0;
		}
	}
}
