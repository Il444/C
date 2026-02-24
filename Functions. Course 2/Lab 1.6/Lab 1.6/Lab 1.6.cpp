#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
void InitializeArrayPersonally(T* array, int length) {
    for (int i = 0; i < length; i++) {
        cin >> array[i];
    }
}

void InitializeArrayPersonally(char* array) {
    cout << "Write: " << endl;
    char ch;
    int i = 0;
    cin.ignore();

    while (true) {
        ch = cin.get();
        if (ch == '\n') break;

        array[i] = ch;
        i++;
    }
}

void InitializeArrayRandomly(int* array, int length) {
    for (int i = 0; i < length; i++) {
        array[i] = rand() % 100;
    }
}


void InitializeArrayRandomly(double *array, int length) {
    for (int i = 0; i < length; i++) {
        array[i] = (double)(rand() % 100)/10;
    }
}


void InitializeArrayRandomly(char* array, int length) {
    for (int i = 0; i < length; i++) {
        array[i] = 'a' + (rand() % 26);
    }
}

void InitializeArrayAscending(int* array, int length) {
    for (int i = 0; i < length; i++) {
        array[i] = i;
    }
}

void InitializeArrayAscending(double* array, int length) {
    for (int i = 0; i < length; i++) {
        array[i] = i * 1.0;
    }
}

void InitializeArrayAscending(char* array, int length) {
    for (int i = 0; i < length; i++) {
        array[i] = 'a' + i;
    }
}

template <typename T>
void PrintArray(T* array, int length) {
    for (int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
}

template <typename T>
void Merge(T* array, int left, int mid, int right) {
    int i = 0;
    int j = 0;
    int k = left;
    int size1 = mid - left + 1;
    int size2 = right - mid;

    T* leftArray = new T[size1];
    T* rightArray = new T[size2];

    for (int i = 0; i < size1; i++) {
        leftArray[i] = array[left + i];
    }

    for (int i = 0; i < size2; i++) {
        rightArray[i] = array[mid + 1 + i];
    }

    while (i < size1 && j < size2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        }
        else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < size1) {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < size2) {
        array[k] = rightArray[j];
        j++;
        k++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

template <typename T>
void MergeSort(T* array, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    MergeSort(array, left, mid);
    MergeSort(array, mid + 1, right);

    Merge(array, left, mid, right);
}

int main() {
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
    cout << endl;
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
    cout << endl;
    cout << "Sorted double array: ";
    PrintArray(doubleArray, length);
    cout << endl;

    cout << "How would you like to initialize the char array?" << endl;
    cout << "1. Personally" << endl << "2. Randomly" << endl << "3. Ascending" << endl;
    cin >> choice;

    while (length <= 0) {
        cout << "You wrote incorrect data, try again" << endl;
        cin >> length;
    }

    char* charArray = new char[length];

    switch (choice) {
    case 1:
        InitializeArrayPersonally(charArray);
        break;
    case 2:
        InitializeArrayRandomly(charArray, length);
        break;
    case 3:
        InitializeArrayAscending(charArray, length);
        break;
    }

    cout << "Original double array: ";
    PrintArray(charArray, length);
    MergeSort(charArray, 0, length - 1);
    cout << endl;
    cout << "Sorted double array: ";
    PrintArray(charArray, length);
    cout << endl;

    return 0;
}