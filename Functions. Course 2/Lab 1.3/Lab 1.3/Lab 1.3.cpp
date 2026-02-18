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

int GetAmountOfUniqueNumbers(int* array, int length) {
    int count = 0;
    bool isUnique = false;
    for (int i = 0; i < length; i++) {
        isUnique = true;
        for (int j = 0; j < length; j++) {
            if (array[i] == array[j] && i != j) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            count++;
        }
    }
    return count;
}

int FindMaxNumber(int* uniqueArray, int length) {
    int maxNum = 0;
    for (int i = 0; i < length; i++) {
        if (uniqueArray[i] > maxNum) {
            maxNum = uniqueArray[i];
        }
    }
    return maxNum;
}

int& FindUniqueAndMaxNumber(int* array, int length) {
    int countOfUniqueNum = GetAmountOfUniqueNumbers(array, length);
    int* uniqueArray = new int[countOfUniqueNum];
    bool isUnique = false;
    int maxNum = 0;
    int uniqueIndex = 0;
    for (int i = 0; i < length; i++) {
        isUnique = true;
        for (int j = 0; j < length; j++) {
            if (array[i] == array[j] && i != j) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            uniqueArray[uniqueIndex] = array[i];
            uniqueIndex++;
        }
    }
    cout << "Unique Array: ";
    for (int i = 0; i < countOfUniqueNum; i++) {
        cout << uniqueArray[i] << " ";
    }
    cout << endl;
    maxNum = FindMaxNumber(uniqueArray, countOfUniqueNum);
    return maxNum;
}

void TransformMaxToZero(int* array, int length, int& maxNum) {
    for (int i = 0; i < length; i++) {
        if (array[i] == maxNum) {
            array[i] = 0;
            break;
        }
    }
}

void PrintArray(int* array, int length) {
    for (int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    srand(time(NULL));
    int choice = 0;
    int length = 0;
    int maxNum = 0;
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
    maxNum = FindUniqueAndMaxNumber(array, length);
    cout << "Max and unique number: " << maxNum << endl;
    TransformMaxToZero(array, length, maxNum);
    cout << "Final array: ";
    PrintArray(array, length);

    delete[] array;
}