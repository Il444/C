#include <iostream>
#include <cmath>
#include "integral.h"
using namespace std;

double f(double x, double s, double t) {
	return t / (sqrt(x * x * x + 1) + s);
}

double trapezoidArea(double (*f)(double, double, double), double a, double b, int n, double s, double t) {
	double square = 0;
	double x_curr = 0;
	double y_prev = f(a, s, t);
	double y_curr = 0;
	double h = (b - a) / n;
	double sum = 0;

	for (int i = 1; i <= n; i++) {
		x_curr = a + i*h;
		y_curr = f(x_curr, s, t);
		square = (y_curr + y_prev) / 2 * h;

		y_prev = y_curr;
		sum += square;

	}
	return sum;
}

double doubleReculculation(double (*f)(double, double, double), double a, double b, double s, double t, double eps, int& k_iter) {
	double I_prev = 0;
	double I_curr = 0;
	k_iter = 0;

	for (int n = 2;; n*=2) {
		k_iter++;
		I_prev = trapezoidArea(f, a, b, n, s, t);
		I_curr = trapezoidArea(f, a, b, n*2, s, t);

		if (fabs(I_curr - I_prev) < eps) {
			return I_curr;
		}
	}
}