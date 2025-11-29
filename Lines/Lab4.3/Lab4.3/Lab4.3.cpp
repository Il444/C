#include <iostream>
using namespace std;

int main()
{
    int length = 0;
    int count = 0;
    int count_unique = 0;
    int count_repeated = 0;
    int word_start = 0;
    int word_end = 0;
    int pov_index = 0;
    bool unique = true;
    bool is_delim = false;
    cout << "Enter the length of the line:";
    cin >> length;
    char* str = new char[length + 1];
    char* pov_str = new char[length + 1];
    char delim[] = " .,!():;?-";

    cout << "Enter the line: ";
    cin.ignore();
    cin.getline(str, length + 1);

    for (int i = 0; i < length; i++) {
        if (str[i] == '\0') break;
    }

    for (int i = 0; i < length; i++) {
        if (str[i] == '\0') break;

        is_delim = false;
        for (int j = 0; delim[j] != '\0'; j++) {
            if (str[i] == delim[j]) {
                is_delim = true;
                break;
            }
        }

        if (is_delim) continue;

        count = 0;
        count_repeated = 0;
        word_start = i;
        word_end = i;

        while (word_end < length && str[word_end] != '\0') {
            bool is_current_delim = false;
            for (int j = 0; delim[j] != '\0'; j++) {
                if (str[word_end] == delim[j]) {
                    is_current_delim = true;
                    break;
                }
            }
            if (is_current_delim) break;
            word_end++;
        }

        for (int j = word_start; j < word_end; j++) {
            unique = true;
            for (int k = word_start; k < j; k++) {
                if (str[j] == str[k]) {
                    unique = false;
                    break;
                }
            }

            if (unique) {
                count++;
                bool has_duplicate = false;
                for (int k = j + 1; k < word_end; k++) {
                    if (str[j] == str[k]) {
                        has_duplicate = true;
                        break;
                    }
                }
                if (has_duplicate) {
                    count_repeated++;
                }
            }
        }

        count_unique = count - count_repeated;

        if (count_repeated > count_unique) {
            for (int j = word_start; j < word_end; j++) {
                pov_str[pov_index++] = str[j];
            }
            pov_str[pov_index++] = ' ';
        }

        i = word_end - 1;
    }

    if (pov_index > 0) {
        pov_str[pov_index - 1] = '\0';
        cout << "Here are words which contain more repeated letters than uniques: ";
        cout << pov_str;
    }
    else {
        cout << "No such words found";
    }

    return 0;
}