#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

struct Student {
    char name[50];
    int age;
    int course;
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
    namesGenerate(s.name);
    s.age = 18 + rand() % 7;
    s.course = 1 + rand() % 4;
    s.gender = (rand() % 2 == 0) ? 'M' : 'F';
    s.gpa = (rand() % 100) / 10.0;
}

int createFile(char* filename, int count) {
    ofstream outfile(filename, ios::binary);
    if (!outfile) {
        cout << "Error: cannot create file" << endl;
        return 1;
    }
    for (int i = 0; i < count; i++) {
        Student s;
        initRandomSt(s);
        outfile.write(reinterpret_cast<char*>(&s), sizeof(Student));
    }
    outfile.close();
    cout << "Created " << count << " students in " << filename << endl;
    return 0;
}

void printFile(char* filename) {
    ifstream infile(filename, ios::binary);
    if (!infile) {
        cout << "Error: cannot open file" << endl;
        return;
    }
    Student s;
    int i = 1;
    infile.read(reinterpret_cast<char*>(&s), sizeof(Student));
    while (!infile.eof()) {
        cout << "Student " << i++ << endl;
        cout << "Name: " << s.name << endl;
        cout << "Age: " << s.age << endl;
        cout << "Course: " << s.course << endl;
        cout << "Gender: " << s.gender << endl;
        cout << "GPA: " << s.gpa << endl;
        cout << endl;
        infile.read(reinterpret_cast<char*>(&s), sizeof(Student));
    }
    infile.close();
}

int findBadStudents(char* inputFile, char* outputFile, double threshold) {
    ifstream infile(inputFile, ios::binary);
    if (!infile) {
        cout << "Error: cannot open input file" << endl;
        return 1;
    }
    ofstream outfile(outputFile, ios::binary);
    if (!outfile) {
        cout << "Error: cannot create output file" << endl;
        return 1;
    }
    Student s;
    int badCount = 0;
    infile.read(reinterpret_cast<char*>(&s), sizeof(Student));
    while (!infile.eof()) {
        if (s.gpa < threshold) {
            outfile.write(reinterpret_cast<char*>(&s), sizeof(Student));
            badCount++;
        }
        infile.read(reinterpret_cast<char*>(&s), sizeof(Student));
    }
    infile.close();
    outfile.close();
    cout << "Found " << badCount << " bad students (GPA < " << threshold << ")" << endl;
    return 0;
}

int main() {
    srand((unsigned)time(NULL));
    int choice;
    char filename[40] = "students.dat";
    char badFilename[40] = "bad_students.dat";
    int count;
    do {
        cout << "MENU" << endl;
        cout << "1. Create file with random students" << endl;
        cout << "2. Print file" << endl;
        cout << "3. Find bad students (GPA < 4.0)" << endl;
        cout << "4. Print bad students file" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "How many students? ";
            cin >> count;
            createFile(filename, count);
            break;
        case 2:
            cout << "\nAll students:" << endl;
            printFile(filename);
            break;
        case 3:
            findBadStudents(filename, badFilename, 4.0);
            break;
        case 4:
            cout << "\nBad students:" << endl;
            printFile(badFilename);
            break;
        case 0:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);
    return 0;
}