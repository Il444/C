#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    const int N = 5;
    int min_val = 0;
    int A[N][N];
    int B[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 100;
        }
    }

    cout << "Matrix A: " << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(3) << A[i][j];
        }
        cout << endl;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            min_val = A[i][j];

            if (i <= j) {
                for (int k = j; k < N; k++) {
                    if (A[i][k] < min_val) {
                        min_val = A[i][k];
                    }
                }
            }
            else {
                min_val = A[i][j];
                for (int k = i; k < N; k++) {
                    if (A[k][j] < min_val) {
                        min_val = A[k][j];
                    }
                }
            }

            B[i][j] = min_val;
        }
    }

    cout << endl;
    cout << "Matrix B:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(3) << B[i][j];
        }
        cout << endl;
    }

    return 0;
}