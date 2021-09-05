#include <iostream>
#include <vector>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	vector<int> rings(n);

	// input
	for (int i = 0; i < n; i++) {
		cin >> rings[i];
	}


	for (int i = 1; i < n; i++) {
		int tmp = 2;
		
		int standard = rings[0];

		while (tmp <= standard) {
			while (standard % tmp == 0 && rings[i] % tmp == 0) {
				standard = standard / tmp;
				rings[i] = rings[i] / tmp;
			}
			tmp++;
		}

		cout << standard << "/" << rings[i] << '\n';
	}
}