#include "lists.h"

List::List() {
    size = 0;
    head = nullptr;
    tail = nullptr;
}

List::~List() {
    clear();
}

void List::push_back(double data) {
    Node* current = new Node(data);

    if (!head) {
        head = tail = current;
    }
    else {
        tail->pNext = current;
        current->pPrev = tail;
        tail = current;
    }
    size++;
}

void List::push_front(double data) {
    Node* current = new Node(data);

    if (!head) {
        head = tail = current;
    }
    else {
        current->pNext = head;
        head->pPrev = current;
        head = current;
    }
    size++;
}

double& List::operator[](int index) {
    if (index < size / 2) {
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->pNext;
        }
        return current->data;
    }
    else {
        Node* current = tail;
        for (int i = 0; i < size - index - 1; i++) {
            current = current->pPrev;
        }
        return current->data;
    }
}

void List::printf() {
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->pNext;
    }
    cout << endl;
}

void List::del_head() {
    Node* temp = head;
    head = head->pNext;
    if (head) head->pPrev = nullptr;
    delete temp;
    size--;
}

void List::del_tail() {
    Node* temp = tail;
    tail = tail->pPrev;
    if (tail) tail->pNext = nullptr;
    delete temp;
    size--;
}

void List::clear() {
    while (head) {
        del_head();
    }
}