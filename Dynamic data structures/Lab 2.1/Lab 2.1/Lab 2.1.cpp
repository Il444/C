#include <iostream>
using namespace std;

void SetCountZero(int* count, const int MAX_SIZE) {
    for (int i = 0; i < MAX_SIZE + 1; i++) {
        count[i] = 0;
    }
}

void InitializeArrayPersonally(int* count, int length, const int MAX_VALUE) {
    int num = 0;
    cout << "Enter numbers: ";
    for (int i = 0; i < length; i++) {
        cin >> num;
        if (num > MAX_VALUE) {
            cout << "The number can't be more than 10^7!";
            i--;
            continue;
        }
        else if (num <= 0) {
            cout << "You wrote incorrect number!";
            i--;
            continue;
        }
        count[num]++;
    }
}


void InitializeArrayRandomly(int* count, int length, const int MAX_VALUE) {
    int num = 0;
    for (int i = 0; i < length; i++) {
        num = rand() % MAX_VALUE + 1;
        count[num]++;
    }
}

void PrintOriginalArray(int* count, const int MAX_SIZE) {
    cout << "Original Array: ";
    for (int i = 1; i < MAX_SIZE; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                cout << i << " ";
            }
        }
    }
    cout << endl;
}

void PrintRepeatedAscedingly(int* count, const int MAX_SIZE) {
    cout << "Numbers that appears exactly twice: ";
    bool found = false;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (count[i] == 2) {
            cout << i << " ";
            found = true;
        }
    }

    if (!found) {
        cout << "No numbers appers twice.";
    }
    cout << endl;
}

int main()
{
    int choice = 0;
    long long length = 0;
    const int MAX_VALUE = 10000000;

    enum InitArray {
        Personally = 1,
        Randomly,
        Ascending
    };

    cout << "How would you like to initialize the integer array?" << endl;
    cout << "1. Personally" << endl << "2. Randomly" << endl;
    cin >> choice;
    cout << "Enter the length of integer array: ";
    cin >> length;

    while (length <= 0) {
        cout << "Oh, it seems you wrote incorrect data, try again" << endl;
        cin >> length;
    }

    int* count = new int[MAX_VALUE + 1];

    SetCountZero(count, MAX_VALUE);

    switch (choice) {
    case 1:
        InitializeArrayPersonally(count, length, MAX_VALUE);
        break;
    case 2:
        InitializeArrayRandomly(count, length, MAX_VALUE);
        break;
    }

    PrintOriginalArray(count, MAX_VALUE);
    PrintRepeatedAscedingly(count, MAX_VALUE);

    delete[] count;
    return 0;
}