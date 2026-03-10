#pragma once
#include <iostream>
using namespace std;

class List {
public:
    List();
    ~List();
    void push_back(double data);
    void push_front(double data);
    double& operator[](int index);
    void printf();
    void del_tail();
    void del_head();
    void clear();
    int sum();
private:
    class Node {
    public:
        Node* pNext;
        Node* pPrev;
        double data;
        Node(double data, Node* pNext = nullptr, Node* pPrev = nullptr) {
            this->data = data;
            this->pNext = pNext;
            this->pPrev = pPrev;
        }
    };
    int size;
    Node* head;
    Node* tail;
};