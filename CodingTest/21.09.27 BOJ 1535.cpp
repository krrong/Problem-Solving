#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int dp[21][101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	int health = 0;
	int glad = 0;

	vector<int> H(n + 1);	// 잃는 건강
	vector<int> G(n + 1);	// 얻는 행복

	for (int i = 1; i <= n; i++) {
		cin >> H[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> G[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 100; j++) {
			if (H[i] >= j) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - H[i]] + G[i]);
			}
		}
	}

	cout << dp[n][100];

	return 0;
}

// 반례
// 3
// 79 50 30
// 20 15 15
// output : 20
// answer : 30