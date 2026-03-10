#include <iostream>
#include <ctime>
#include <cstdlib>
#include "lists.h"
using namespace std;

int List::sum() {
    int k = size;
    double sum = 0;
    Node* current1 = head;
    Node* current2 = tail;
    for (int i = 0; i < k / 2; i++) {
        sum += (current1->data) * (current2->data);
        current1 = current1->pNext;
        current2 = current2->pPrev;
    }
    return sum;
}

int main() {
    srand(time(NULL));
    int n;
    List L;
    cout << "Enter n = "; cin >> n;
    for (int i = 0; i < n; i++) {
        L.push_back(rand() % 10);
        L.push_front(rand() % 10);
    }
    L.printf();
    int result = L.sum();
    cout << result << endl;
    L.~List();
    return 0;
}