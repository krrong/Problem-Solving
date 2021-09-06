#include <iostream>
#include <vector>
using namespace std;

int t, n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	while (t--) {
		int result = 0;
		cin >> n;
		vector<int> list(n);

		// input
		for (int i = 0; i < n; i++) {
			cin >> list[i];
		}

		// sort
		for (int i = 1; i < n; i++) {
			int tmp = i;

			while (tmp != 0) {
				if (list[tmp - 1] > list[tmp]) {
					swap(list[tmp - 1], list[tmp]);
					result++;
				}
				tmp--;
			}
		}

		cout << result << '\n';
	}

}