#include <iostream>
using namespace std;

int main()
{
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    int num4 = 0;
    int raschet1 = 0;
    int raschet2 = 0;
    bool isSimple = false;

    cout << "Here are all simple numbers from 1 000 to 9 999 which satisfy the condition: " << endl;

    for(int num = 1000; num <= 9999; num++) {
        isSimple = true;
        for (int i = 2; i < num-1; i++) {
            if (num % i == 0) {
                isSimple = false;
                break;
            }
        }
        if (isSimple) {
            num1 = num % 10;
            raschet1 = num / 10;
            num2 = raschet1 % 10;
            raschet2 = raschet1 / 10;
            num3 = raschet2 % 10;
            num4 = raschet2 / 10;
            if (num1 + num2 == num3 + num4) {
                cout << num << endl;
            }
        }
    }
    return 0;
}