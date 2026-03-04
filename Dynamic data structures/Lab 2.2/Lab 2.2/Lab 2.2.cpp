#include <iostream>
#include <stdlib.h>
using namespace std;

template <typename T>
void InitPersonally(T** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
}

template <typename T>
void RandomInit(T** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

template <typename T>
void InitAscending(T** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = j;
        }
    }
}

template <typename T>
void InitPersonallyL(T* matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i*n + j];
        }
    }
}

template <typename T>
void RandomInitL(T* matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i*n + j] = rand() % 100;
        }
    }
}

template <typename T>
void InitAscendingL(T* matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i*n + j] = j;
        }
    }
}

template <typename T>
void ChoiceOfInitializing(T** matrix, int n) {
    int choice = 0;
    cout << "How would you like to enter the matrix?" << endl;
    cout << "1. Personally" << endl;
    cout << "2. Random" << endl;
    cout << "3. Ascendingly" << endl;
    cin >> choice;

    enum InitMatrix {
        Personally = 1,
        Random,
        Ascending
    };

    switch (choice) {
    case(Personally):
        InitPersonally(matrix, n);
        break;
    case(Random):
        RandomInit(matrix, n);
        break;
    case(Ascending):
        InitAscending(matrix, n);
        break;
    }
}

template <typename T>
void ChoiceOfInitializingL(T* matrix, int n) {
    int choice = 0;
    cout << "How would you like to enter the matrix?" << endl;
    cout << "1. Personally" << endl;
    cout << "2. Random" << endl;
    cout << "3. Ascendingly" << endl;
    cin >> choice;

    enum InitMatrix {
        Personally = 1,
        Random,
        Ascending
    };

    switch (choice) {
    case(Personally):
        InitPersonallyL(matrix, n);
        break;
    case(Random):
        RandomInitL(matrix, n);
        break;
    case(Ascending):
        InitAscendingL(matrix, n);
        break;
    }
}

template <typename T>
void output(T** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

template <typename T>
void outputL(T* matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i*n + j] << " ";
        }
        cout << endl;
    }
}

template <typename T>
T** CreateIdentityMatrix(int n) {
    T** E = new T*[n];
    for (int i = 0; i < n; i++) {
        E[i] = new T[n];
        for (int j = 0; j < n; j++) {
            if (i == j) {
                E[i][j] = 1;
            }
            else {
                E[i][j] = 0;

            }
        }
    }
    return E;
}

template <typename T>
T* CreateIdentityMatrixL(int n) {
    T* E = new T [n*n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                E[i*n + j] = 1;
            }
            else {
                E[i*n + j] = 0;

            }
        }
    }
    return E;
}

template <typename T>
T* MultipleMatricesL(T* A, int n, int m) {
    T* result = new T [n*n];

    for (int i = 0; i < n*n; i++) {
        result[i] = A[i];
    }

    int count = 1;
    while (count < m) {
        T* temp = new T [n*n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp[i*n + j] = 0;
                for (int k = 0; k < n; k++) {
                    temp[i*n + j] += result[i*n + k] * A[k*n + j];
                }
            }
        }

        for (int i = 0; i < n*n; i++) {
            result[i] = temp[i];
        }

        delete[] temp;

        count++;
    }
    return result;
}

template <typename T>
T** MultipleMatrices(T** A, int n, int m) {
    T** result = new T * [n];
    for (int i = 0; i < n; i++) {
        result[i] = new T[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j];
        }
    }

    int count = 1;
    while (count <= m) {
        T** temp = new T * [n];

        for (int i = 0; i < n; i++) {
            temp[i] = new T[n];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp[i][j] = 0;
                for (int k = 0; k < n; k++) {
                    temp[i][j] += result[i][k] * A[k][j];
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                result[i][j] = temp[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            delete[] temp[i];
        }
        delete[] temp;

        count++;
    }
    return result;
}

template <typename T>
T* AdditionMatricesL(T* A, int n, int m) {
    T* result = CreateIdentityMatrixL<T>(n);
    T* powerMatrix;

    for (int i = 1; i <= m; i++) {
        powerMatrix = MultipleMatricesL(A, n, i);

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[j*n + k] += powerMatrix[j*n + k];
            }
        }

        delete[] powerMatrix;
    }

    return result;
}

template <typename T>
T** AdditionMatrices(T** A, int n, int m) {
    T** result = CreateIdentityMatrix<T>(n);
    T** powerMatrix;

    for (int i = 1; i <= m; i++) {
        powerMatrix = MultipleMatrices(A, n, i);

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[j][k] += powerMatrix[j][k];
            }
        }

        for (int j = 0; j < n; j++) {
            delete[] powerMatrix[j];
        }
        delete[] powerMatrix;
    }

    return result;
}

int main()
{
    int choice = 0;
    int n = 0;
    int m = 0;
    cout << "Enter the length of your matrix: ";
    cin >> n;
    cout << "Enter the degree: ";
    cin >> m;

    if (n <= 0 || m <= 0) {
        cout << "Are you kidding?" << endl;
        return 0;
    }

    cout << "Which method do you prefer to solve your equation?" << endl;
    cout << "1. Using 2D array" << endl;
    cout << "2. Using 1D array" << endl;

    cin >> choice;

    long long** matrix = new long long* [n];

    for (int i = 0; i < n; i++) {
        matrix[i] = new long long[n];
    }

    long long* matrixLin = new long long[n * n];

    if (choice == 1) {
        ChoiceOfInitializing(matrix, n);
        cout << "Here is your matrix:" << endl;

        output(matrix, n);

        cout << "Here is the solution: " << endl;
        long long** result = AdditionMatrices<long long>(matrix, n, m);
        output(result, n);

        for (int i = 0; i < n; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;

        for (int i = 0; i < n; i++) {
            delete[] result[i];
        }
        delete[] result;
    }
    else if (choice == 2) {
        ChoiceOfInitializingL(matrixLin, n);
        cout << "Here is your matrix:" << endl;

        outputL(matrixLin, n);

        cout << "Here is the solution: " << endl;
        long long* result = AdditionMatricesL(matrixLin, n, m);
        outputL(result, n);

    }
    else {
        cout << "It seeems you wrote incorrect data" << endl;
    }


    
}