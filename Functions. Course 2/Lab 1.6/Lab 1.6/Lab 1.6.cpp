#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void InitializeArrayPersonally(int* array, int length) {
    for (int i = 0; i < length; i++) {
        cin >> array[i];
    }
}

void InitializeArrayRandomly(int* array, int length) {
    for (int i = 0; i < length; i++) {
        array[i] = rand() % 100;
    }
}

void InitializeArrayAscending(int* array, int length) {
    for (int i = 0; i < length; i++) {
        array[i] = i;
    }
}

void InitializeArrayPersonally(double* array, int length) {
    for (int i = 0; i < length; i++) {
        cin >> array[i];
    }
}

void InitializeArrayRandomly(double* array, int length) {
    for (int i = 0; i < length; i++) {
        array[i] = (rand() % 100) / 10.0;
    }
}

void InitializeArrayAscending(double* array, int length) {
    for (int i = 0; i < length; i++) {
        array[i] = i;
    }
}

void InitializeArrayPersonally(char* array, int length) {
    for (int i = 0; i < length; i++) {
        cin >> array[i];
    }
}

void InitializeArrayRandomly(char* array, int length) {
    for (int i = 0; i < length; i++) {
        array[i] = 'a' + rand() % 26;
    }
}

void InitializeArrayAscending(char* array, int length) {
    for (int i = 0; i < length; i++) {
        array[i] = 'a' + i;
    }
}

void PrintArray(int* array, int length) {
    for (int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void PrintArray(double* array, int length) {
    for (int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void PrintArray(char* array, int length) {
    for (int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void PrintArray(char** array, int length) {
    for (int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

template <typename T>
void MergeArrays(T* array, int left, int mid, int right) {
    T* temp = new T[right - left + 1];

    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {
        if (array[i] <= array[j]) {
            temp[k] = array[i];
            i++;
        }
        else {
            temp[k] = array[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = array[i];
        i++;
        k++;
    }

    while (j <= right) {
        temp[k] = array[j];
        j++;
        k++;
    }

    for (int p = 0; p < k; p++) {
        array[left + p] = temp[p];
    }

    delete[] temp;
}

template <typename T>
void MergeSort(T* array, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        MergeSort(array, left, mid);
        MergeSort(array, mid + 1, right);

        MergeArrays(array, left, mid, right);
    }
}

int main() {
    srand(time(NULL));
    int choice = 0;
    int length = 0;

    enum InitArray {
        Personally = 1,
        Randomly,
        Ascending
    };

    cout << "How would you like to initialize the integer array?" << endl;
    cout << "1. Personally" << endl << "2. Randomly" << endl << "3. Ascending" << endl;
    cin >> choice;
    cout << "Enter the length of integer array: ";
    cin >> length;

    while (length <= 0) {
        cout << "Oh, it seems you wrote incorrect data, try again" << endl;
        cin >> length;
    }

    int* intArray = new int[length];

    switch (choice) {
    case 1:
        InitializeArrayPersonally(intArray, length);
        break;
    case 2:
        InitializeArrayRandomly(intArray, length);
        break;
    case 3:
        InitializeArrayAscending(intArray, length);
        break;
    }

    cout << "Original integer array: ";
    PrintArray(intArray, length);
    MergeSort(intArray, 0, length - 1);
    cout << "Sorted integer array: ";
    PrintArray(intArray, length);
    cout << endl;

    cout << "How would you like to initialize the double array?" << endl;
    cout << "1. Personally" << endl << "2. Randomly" << endl << "3. Ascending" << endl;
    cin >> choice;
    cout << "Enter the length of double array: ";
    cin >> length;

    while (length <= 0) {
        cout << "Oh, it seems you wrote incorrect data, try again" << endl;
        cin >> length;
    }

    double* doubleArray = new double[length];

    switch (choice) {
    case 1:
        InitializeArrayPersonally(doubleArray, length);
        break;
    case 2:
        InitializeArrayRandomly(doubleArray, length);
        break;
    case 3:
        InitializeArrayAscending(doubleArray, length);
        break;
    }

    cout << "Original double array: ";
    PrintArray(doubleArray, length);
    MergeSort(doubleArray, 0, length - 1);
    cout << "Sorted double array: ";
    PrintArray(doubleArray, length);
    cout << endl;

    cout << "How would you like to initialize the char array?" << endl;
    cout << "1. Personally" << endl << "2. Randomly" << endl << "3. Ascending" << endl;
    cin >> choice;
    cout << "Enter the length of char array: ";
    cin >> length;

    while (length <= 0) {
        cout << "You wrote incorrect data, try again" << endl;
        cin >> length;
    }

    char* charArray = new char[length];

    switch (choice) {
    case 1:
        InitializeArrayPersonally(charArray, length);
        break;
    case 2:
        InitializeArrayRandomly(charArray, length);
        break;
    case 3:
        InitializeArrayAscending(charArray, length);
        break;
    }

    cout << "Original char array: ";
    PrintArray(charArray, length);
    MergeSort(charArray, 0, length - 1);
    cout << "Sorted char array: ";
    PrintArray(charArray, length);
    cout << endl;

    delete[] intArray;
    delete[] doubleArray;
    delete[] charArray;

    return 0;
}