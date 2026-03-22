#include <ctime>
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;

int create(char* filename, long long count);
int find_common(char* f, char* g, char* result);

int main() {
    srand((unsigned)time(NULL));

    long long n;
    cout << "Enter number of elements in each file: ";
    cin >> n;

    char f[40] = "f.txt";
    char g[40] = "g.txt";
    char result[40] = "result.txt";

    create(f, n);
    create(g, n);

    find_common(f, g, result);

    return 0;
}

int create(char* filename, long long count) {
    ofstream outfile(filename);
    if (!outfile) {
        cout << "Error: cannot create file" << endl;
        return 1;
    }

    int current = 0;
    for (long long i = 0; i < count; i++) {
        current += rand() % 100 + 1;
        outfile << current << " ";
    }

    outfile.close();
    return 0;
}

int find_common(char* f, char* g, char* result) {
    ifstream file_f(f);
    if (!file_f) {
        cout << "Error: cannot open file f" << endl;
        return 1;
    }

    ifstream file_g(g);
    if (!file_g) {
        cout << "Error: cannot open file g" << endl;
        return 1;
    }

    ofstream outfile(result);
    if (!outfile) {
        cout << "Error: cannot create result file" << endl;
        return 1;
    }

    int val_f, val_g;
    bool found = false;

    file_f >> val_f;
    file_g >> val_g;

    while (!file_f.eof() && !file_g.eof()) {
        if (val_f == val_g) {
            outfile << val_f << " ";
            found = true;
            file_f >> val_f;
            file_g >> val_g;
        }
        else if (val_f < val_g) {
            file_f >> val_f;
        }
        else {
            file_g >> val_g;
        }
    }

    if (!found) {
        outfile << "none";
    }

    cout << "Common numbers saved to result.txt" << endl;

    file_f.close();
    file_g.close();
    outfile.close();
    return 0;
}