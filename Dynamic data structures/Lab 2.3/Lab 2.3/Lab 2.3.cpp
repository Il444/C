#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct Student {
    char name[50];
    int age;
    int course;
    char gender;
    double gpa;
};

struct Node {
    Student data;
    Node* next;
};

void namesGenerate(char* name) {
    const char* firstNames[] = { "John", "Emma", "Michael", "Sophia", "William", "Olivia", "James", "Ava", "Robert", "Isabella" };
    const char* lastNames[] = { "Smith", "Johnson", "Williams", "Brown", "Jones", "Miller", "Davis", "Garcia", "Rodriguez", "Wilson" };
    int index1 = rand() % 10;
    int index2 = rand() % 10;
    strcpy_s(name, 50, firstNames[index1]);
    strcat_s(name, 50, " ");
    strcat_s(name, 50, lastNames[index2]);
}

void initRandomSt(Student& s) {
    int luck = rand() % 10;
    namesGenerate(s.name);
    if (luck == 0) {
        s.age = rand() % 60;
    }
    else {
        s.age = 18 + rand() % 7;
    }
    s.course = 1 + rand() % 4;
    s.gender = (rand() % 2 == 0) ? 'M' : 'F';
    s.gpa = (rand() % 100) / 10.0;
}

Node* addSorted(Node* head, const Student& s) {
    Node* newNode = new Node;
    newNode->data = s;
    newNode->next = nullptr;
    if (head == nullptr || strcmp(s.name, head->data.name) < 0) {
        newNode->next = head;
        return newNode;
    }
    Node* current = head;
    while (current->next != nullptr && strcmp(s.name, current->next->data.name) > 0) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

Node* InitRandom(Node* head) {
    int size;
    cout << "How many students would you like to get? ";
    cin >> size;
    if (size <= 0) {
        cout << "Invalid number!" << endl;
        return head;
    }
    for (int i = 0; i < size; i++) {
        Student s;
        initRandomSt(s);
        head = addSorted(head, s);
    }
    return head;
}

void inputStudent(Student& s) {
    cout << "Enter the name of the student: ";
    cin.ignore();
    cin.getline(s.name, 50);
    cout << "Enter the age of the student: ";
    cin >> s.age;
    cout << "Enter the course of the student: ";
    cin >> s.course;
    cout << "Enter the gender of the student: ";
    cin >> s.gender;
    cout << "Enter the gpa of the student: ";
    cin >> s.gpa;
}

Node* Init(Node* head) {
    int size;
    cout << "What amount of students would you like to input? ";
    cin >> size;
    for (int i = 0; i < size; i++) {
        cout << "Student " << i + 1 << endl;
        Student s;
        inputStudent(s);
        head = addSorted(head, s);
    }
    return head;
}

void outputStudent(const Student& s) {
    cout << "Name: " << s.name << endl;
    cout << "Age: " << s.age << endl;
    cout << "Course: " << s.course << endl;
    cout << "Gender: " << s.gender << endl;
    cout << "GPA: " << s.gpa << endl;
    cout << endl;
}

void PrintList(Node* head) {
    if (head == nullptr) {
        cout << "The list is empty" << endl;
        return;
    }
    int i = 1;
    while (head != nullptr) {
        cout << "Student " << i++ << endl;
        outputStudent(head->data);
        head = head->next;
    }
}

void splitByPerformance(Node*& src, Node*& dest, double threshold) {
    Node* prev = nullptr;
    Node* current = src;
    while (current != nullptr) {
        if (current->data.gpa < threshold) {
            if (prev == nullptr) {
                src = current->next;
            }
            else {
                prev->next = current->next;
            }
            Node* temp = current->next;
            current->next = nullptr;
            if (dest == nullptr) {
                dest = current;
            }
            else {
                Node* last = dest;
                while (last->next != nullptr) last = last->next;
                last->next = current;
            }
            current = temp;
        }
        else {
            prev = current;
            current = current->next;
        }
    }
}

void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    int choice = 0;
    Node* head = nullptr;
    Node* badHead = nullptr;

    do {
        cout << "MENU" << endl;
        cout << "1. Init list manually" << endl;
        cout << "2. Print list" << endl;
        cout << "3. Split by performance (threshold = 4.0)" << endl;
        cout << "4. Generate randomly" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
        case 1:
            head = Init(head);
            break;
        case 2:
            cout << "\nGood students:" << endl;
            PrintList(head);
            if (badHead != nullptr) {
                cout << "\nBad students:" << endl;
                PrintList(badHead);
            }
            break;
        case 3:
            splitByPerformance(head, badHead, 4.0);
            cout << "Split completed!" << endl;
            break;
        case 4:
            head = InitRandom(head);
            break;
        case 0:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);

    deleteList(head);
    deleteList(badHead);

    return 0;
}