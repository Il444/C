#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
    const int max_size = 50;
    char palin_dec[max_size];
    char palin_bin[max_size];
    int length_dec = 0;
    int length_bin = 0;
    bool isPalindrom = false;

    for (int i = 1; i < 1000000; i++) {

        _itoa_s(i, palin_dec, max_size, 10);
        isPalindrom = true;
        length_dec = 0;
        length_bin = 0;

        while (palin_dec[length_dec] != '\0') {
            length_dec++;
        }

        for (int j = 0; j < length_dec / 2; j++) {
            if (palin_dec[j] != palin_dec[length_dec - 1 - j]) {
                isPalindrom = false;
                break;
            }
        }
        if (isPalindrom) {
            _itoa_s(i, palin_bin, max_size, 2);
            
            while (palin_bin[length_bin] != '\0') {
                length_bin++;
            }

            for (int j = 0; j < length_bin / 2; j++) {
                if (palin_bin[j] != palin_bin[length_bin - 1 - j]) {
                    isPalindrom = false;
                    break;
                }
            }
            if (isPalindrom) {
                cout << "Decimal: " << palin_dec << " Binary: " << palin_bin << endl;
            }
        }
    }
    return 0;
}