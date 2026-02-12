#include <iostream>
#include <iomanip>
using namespace std;

void InputLengthOfMatrix(int &n) {
    do {
        cout << "Enter the length of matrix: ";
        cin >> n;
        if (n <= 0) {
            cout << "Error. Try again!" << endl;
        }
    } while (n <= 0);
}

void FillMatrix(const int n, int** matrix) {
    int count = 0;
    int top = 0;
    int bottom = n - 1;
    int right = n - 1;
    int left = 0;

    while (count < n * n) {
        for (int j = right; j >= left; j--) {
            count++;
            *(*(matrix + top) + j) = count;
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            count++;
            *(*(matrix + i) + left) = count;
        }
        left++;

        for (int j = left; j <= right; j++) {
            count++;
            *(*(matrix + bottom) + j) = count;
        }
        bottom--;

        for (int i = bottom; i >= top; i--) {
            count++;
            *(*(matrix + i) + right) = count;
        }
        right--;
    }
}

void PrintMatrix(int** matrix, const int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(4) << *(*(matrix + i) + j);
        }
        cout << endl;
    }
}

int main()
{
    int n = 0;
    InputLengthOfMatrix(n);

    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }

    FillMatrix(n, matrix);
    PrintMatrix(matrix, n);

    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}