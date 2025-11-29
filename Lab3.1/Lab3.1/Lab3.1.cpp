#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int choice;
    int count;
    int n;
    cout << "Enter the length of array: ";
    cin >> n;
    enum enmArrayInit {
        WithCost = 1,
        WithRand,
        ByUser,
    };
    int* A = new int[n];
    int* B = new int[n];
    cout << "How would you like to enter massiv?" << endl;
    cout << "1. Constants" << endl;
    cout << "2. Random numbers" << endl;
    cout << "3. Enter personally" << endl;
    cin >> choice;
    switch (choice) {
    case WithCost:
        for (int i = 0; i < n; i++) {
            A[i] = i;
        }
        break;
    case WithRand:
        for (int i = 0; i < n; i++) {
            A[i] = rand() % 100;
        }
        break;
    case ByUser:
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        break;
    default:
        cout << "Programm has been finished" << endl;
        return 0;
    }
    
    for (int i = 0; i < n; i++) {
        count = 0;
        for (int j = i; j < n; j++) {
            if (A[j] <= A[i]) {
                count++;
            }
        }
        B[i] = count;
    }
    cout << "Here is your massive A: " << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(3) << A[i];
    }
    cout << endl;

    cout << "Here is your massive B: " << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(3) << B[i];
    }
    cout << endl;
    while (true)
    {

    }
}