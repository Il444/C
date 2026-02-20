#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
using namespace std;

void SetTheArray(string& text) {
    cout << "Enter your text: ";
    getline(cin, text);
}

string* MarkWords(const string& text, const string& delim, int& wordCount) {
    string* words = new string[text.length()];
    string word = "";
    int start = 0;
    int i = 0;
    int length = 0;
    bool startWithDelim = false;
    wordCount = 0;

    for (int j = 0; j < text.length(); j++) {
        start = i;
        for (int k = 0; delim[k] != '\0'; k++) {
            if (text[j] == delim[k] && (j == 0 || text[j - 1] != delim[k])) {
                length = j - start;
                startWithDelim = false;
                for (int d = 0; delim[d] != '\0'; d++) {
                    if (text[start] == delim[d]) {
                        startWithDelim = true;
                        break;
                    }
                }
                if (length > 0 && !startWithDelim) {
                    word = text.substr(start, length);
                    words[wordCount] = word;
                    wordCount++;
                }

                i = j + 1;
                break;
            }
        }
    }
    if (text[i] != '\0') {
        length = text.length() - i;

        startWithDelim = false;
        for (int d = 0; delim[d] != '\0'; d++) {
            if (text[i] == delim[d]) {
                startWithDelim = true;
                break;
            }
        }

        if (length > 0 && !startWithDelim) {
            word = text.substr(start, length);
            words[wordCount] = word;
            wordCount++;
        }
    }
    return words;
}

void BubleSort(string* words, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (words[j][0] > words[j + 1][0]) {
                swap(words[j], words[j + 1]);
            }
        }
    }
}

void PrintTheArray(string* words, int size) {
    for (int i = 0; i < size; i++) {
        cout << words[i] << " ";
    }
}

int main()
{
    string text;
    string* words = nullptr;
    string delim = " .,;!?-()";
    int wordCount = 0;

    SetTheArray(text);
    words = MarkWords(text, delim, wordCount);
    BubleSort(words, wordCount);
    PrintTheArray(words, wordCount);

    delete[] words;

    return 0;
}