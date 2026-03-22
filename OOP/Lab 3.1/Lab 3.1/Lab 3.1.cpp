#include <fstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

void merge_sort(double* arr, int n) {
    for (int size = 1; size < n; size = size * 2) {
        for (int left = 0; left < n - size; left += size * 2) {
            int mid = left + size - 1;
            int right = min(left + size * 2 - 1, n - 1);

            int n1 = mid - left + 1;
            int n2 = right - mid;

            double* L = new double[n1];
            double* R = new double[n2];

            for (int i = 0; i < n1; i++) L[i] = arr[left + i];
            for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

            int i = 0, j = 0, k = left;
            while (i < n1 && j < n2) {
                if (L[i] <= R[j]) arr[k++] = L[i++];
                else arr[k++] = R[j++];
            }
            while (i < n1) arr[k++] = L[i++];
            while (j < n2) arr[k++] = R[j++];

            delete[] L;
            delete[] R;
        }
    }
}

void find_common(const char* file1, const char* file2, const char* result) {
    ifstream f(file1);
    ifstream g(file2);
    ofstream out(result);

    if (!f.is_open() || !g.is_open() || !out.is_open()) {
        cout << "File error" << endl;
        return;
    }

    double a, b;
    f >> a;
    g >> b;

    while (f && g) {
        if (fabs(a - b) < 1e-9) {
            out << a << " ";

            double current = a;

            while (f && fabs(a - current) < 1e-9) {
                f >> a;
            }

            while (g && fabs(b - current) < 1e-9) {
                g >> b;
            }
        }
        else if (a < b) {
            f >> a;
        }
        else {
            g >> b;
        }
    }

    f.close();
    g.close();
    out.close();
}

int main() {
    srand(time(0));

    const int n = 300;
    double f_arr[n];
    double g_arr[n];

    ofstream f_out("f.txt");
    ofstream g_out("g.txt");

    for (int i = 0; i < n; i++) {
        f_arr[i] = rand() % 1000;
        g_arr[i] = rand() % 1000;
    }

    merge_sort(f_arr, n);
    merge_sort(g_arr, n);

    for (int i = 0; i < n; i++) {
        f_out << f_arr[i] << " ";
        g_out << g_arr[i] << " ";
    }

    f_out.close();
    g_out.close();

    find_common("f.txt", "g.txt", "result.txt");
    cout << "Done" << endl;
    return 0;
}