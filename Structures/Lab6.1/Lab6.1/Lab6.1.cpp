#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct Student {
    char name[50];
    int age;
    int course;
    int group;
    int soc_group;
    char gender;
    double gpa;
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
    s.gpa = rand() % 10; 
}

void InitRandom(Student arr[], int& size) {
    cout << "How many students would you like to get? ";
    cin >> size;
    if (size <= 0) {
        cout << "Invalid number!" << endl;
    }
    for (int i = 0; i < size; i++) {
        initRandomSt(arr[i]);
    }
}

void inputStudent(Student &s) {
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

void Init(Student arr[], int &size) {
    cout << "What amout of student would you like to input?";
    cin >> size;
    for (int i = 0; i < size; i++) {
        cout << "Student " << i + 1 << endl;
        inputStudent(arr[i]);
    }
}

void outputStudent(const Student &s) {
    cout << "Name: " << s.name << endl;
    cout << "Age: " << s.age << endl;
    cout << "Course: " << s.course << endl;
    cout << "Gender: " << s.gender << endl;
    cout << "GPA: " << s.gpa << endl;
    cout << endl;
}

void Output(const Student arr[], int size) {
    if (size == 0) {
        cout << "The array is empty";
        return;
    }
    for (int i = 0; i < size; i++) {
        cout << "Student " << i + 1 << endl;
        outputStudent(arr[i]);
    }
}

void searchForBadSt(const Student arr[], int size, int& target) {
    int count = 0;
    const double min_gpa = 4.0;
    cout << "Bad students from " << target << " course:" << endl;
    for (int i = 0; i < size; i++) {
        if (arr[i].course == target && arr[i].gpa < min_gpa) {
            count++;
            cout << count << ". " << arr[i].name << " GPA is " << arr[i].gpa << endl;
        }
    }

    if (count == 0) {
        cout << "There are no bad students from " << target << "  course." <<  endl;
    }
    else {
        cout << "The amount of bad students is: " << count << endl;
    }
}

void Search(const Student arr[], int size) {
    int target = 0;
    if (size == 0) {
        cout << "First enter your studetns" << endl;
    }
    cout << "Enter the course: ";
    cin >> target;
    if (target >= 1 && target <= 4) {
        searchForBadSt(arr, size, target);
    }
    else{
        cout << "Invalid course!" << endl;
    }
}

int main()
{

    int choice = 0;
    const int maxsize = 100;
    int size = 0;
    Student students[maxsize];

    enum Initw {
        In = 1,
        Out,
        Find,
        Random
    };

    do {
        cout << "MENU" << endl;
        cout << "Choose what you want to do: " << endl;
        cout << "1. Init the array" << endl;
        cout << "2. Output the array" << endl;
        cout << "3. Search for the bad student" << endl;
        cout << "4. Generate randomly" << endl;
        cin >> choice;

        switch (choice) {
        case(In):
            Init(students, size);
            break;
        case(Out):
            Output(students, size);
            break;
        case(Find):
            Search(students, size);
            break;
        case(Random):
            InitRandom(students, size);
            break;

        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);
    return 0;
}