#include <iostream>
#include <vector>
using namespace std;

int n, t;

// 최대공약수
int GCD(int a, int b) {
	if (b == 0) {
		return a;
	}

	return GCD(b, a % b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	while (t--) {
		cin >> n;
		vector<int> v(n);

		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		long long sum = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				sum = sum + GCD(v[i], v[j]);
			}
		}

		cout << sum << '\n';
	}

	return 0;
}