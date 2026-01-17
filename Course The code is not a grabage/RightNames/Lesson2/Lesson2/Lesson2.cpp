#include <iostream>
using namespace std;

bool isPrimeCandidate(int number) {
    for (int divisor = 2; divisor < number - 1; divisor++) {
        if (number % divisor == 0) {
            return false;
            break;
        }
    }
    return true;
}

bool isReverseValueAlsoPrime(int reverseNumber) {
    for (int i = 2; i < reverseNumber - 1; i++) {
        if (reverseNumber % i == 0) {
            return false;
            break;
        }
        else {
            return true;
            break;
        }
    }
}

int main()
{
    int unitsDigit = 0;
    int tensDigit = 0;
    int hundreadsDigit = 0;
    int thousandsDigit = 0;
    int reverseNumber = 0;
    int numberWithoutLastDigit = 0;
    int numberWithoutLastTwoDigits = 0;
    bool isPrime = false;
    bool isSuperPrime = false;

    cout << "Here are all simple numbers from 1 000 to 9 999 which satisfy the condition: " << endl;

    for (int number = 1000; number <= 9999; number++) {
        isPrime = isPrimeCandidate(number);
        if (isPrime) {
            unitsDigit = number % 10;
            numberWithoutLastDigit = number / 10;
            tensDigit = numberWithoutLastDigit % 10;
            numberWithoutLastTwoDigits = numberWithoutLastDigit / 10;
            hundreadsDigit = numberWithoutLastTwoDigits % 10;
            thousandsDigit = numberWithoutLastTwoDigits / 10;
            reverseNumber = (unitsDigit * 1000) + (tensDigit * 100) + (hundreadsDigit * 10) + thousandsDigit;
            isSuperPrime = isReverseValueAlsoPrime(reverseNumber);
            if (isSuperPrime) {
                cout << number << endl;
            }
        }
    }
    return 0;
}