#include <iostream>
using namespace std;

int n, white, blue;

// Divide and Conquer
void Check(int x, int y, int n, bool** arr) {
	int cnt = 0;

	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (arr[i][j] == true) {
				cnt++;
			}
		}
	}

	if (cnt == 0) white++;
	else if (cnt == n * n) blue++;
	// recursion
	else {
		Check(x, y, n / 2, arr);
		Check(x, y + n / 2, n / 2, arr);
		Check(x + n / 2, y, n / 2, arr);
		Check(x + n / 2, y + n / 2, n / 2, arr);
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	// make array of 2 dimension
	bool** paper = new bool* [n];
	
	for (int i = 0; i < n; i++) {
		paper[i] = new bool[n];
	}

	// input
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}

	Check(0, 0, n, paper);

	// output
	cout << white << '\n';
	cout << blue;

}