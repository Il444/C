#include <iostream>
#include <cmath>
using namespace std;

double calculateExpression(double x, int s, int t) {
	const double numerator = tan(x * x) + sqrt(x);
	const double denominator = t * tan(x + s);
	if (fabs(denominator) < 1e-10) {
		cout << "You cant divide by zero";
		return 0;
	}
	return numerator / denominator;
}

int main()
{
	int x = 0;
	int s = 0;
	int t = 0;
	cout << "Enter constants: " << endl;
	cout << "x: ";
	cin >> x;
	cout << "s: ";
	cin >> s;
	cout << "t: ";
	cin >> t;

	if (x < 0) {
		cout << "You can't take the square root of a negative number" << endl;
		return 0;
	}

	const double result = calculateExpression(x, s, t);
	cout << "Result: " << result;

	return 0;
}