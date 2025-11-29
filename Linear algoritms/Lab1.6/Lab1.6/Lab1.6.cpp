#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    unsigned int n;

    cout << "Write down your numder: ";
    cin >> n;

    int bit15 = (n >> 15) & 1;
    int bit7 = (n >> 7) & 1;

    cout << "Number: " << bitset<32>(n) << endl;
    cout << "Zero bit: " << bitset<1>(n) << endl;
    cout << "Fifteinth bit: " << bit15  << endl;

    unsigned int mask = (1 << 7) | (1 << 15);
    unsigned int n_inverted = n ^ mask;

    cout << "Inverted seventh bit: " << ((n_inverted >> 7) & 1) << endl;
    cout << "Inverted fifteinth bit: " << ((n_inverted >> 15) & 1) << endl;
    cout << "Inverted bits: " << bitset<32>(n_inverted) << " = " << n_inverted << endl;
}