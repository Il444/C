#include <iostream>
using namespace std;

const int SIZE = 100;

struct List {
    char data[SIZE];
    int next[SIZE];
    int head;
    int freeHead;
};

void initializeList(List& L) {
    for (int i = 0; i < SIZE - 1; i++) {
        L.next[i] = i + 1;
    }
    L.next[SIZE - 1] = -1;
    L.head = -1;
    L.freeHead = 0;
}

int getFreeIndex(List& L) {
    int index;
    index = L.freeHead;
    if (index == -1) {
        return -1;
    }
    L.freeHead = L.next[index];
    return index;
}

void releaseIndex(List& L, int index) {
    L.next[index] = L.freeHead;
    L.freeHead = index;
}

void addToBeginning(List& L, char value) {
    int newIndex;
    newIndex = getFreeIndex(L);
    if (newIndex == -1) {
        cout << "List is full" << endl;
        return;
    }
    L.data[newIndex] = value;
    L.next[newIndex] = L.head;
    L.head = newIndex;
    cout << "Added " << value << " at beginning" << endl;
}

void addToEnd(List& L, char value) {
    int newIndex;
    int current;
    newIndex = getFreeIndex(L);
    if (newIndex == -1) {
        cout << "List is full" << endl;
        return;
    }
    L.data[newIndex] = value;
    L.next[newIndex] = -1;
    if (L.head == -1) {
        L.head = newIndex;
    }
    else {
        current = L.head;
        while (L.next[current] != -1) {
            current = L.next[current];
        }
        L.next[current] = newIndex;
    }
    cout << "Added " << value << " at end" << endl;
}

void printList(List& L) {
    int current;
    if (L.head == -1) {
        cout << "List is empty" << endl;
        return;
    }
    cout << "List: ";
    current = L.head;
    while (current != -1) {
        cout << L.data[current] << " ";
        current = L.next[current];
    }
    cout << endl;
}

int findElement(List& L, char value) {
    int current;
    int position;
    current = L.head;
    position = 0;
    while (current != -1) {
        if (L.data[current] == value) {
            cout << "Found " << value << " at position " << position << endl;
            return current;
        }
        current = L.next[current];
        position++;
    }
    cout << "Element " << value << " not found" << endl;
    return -1;
}

void insertAfter(List& L, char afterValue, char newValue) {
    int position;
    int newIndex;
    position = findElement(L, afterValue);
    if (position == -1) {
        return;
    }
    newIndex = getFreeIndex(L);
    if (newIndex == -1) {
        cout << "List is full" << endl;
        return;
    }
    L.data[newIndex] = newValue;
    L.next[newIndex] = L.next[position];
    L.next[position] = newIndex;
    cout << "Inserted " << newValue << " after " << afterValue << endl;
}

void deleteElement(List& L, char value) {
    int current;
    int previous;
    current = L.head;
    previous = -1;
    while (current != -1) {
        if (L.data[current] == value) {
            if (previous == -1) {
                L.head = L.next[current];
            }
            else {
                L.next[previous] = L.next[current];
            }
            releaseIndex(L, current);
            cout << "Deleted " << value << endl;
            return;
        }
        previous = current;
        current = L.next[current];
    }
    cout << "Element " << value << " not found" << endl;
}

int countElements(List& L) {
    int count;
    int current;
    count = 0;
    current = L.head;
    while (current != -1) {
        count++;
        current = L.next[current];
    }
    cout << "Number of elements: " << count << endl;
    return count;
}

void logic(List& L1, List& L2, List& L) {
    int current;
    int temp;
    char c;
    bool inL2;
    bool alreadyInL;

    current = L1.head;
    while (current != -1) {
        c = L1.data[current];

        inL2 = false;
        temp = L2.head;
        while (temp != -1) {
            if (L2.data[temp] == c) {
                inL2 = true;
                break;
            }
            temp = L2.next[temp];
        }

        if (inL2 == false) {
            alreadyInL = false;
            temp = L.head;
            while (temp != -1) {
                if (L.data[temp] == c) {
                    alreadyInL = true;
                    break;
                }
                temp = L.next[temp];
            }

            if (alreadyInL == false) {
                addToEnd(L, c);
            }
        }

        current = L1.next[current];
    }
}

void inputList(List& L, const char* listName) {
    int n;
    int i;
    char c;
    cout << "How many symbols in " << listName << "? ";
    cin >> n;
    cout << "Enter " << n << " symbols: ";
    for (i = 0; i < n; i++) {
        cin >> c;
        addToEnd(L, c);
    }
}

int main() {
    List L1;
    List L2;
    List L;
    int choice;
    char val;
    char after;

    initializeList(L1);
    initializeList(L2);
    initializeList(L);

    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Add to beginning" << endl;
        cout << "2. Add to end" << endl;
        cout << "3. Print list L1" << endl;
        cout << "4. Print list L2" << endl;
        cout << "5. Print list L" << endl;
        cout << "6. Find element in L1" << endl;
        cout << "7. Insert after element in L1" << endl;
        cout << "8. Delete element from L1" << endl;
        cout << "9. Count elements in L1" << endl;
        cout << "10. Input L1 manually" << endl;
        cout << "11. Input L2 manually" << endl;
        cout << "12. Run 2.4 (L from L1 not in L2)" << endl;
        cout << "0. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter character: ";
            cin >> val;
            addToBeginning(L1, val);
            break;
        case 2:
            cout << "Enter character: ";
            cin >> val;
            addToEnd(L1, val);
            break;
        case 3:
            cout << "L1: ";
            printList(L1);
            break;
        case 4:
            cout << "L2: ";
            printList(L2);
            break;
        case 5:
            cout << "L: ";
            printList(L);
            break;
        case 6:
            cout << "Enter character to find in L1: ";
            cin >> val;
            findElement(L1, val);
            break;
        case 7:
            cout << "Enter character to insert after: ";
            cin >> after;
            cout << "Enter character to insert: ";
            cin >> val;
            insertAfter(L1, after, val);
            break;
        case 8:
            cout << "Enter character to delete from L1: ";
            cin >> val;
            deleteElement(L1, val);
            break;
        case 9:
            countElements(L1);
            break;
        case 10:
            inputList(L1, "L1");
            break;
        case 11:
            inputList(L2, "L2");
            break;
        case 12:
            logic(L1, L2, L);
            cout << "Result L created from L1 elements not in L2" << endl;
            break;
        case 0:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 0);

    return 0;
}