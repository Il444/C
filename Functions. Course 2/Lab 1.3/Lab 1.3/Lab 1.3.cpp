#include <iostream>
#include <stdlib.h>
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

void InitializeArray(int* array, int length) {
    for (int i = 0; i < length; i++) {
        array[i] = i;
    }
}

void PrintArray(int* array, int length) {
    for (int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
}

int main()
{
    srand(time(NULL));
    int choice = 0;
    int length = 0;
    enum InitArray {
        Personally = 1,
        Randomly,
        Ascending
    };

    cout << "How would you like to initialize the array?" << endl;
    cout << "1. Personally" << endl << "2. Randomly" << endl << "3. Ascending" << endl;
    cin >> choice;
    cout << "Enter the length of array: ";
    cin >> length;

    while(length <= 0) {
        cout << "Oh, it seems you wrote incorrect data, try again" << endl;
        cin >> length;
    }

    int* array = new int[length];

    switch (choice) {
        case 1:
            InitializeArrayPersonally(array, length);
            break;
        case 2:
            InitializeArrayRandomly(array, length);
            break;
        case 3:
            InitializeArray(array, length);
            break;
    }

    PrintArray(array, length);

    delete[] array;
}