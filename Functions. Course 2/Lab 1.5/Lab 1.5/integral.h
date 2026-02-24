#pragma once

double f(double x, double s, double t);
double trapezoidArea(double (*f)(double, double, double), double a, double b, int n, double s, double t);
double doubleReculculation(double (*f)(double, double, double), double a, double b, double s, double t, double eps, int& k_iter);