#include <iostream>
using namespace std;

int main()
{
    int count = 0;
    int N = 0;
    int newsize = 0;

    cout << "Enter the length of a string: ";
    cin >> N;

    char* s = new char[N + 1];

    cout << "Enter a string: ";
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }

    s[N] = '\0';

    cout << "You entered: ";
    for (int i = 0; i < N; i++) {
        cout << s[i] << " ";;
    }

    cout << endl;
    for (int i = 0; i < N; i++) {
        if (s[i] == 0) {
            continue;
        }
        count = 0;
        for (int j = 0; j < N; j++) {
            if (s[i] == s[j]) {
                count++;
                if (count > 1) {
                    s[j] = 0;
                }
            }
        }
        if (s[i] != 0) {
            cout << "Symbol " << s[i] << " was reapeted " << count << " times" << endl;
        }
        if (count > 1) {
            s[i] = 0;
        }
    }

    for (int i = 0; i < N; i++) {
        if (s[i] != 0) {
            s[newsize] = s[i];
            newsize++;
        }
    }

    s[newsize] = '\0';

    for (int i = 0; i < newsize; i++) {
        cout << s[i] << " ";
    }
    while (true)
    {

    }
}