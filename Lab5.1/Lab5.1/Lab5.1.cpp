#include <iostream>
using namespace std;

long long factorial(int k) {
    if (k <= 1) {
        return 1;
    }
    return k * factorial(k - 1);
}

double stepen(int k, double x) {
    double result = 1.0;
    for (int i = 0; i < 2 * (k + 1); i++) {
        result *= (x / 2.0);
    }
    return result;
}

double sum1(double x, int *terms) {
    double sum = 0;
    double e = 0.000001;
    double element = 1.0;
    double perv_slog = 0;
    double vtor_slog = 0;
    *terms = 0;
    long long fact = 0;
    for (int k = 1; element >= e; k++) {
        (*terms)++;
        fact = factorial(k);
        vtor_slog = stepen(k, x);
        if (k % 2 == 0) {
            perv_slog = 1.0 / (fact * fact);
        }
        else {
            perv_slog = -1.0 / (fact * fact);
        }
        element = perv_slog * vtor_slog;
        sum += element;
        if (element < 0) {
            element = -element;
        }
    }
    return sum;
}

void sum2(double *x, double *sum, int *terms) {
    *sum = 0;
    double e = 0.000001;
    double element = 1.0;
    double perv_slog = 0;
    double vtor_slog = 0;
    *terms = 0;
    long long fact = 0;
    for (int k = 1; element >= e; k++) {
        (*terms)++;
        fact = factorial(k);
        vtor_slog = stepen(k, *x);
        if (k % 2 == 0) {
            perv_slog = 1.0 / (fact * fact);
        }
        else {
            perv_slog = -1.0 / (fact * fact);
        }
        element = perv_slog * vtor_slog;
        *sum += element;
        if (element < 0) {
            element = -element;
        }
    }
}

void sum3(double &x, double &sum, int &terms) {
    sum = 0;
    double e = 0.000001;
    double element = 1.0;
    double perv_slog = 0;
    double vtor_slog = 0;
    terms = 0;
    long long fact = 0;
    for (int k = 1; element >= e; k++) {
        terms++;
        fact = factorial(k);
        vtor_slog = stepen(k, x);
        if (k % 2 == 0) {
            perv_slog = 1.0 / (fact * fact);
        }
        else {
            perv_slog = -1.0 / (fact * fact);
        }
        element = perv_slog * vtor_slog;
        sum += element;
        if (element < 0) {
            element = -element;
        }
    }
}

int main()
{
    double num = 0;
    double sum = 0;
    int terms = 0;
    int choice = 0;
    cout << "Enter your number(from 0 to 1): ";
    cin >> num;
    enum emmArrayInit {
        WithReturn = 1,
        WithPointers,
        WithLinks
    };
    if (num <= 0 || num > 1) {
        cout << "You gave incorrect data";
    }
    else {
        cout << "Which method would you like to calculate the amount:" << endl;
        cout << "1. Using return function" << endl;
        cout << "2. Using function with pointers" << endl;
        cout << "3. Using function with links" << endl;
        cin >> choice;
        switch (choice) {
        case WithReturn:
            sum = sum1(num, &terms);
            cout << "Terms: " << terms << endl;
            cout << "Result: " << sum << endl;
            break;
        case WithPointers:
            sum2(&num, &sum, &terms);
            cout << "Terms: " << terms << endl;
            cout << "Result: " << sum << endl;
            break;
        case WithLinks:
            sum3(num, sum, terms);
            cout << "Terms: " << terms << endl;
            cout << "Result: " << sum << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    }
}