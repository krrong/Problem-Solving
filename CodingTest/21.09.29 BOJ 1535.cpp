#include <iostream>
#include <vector>
using namespace std;

int n;
int dp[101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	vector<int> H(n + 1);
	vector<int> G(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> H[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> G[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 100; j > H[i]; j--) {
			dp[j] = max(dp[j], dp[j - H[i]] + G[i]);
		}
	}

	cout << dp[100];

	return 0;
}