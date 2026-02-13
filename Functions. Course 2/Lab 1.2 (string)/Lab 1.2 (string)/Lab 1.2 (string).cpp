#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
using namespace std;

void SetTheArray(char* buffer, int size) {
    cout << "Enter your text: ";
    cin.getline(buffer, size);
}

int MarkWords(char* buffer, char array[][100], char* delim, int size) {
    int start = 0;
    int count = -1;
    int i = 0;
    int length = 0;
    bool startWithDelim = false;

    for (int j = 0; buffer[j] != '\0'; j++) {
        start = i;
        for (int k = 0; delim[k] != '\0'; k++) {
            if (buffer[j] == delim[k] && (j == 0 || buffer[j - 1] != delim[k])) {
                length = j - start;
                startWithDelim = false;
                for (int d = 0; delim[d] != '\0'; d++) {
                    if (buffer[start] == delim[d]) {
                        startWithDelim = true;
                        break;
                    }
                }
                if (length > 0 && !startWithDelim) {
                    count++;
                    for (int n = 0; n < length; n++) {
                        array[count][n] = buffer[start + n];
                    }
                    array[count][length] = '\0';
                }

                i = j + 1;
                break;
            }
        }
    }
    if (buffer[i] != '\0') {
        length = strlen(buffer) - i;

        startWithDelim = false;
        for (int d = 0; delim[d] != '\0'; d++) {
            if (buffer[start] == delim[d]) {
                startWithDelim = true;
                break;
            }
        }

        if (length > 0 && !startWithDelim) {
            count++;
            for (int n = 0; n < length; n++) {
                array[count][n] = buffer[i + n];
            }
            array[count][length] = '\0';
        }
    }
    return count;
}

void BubleSort(char array[][100], int count) {
    char temp[100];
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count - i; j++) {
            if (array[j][0] > array[j + 1][0]) {
                strcpy(temp, array[j]);
                strcpy(array[j], array[j + 1]);
                strcpy(array[j + 1], temp);
            }
        }
    }
}

void PrintTheArray(char array[][100], int count) {
    for (int i = 0; i <= count; i++) {
        cout << array[i] << " ";
    }
}

int main()
{
    int count = 0;
    char buffer[1000];
    char array[1000][100];
    char delim[] = " .,;!?-()";

    SetTheArray(buffer, 1000);
    count = MarkWords(buffer, array, delim, 100);
    BubleSort(array, count);
    PrintTheArray(array, count);
}