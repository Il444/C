#include <ctime>
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;

int create(char* filename, long long count);
void read_file(char* filename);
int find_common(char* f, char* g);

int main() {
    srand((unsigned)time(NULL));

    long long n;
    cout << "Enter number of elements in each file: ";
    cin >> n;

    char f[40] = "f.dat";
    char g[40] = "g.dat";

    create(f, n);
    create(g, n);

    cout << "File f: ";
    read_file(f);

    cout << "File g: ";
    read_file(g);

    cout << "Common numbers: ";
    find_common(f, g);

    return 0;
}

int create(char* filename, long long count) {
    ofstream outfile(filename, ios::binary);
    if (!outfile) {
        cout << "Error: cannot create file" << endl;
        return 1;
    }

    int current = 0;
    for (long long i = 0; i < count; i++) {
        current += rand() % 100 + 1;
        outfile.write(reinterpret_cast<char*>(&current), sizeof(int));
    }

    outfile.close();
    return 0;
}

void read_file(char* filename) {
    ifstream infile(filename, ios::binary);
    if (!infile) {
        cout << "Error: cannot open file" << endl;
        return;
    }

    int v;
    int count = 0;
    infile.read(reinterpret_cast<char*>(&v), sizeof(int));
    while (!infile.eof() && count < 20) {
        cout << v << " ";
        count++;
        infile.read(reinterpret_cast<char*>(&v), sizeof(int));
    }
    cout << endl;

    infile.close();
}

int find_common(char* f, char* g) {
    ifstream file_f(f, ios::binary);
    if (!file_f) {
        cout << "Error: cannot open file f" << endl;
        return 1;
    }

    ifstream file_g(g, ios::binary);
    if (!file_g) {
        cout << "Error: cannot open file g" << endl;
        return 1;
    }

    int val_f, val_g;
    bool found = false;

    file_f.read(reinterpret_cast<char*>(&val_f), sizeof(int));
    file_g.read(reinterpret_cast<char*>(&val_g), sizeof(int));

    while (!file_f.eof() && !file_g.eof()) {
        if (val_f == val_g) {
            cout << val_f << " ";
            found = true;
            file_f.read(reinterpret_cast<char*>(&val_f), sizeof(int));
            file_g.read(reinterpret_cast<char*>(&val_g), sizeof(int));
        }
        else if (val_f < val_g) {
            file_f.read(reinterpret_cast<char*>(&val_f), sizeof(int));
        }
        else {
            file_g.read(reinterpret_cast<char*>(&val_g), sizeof(int));
        }
    }

    if (!found) {
        cout << "none";
    }
    cout << endl;

    file_f.close();
    file_g.close();
    return 0;
}