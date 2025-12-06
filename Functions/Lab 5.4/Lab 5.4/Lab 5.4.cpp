#include <iostream>
using namespace std;

void Init(int& length, char* S) {
    cin.ignore();
    cin.getline(S, length + 1);
}

void output(char* S) {
    cout << S;
}

void shiftRight(int pos, char* S, int& length, int way) {
    if (way == 1) {
        length += 2;
        for (int i = length; i >= pos; i--) {
            S[i + 2] = S[i];
        }
    }
    if (way == 2) {
        length += 1;
        for (int i = length; i >= pos; i--) {
            S[i + 1] = S[i];
        }
    }
}

void replacement(int pos, char* S, int& length, int way) {
    shiftRight(pos, S, length, way);
    if (way == 1) {
        for (int i = (pos + 1); i > pos; i--) {
            S[i] = S[i - 2];
        }
    }
    if (way == 2) {
        for (int i = (pos + 1); i > pos; i--) {
            S[i] = S[i - 1];
        }
    }
}

void places_to_replace(int& length, char* S, int& left, int& _length) {
    int pos = 0;
    int way = 0;
    left -= 1;
    if (left < 0) left = 0;
    if (_length > length) _length = length;
    if (left >= _length) return;
    for (int i = left; i < _length;) {
        if (i + 2 >= _length) break;
        if (S[i] == S[i + 1] && S[i] == S[i + 2] && S[i] != S[i + 3]) {
            way = 1;
            pos = i + 2;
            replacement(pos, S, length, way);
            i += 5;
        }
        else if (S[i] == S[i + 1] && S[i] == S[i + 2] && S[i] == S[i + 3] && S[i] != S[i + 4]) {
            way = 2;
            pos = i + 3;
            replacement(pos, S, length, way);
            i += 5;
        }
        else if (S[i] == S[i + 1] && S[i] == S[i + 2] && S[i] == S[i + 3] && S[i] == S[i + 4]) {
            i += 5;
        }
        else {
            i++;
        }
    }
}

void Input(int& length, char* S) {
    int left = 0;
    int _length = 0;
    cout << "Enter the number of first element of the sentence you want to replace: ";
    cin >> left;
    cout << "Enter the length of the sentence which you wanna replace: ";
    cin >> _length;
    cout << endl;
    places_to_replace(length, S, left, _length);
}

int main()
{
    int left = 0;
    int choice = 0;
    int length = 0;
    enum InitCh {
        First = 1,
        Second
    };
    cout << "Enter the length of the sentence: ";
    cin >> length;
    char* S = new char[length * 2 + 1];

    cout << "Enter the senstence: ";
    Init(length, S);
    cout << "The sentence: ";
    output(S);

    cout << endl;
    cout << "Would you like to modify all sentence(1) or only part of it(2): ";
    cin >> choice;
    switch (choice) {
        case(First):
            cout << endl;
            places_to_replace(length, S, left, length);
            break;
        case(Second):
            cout << endl;
            cin.ignore();
            Input(length, S);
            break;
    }

    cout << "Modified sentence: ";
    output(S);

    delete[]S;
    return 0;
}
