#include <iostream>
using namespace std;

int reverseNumbers(int number) {
    int reversed = 0;

    if (number < 0) {
        return -1;
    }

    while (number > 0) {
        if (reversed > INT_MAX / 10) {
            return -2;
        }
        reversed = reversed * 10 + (number % 10);
        number /= 10;
    }
    return reversed;
}

bool isPrimes(unsigned int number) {

    if (number < 2) {
        return false;
    }

    if (number == 2) {
        return true;
    }

    if (number % 2 == 0) {
        return false;
    }

    for (unsigned int divisor = 3; divisor <= number / divisor; divisor+=2) { // divisor * diviosr because check to square root is enogugh to make sure our number is simple, also we wrote number / divisor to make sure there will be not overflow  
        if (number % divisor == 0) {
            return false;
        }
    }
    return true;
}

bool isSuperPrimes(int number) {
    if (number < 0) {
        return false;
    }

    const int reversed = reverseNumbers(number);

    if (reversed < 0) {
        return false;
    }

    return isPrimes(static_cast<unsigned int>(number)) && isPrimes(static_cast<unsigned int>(reversed));  // to send usinged int instead of just int
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
    int from = 0;
    int to = 0;
    cout << "Enter the number from which we shall start our process(FROM): ";
    cin >> from;
    cout << "Enter the final number(TO): ";
    cin >> to;

    if (cin.fail()) {  // if there will be letters instead of numbers
        return 1;
    }

    if ((from > to) || (from < 1000) || (to > 9999)) {
        return 1;
    }

    cout << "Here are all simple numbers from 1 000 to 9 999 which satisfy the condition: " << endl;

    processRange(from, to);
    return 0;
}