#include <iostream>
#include <vector>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	vector<int> books(n);

	// input
	for (int i = 0; i < n; i++) {
		cin >> books[i];
	}

	// the number of resort book
	int result = n;
	for (int i = n - 1; i >= 0; i--) {
		if (books[i] == result) {
			result--;
		}
	}

	cout << result;
}