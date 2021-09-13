#include <iostream>
using namespace std;

int n;
int dp[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	dp[1] = 1;
	dp[2] = 3;
	dp[3] = 5;
	dp[4] = 11;

	for (int i = 5; i <= n; i++) {
		dp[i] = (dp[i - 2] * 2 + dp[i - 1]) % 10007;
	}

	cout << dp[n];

}