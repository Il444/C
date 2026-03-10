#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

void add(Node*& head, char c) {
    Node* newNode = new Node;
    newNode->data = c;
    newNode->next = head;
    head = newNode;
}

void addToEnd(Node*& head, char c) {
    Node* newNode = new Node;
    newNode->data = c;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

void print(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void inputList(Node*& head) {
    int n;
    char c;
    cout << "How many symbols? ";
    cin >> n;
    cout << "Enter symbols: ";
    for (int i = 0; i < n; i++) {
        c;
        cin >> c;
        addToEnd(head, c);
    }
}

void zadanie8(Node* L1, Node* L2, Node*& L) {
    Node* current = L1;
    char c;
    bool inL2 = false;
    bool already = false;
    while (current != nullptr) {
        c = current->data;

        inL2 = false;
        Node* temp = L2;
        while (temp != nullptr) {
            if (temp->data == c) {
                inL2 = true;
                break;
            }
            temp = temp->next;
        }

        if (!inL2) {
            already = false;
            temp = L;
            while (temp != nullptr) {
                if (temp->data == c) {
                    already = true;
                    break;
                }
                temp = temp->next;
            }

            if (!already) {
                addToEnd(L, c);
            }
        }

        current = current->next;
    }
}

void del(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* L1 = nullptr;
    Node* L2 = nullptr;
    Node* L = nullptr;

    cout << "Enter first list L1:" << endl;
    inputList(L1);
    cout << "Enter second list L2:" << endl;
    inputList(L2);

    cout << "L1: ";
    print(L1);
    cout << "L2: ";
    print(L2);

    zadanie8(L1, L2, L);

    cout << "Result L: ";
    print(L);

    del(L1);
    del(L2);
    del(L);

    return 0;
}