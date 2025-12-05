#include <iostream>
using namespace std;

void Init(int length, char* S) {
    cin.ignore();
    cin.getline(S, length + 1);
}

void output(char* S) {
     cout << S;
}

void replacement(int right, char* S, int* length) {
    for (int i = right; i < (right + 2); i++) {
        S[i] = S_;
    }
}

int places_to_replace(int* length, char* S) {
    int left = 0;
    int right = 0;
    char S_;
    int count = 0;
    for (int i = 0; i < (*length); i++) {
        if (S[i] == S[i + 1] || S[i] == S[i + 2]) {
            left = i;
            right = i + 2;
            S_ = S[i];
          //  replacement(left, right, S, length);
            i += 4;
            count++;
        }
    }
    return count;
}

void shiftRight(int right, char* S, int* length) {
    int count = places_to_replace(length, S);
    (*length) += 2;
    for (int i = (*length); i >= right; i--) {
        S[i + 2] = S[i];
    }
}

int main()
{
    int length = 0;
    int new_length = length;
    cout << "Enter the length of the sentence: ";
    cin >> length;
    char* S = new char[length * 2 + 1];

    cout << "Enter the senstence: ";
    Init(length, S);
    output(S);

    shiftRight(S, &length);
    output(S);

    for (int i = 0; i < new_length - 2; i++) {
        if (S[i] == S[i + 1] || S[i] == S[i + 2]) {
            shiftRight(i + 3, )
            //  replacement(left, right, S, length);
            i += 4;
            count++;
        }
    }
    return count;
}

    delete[]S;
    return 0;
}
