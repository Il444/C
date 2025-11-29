#include <iostream>
#include "array_init.h"
#include "sorting.h"
#include <stdlib.h>
using namespace std;

int main()
{
    int choice  = 0;
    int length = 0;
    int count_srav = 0;
    int count_perem = 0;
    cout << "Enter the length of array: ";
    cin >> length;
    int* array = new int[length];
    cout << "How would you like to enter the array: " << endl;
    cout << "1. Ascending array " << endl;
    cout << "2. Descending array " << endl;
    cout << "3. Random" << endl;
    cin >> choice;

    enum InitArray {
        Ascending = 1,
        Descending,
        Random
    };

    switch (choice) {
    case(Ascending):
        ascending(array, length);
        break;
    case(Descending):
        descending(array, length);
        break;
    case(Random):
        random(array, length);
        break;
    }
   
    cout << "Here is our array: ";
    for (int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    cout << endl;

    count_srav = 0;
    count_perem = 0;

    int* array_copy = new int[length];
    for (int i = 0; i < length; i++) {
        array_copy[i] = array[i];
    }

    cout << "Array that was created by quick sort: ";
    quickSort(array, 0, length - 1, count_srav, count_perem);
    for (int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }

    cout << endl;
    cout << "The amount of comparasements during quick sort: " << count_srav << endl;
    cout << "The amount of movement during quick sort: " << count_perem << endl;

    count_srav = 0;
    count_perem = 0;

    cout << endl;
    cout << "Array that was created by binary sort: ";
    binarySort(array_copy, length, count_srav, count_perem);
    for (int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    cout << "The amount of comparasements during binary sort: " << count_srav << endl;
    cout << "The amount of movement during binary sort: " << count_perem << endl;


    delete[] array;
    return 0;
}