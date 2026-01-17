#include <iostream>
using namespace std;

int reverseNumbers(int number) {
    int reversed = 0;
    while (number > 0) {
        reversed = reversed * 10 + (number % 10);
        number /= 10;
    }
    return reversed;
}

bool isPrimes(int number) {
    for (int divisor = 2; divisor < number - 1; divisor++) {
        if (number % divisor == 0) {
            return false;
        }
    }
    return true;
}

bool isSuperPrimes(int number) {
    return isPrimes(number) && isPrimes(reverseNumbers(number));
}

void printIfSuperPrimes(int number) {
    if (isSuperPrimes(number)) {
        cout << number << endl;
    }
}

void processRange(int from, int to) {
    for (int number = from; number <= to; number++) {
        printIfSuperPrimes(number);
    }
}

int main()
{
    cout << "Here are all simple numbers from 1 000 to 9 999 which satisfy the condition: " << endl;

    processRange(1000, 9999);
    return 0;
}