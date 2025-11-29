#include <iostream>
using namespace std;

int main()
{
	int k, l, m, n;
	bool error = false;
	bool threat = false;

	cout << "Write down the Queen coordinates" << endl;
	cout << "Vertically: ";
	cin >> k;
	cout << "Horizontally: ";
	cin >> l;
	cout << "" << endl;
	cout << "Now do the same for your horse" << endl;
	cout << "Vertically: ";
	cin >> m;
	cout << "Horizontally: ";
	cin >> n;

	if ((k > 8 || k <= 0) || (l > 8 || l <= 0)) {
		cout << "Your queen is out of the board!" << endl;
		error = true;
	}
	if ((m > 8 || m <= 0) || (n > 8 || n <= 0)) {
		cout << "Your horse is out of the board!" << endl;
		error = true;
	}

	if (error) {
		return 1;
	}

	if ((k == m) || (l == n) || ((k == m + 1) && (l == n + 1)) || ((k == m + 2) && (l == n + 2)) || ((k == m + 3) && (l == n + 3)) || ((k == m + 4) && (l == n + 4)) || ((k == m + 5) && (l == n + 5)) || ((k == m + 6) && (l == n + 6)) || ((k == m + 7) && (l == n + 7)) || ((k == m + 8) && (l == n + 8)) || ((k == m - 1) && (l == n - 1)) || ((k == m - 2) && (l == n - 2)) || ((k == m - 3) && (l == n - 3)) || ((k == m - 4) && (l == n - 4)) || ((k == m - 5) && (l == n - 5)) || ((k == m - 6) && (l == n - 6)) || ((k == m - 7) && (l == n - 7)) || ((k == m - 8) && (l == n - 8)) || ((k == m - 1) && (l == n + 1)) || ((k == m - 2) && (l == n + 2)) || ((k == m - 3) && (l == n + 3)) || ((k == m - 4) && (l == n + 4)) || ((k == m - 5) && (l == n + 5)) || ((k == m - 6) && (l == n + 6)) || ((k == m - 7) && (l == n + 7)) || ((k == m - 8) && (l == n + 8)) || (((k == m + 1) && (l == n - 1)) || ((k == m + 2) && (l == n - 2)) || ((k == m + 3) && (l == n - 3)) || ((k == m + 4) && (l == n - 4)) || ((k == m + 5) && (l == n - 5)) || ((k == m + 6) && (l == n - 6)) || ((k == m + 7) && (l == n - 7)) || ((k == m + 8) && (l == n - 8)))) {
		threat = true;
		cout << "You can beat the horse!" << endl;
		return 1;
	}
	if ((m == k - 1) && (l == n - 2)) {
		threat = true;
		cout << "Your queen is under attack!" << endl;
		return 1;
	}
	if (((k == m - 1) && (l == n - 2)) || ((k == m + 1) && (l == n + 2)) || ((k == m + 2) && (l == n - 1)) || ((k == m - 2) && (l == n - 1)) || ((k == m - 2) && (l == n + 1)) || ((k == m - 1) && (l == n + 2)) || ((k == m + 1) && (l == n - 2)) || ((k == m + 2) && (l == n + 1))) {
		threat = true;
		cout << "Your queen is under attack!" << endl;
		return 1;
	}

	/*if (threat) {
		cout << "There is threat on the board!" << endl;
		return 1;
	}*/
	if (threat) {
		return 1;
	}
	if (!threat) {
		cout << "There is not any threat on the board" << endl;

		cout << "Queen can threat the horse" << endl;
		bool futureThreat = true;

		if ((m + 2 >= 1 && m + 2 <= 8 && n + 1 >= 1 && n + 1 <= 8) ||
			(m + 2 >= 1 && m + 2 <= 8 && n - 1 >= 1 && n - 1 <= 8) ||
			(m - 2 >= 1 && m - 2 <= 8 && n + 1 >= 1 && n + 1 <= 8) ||
			(m - 2 >= 1 && m - 2 <= 8 && n - 1 >= 1 && n - 1 <= 8) ||
			(m + 1 >= 1 && m + 1 <= 8 && n + 2 >= 1 && n + 2 <= 8) ||
			(m + 1 >= 1 && m + 1 <= 8 && n - 2 >= 1 && n - 2 <= 8) ||
			(m - 1 >= 1 && m - 1 <= 8 && n + 2 >= 1 && n + 2 <= 8) ||
			(m - 1 >= 1 && m - 1 <= 8 && n - 2 >= 1 && n - 2 <= 8)) {
			cout << "Horse can also create threat in one move!" << endl;
			futureThreat = true;
		}

		if (futureThreat) {
			cout << "Threat can be created in one move by one of the figures." << endl;
		}
		else {
			cout << "No possible moves to create threat in one turn." << endl;
		}

		return 0;
	}
}
