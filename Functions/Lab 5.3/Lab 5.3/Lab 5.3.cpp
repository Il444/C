#include <iostream>
#include <stdlib.h>
using namespace std;

template <typename T>
void Init(T** matrix, int length_lines, int length_rows) {
    for (int i = 0; i < length_lines; i++) {
        for (int j = 0; j < length_rows; j++) {
            cin >> matrix[i][j];
        }
    }
}

template <typename T>
void RandomInit(T** matrix, int length_lines, int length_rows) {
    for (int i = 0; i < length_lines; i++) {
        for (int j = 0; j < length_rows; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

template <typename T>
void output(T** matrix, int length_lines, int length_rows) {
    for (int i = 0; i < length_lines; i++) {
        for (int j = 0; j < length_rows; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

template <typename T>
T Sum(T** matrix, int i, int length_lines) {
    T sum = 0;
    for (int j = 0; j < length_lines; j++) {
        sum += matrix[j][i];
    }
    cout << "Sum " << i << " = " << sum << endl;
    return sum;
}

template <typename T>
void SumArray(T** matrix, int length_lines, int length_rows, T* sums) {
    for (int i = 0; i < length_rows; i++) {
        sums[i] = Sum(matrix, i, length_lines);
    }
}

template <typename T>
void swapRows(T** matrix, int length_lines, int i, int j) {
    for (int k = 0; k < length_lines; k++) {
        T temp = matrix[k][i];
        matrix[k][i] = matrix[k][j];
        matrix[k][j] = temp;
    }
}

template <typename T>
void Sort(T** matrix, int length_lines, int length_rows) {
    T* sums = new T[length_rows];
    SumArray(matrix, length_lines, length_rows, sums);
    for (int i = 0; i < length_rows - 1; i++) {
        for (int j = 0; j < length_rows - i - 1; j++) {
            if (sums[j] < sums[j + 1]) {
                swapRows(matrix, length_lines, j, j + 1);
                T temp = sums[j];
                sums[j] = sums[j + 1];
                sums[j + 1] = temp;
            }
        }
    }
    delete[] sums;
}

int main()
{
    int choice = 0;
    int length_lines = 0;
    int length_rows = 0;
    cout << "Enter the length of your matrix's lines: ";
    cin >> length_lines;
    cout << "Enter the length of your matrix's rows: ";
    cin >> length_rows;

    if (length_lines <= 0 || length_rows <= 0) {
        cout << "Are you kidding?" << endl;
        return 0;
    }

    double** matrix = new double* [length_lines];
    for (int i = 0; i < length_lines; i++) {
        matrix[i] = new double[length_rows];
    }

    cout << "How would you like to enter the matrix?" << endl;
    cout << "1. Personally" << endl;
    cout << "2. Random" << endl;
    cin >> choice;

    enum InitMatrix {
        Personally = 1,
        Random
    };

    switch (choice) {
        case(Personally):
            Init(matrix, length_lines, length_rows);
            break;
        case(Random):
            RandomInit(matrix, length_lines, length_rows);
            break;
    }

    cout << "Here is your matrix:" << endl;

    output(matrix, length_lines, length_rows);

    cout << "Here is your sort matrix:" << endl;

    Sort(matrix, length_lines, length_rows);
    output(matrix, length_lines, length_rows);

    delete[] matrix;
}