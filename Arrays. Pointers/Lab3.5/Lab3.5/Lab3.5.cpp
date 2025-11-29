#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

int main()
{
    enum enmArrayInit {
        WithConst = 1,
        WithRand,
        ByUser,
    };
    int choice1 = 0;
    int choice2 = 0;
    int n = 0;
    int A_ik = 0;
    int A_kj = 0;
    int index_ik = 0;
    int index_kj = 0;
    int index_ij = 0;
    cout << "Enter the length of the vector b: ";
    cin >> n;
    const int N = n * (n + 1) / 2;
    int sum = 0;
    int* a = new int [N];
    int* a2 = new int[N];
    int* b = new int [n];
    int* c = new int[n];

    cout << "How would you like to enter the array b?" << endl;
    cout << "1. With constants" << endl;
    cout << "2. Random" << endl;
    cout << "3. Enter personally" << endl;
    cin >> choice1;
    
    switch (choice1) {
    case WithConst:
        for (int i = 0; i < n; i++) {
            b[i] = i;
        }
        break;
    case WithRand:
        for (int i = 0; i < n; i++) {
            b[i] = rand() % 10;
        }
        break;
    case ByUser:
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        break;
    }

    cout << "Vector B: ";
    for (int i = 0; i < n; i++) {
        cout << setw(3) << b[i];
    }

    cout << endl;
    cout << "How would you like to enter the symetrical matrix A?" << endl;
    cout << "1. With constants" << endl;
    cout << "2. Random" << endl;
    cout << "3. Enter personally" << endl;
    cin >> choice2;

    switch (choice2) {
    case WithConst:
        for (int i = 0; i < N; i++) {
            a[i] = i;
        }
        break;
    case WithRand:
        for (int i = 0; i < N; i++) {
            a[i] = rand() % 10;
        }
        break;
    case ByUser:
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        break;
    }

    cout << "The symmetric matrix A: ";
    for (int i = 0; i < N; i++) {
        cout << setw(3) << a[i];
    }
    
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;

            for (int k = 0; k < n; k++) {
                A_ik = 0;
                index_ik = 0;
                if (i <= k) {
                    index_ik = i * n - i * (i - 1) / 2 + (k - i);
                    A_ik = a[index_ik];
                }
                else {
                    index_ik = k * n - k * (k - 1) / 2 + (i - k);
                    A_ik = a[index_ik];
                }

                A_kj = 0;
                if (k <= j) {
                    index_kj = k * n - k * (k - 1) / 2 + (j - k);
                    A_kj = a[index_kj];
                }
                else {
                    index_kj = j * n - j * (j - 1) / 2 + (k - j);
                    A_kj = a[index_kj];
                }

                sum += A_ik * A_kj;
            }

            index_ij = i * n - i * (i - 1) / 2 + (j - i);
            a2[index_ij] = sum;

            cout << "A**2[" << i << "][" << j << "] = " << sum << " : " << index_ij << endl;
        }
    }

    cout << "Matrix A**2: ";
    for (int i = 0; i < N; i++) {
        cout << setw(4) << a2[i];
    }

    for (int i = 0; i < n; i++) {
        c[i] = 0; 

        for (int j = 0; j < n; j++) {
            int A2_element;
            if (i <= j) {
                int index = i * n - i * (i - 1) / 2 + (j - i);
                A2_element = a2[index];
            }
            else {
                int index = j * n - j * (j - 1) / 2 + (i - j);
                A2_element = a2[index];
            }

            c[i] += A2_element * b[j];
        }

    }

    cout << endl;
    cout << "c = ";
    for (int i = 0; i < n; i++) {
        cout << c[i] << " ";
    }
    cout << endl;
}