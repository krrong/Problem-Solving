#include <iostream>
#include <vector>
using namespace std;

int n, m, cnt;
bool friends_standard[51][51];
bool friends[51][51];
vector<int> result;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	// make connection
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		friends_standard[a][b] = 1;
		friends_standard[b][a] = 1;
		friends[a][b] = 1;
		friends[b][a] = 1;

		cnt = cnt + 2;	// 模备 荐 2疙究 墨款飘!
	}

	// repeat for all is friends
	while (cnt < n * (n - 1)) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					// i-j , j-k -> i-k is friend
					if (i != k && friends_standard[i][j] == 1 && friends_standard[j][k] == 1) {
						friends[i][k] = 1;
						friends[k][i] = 1;
					}
				}
			}
		}

		// today count of friends
		int tmp = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				// if not same -> today friends
				if (friends_standard[i][j] != friends[i][j]) {
					cnt++;
					tmp++;
					friends_standard[i][j] = friends[i][j];
				}
			}
		}

		result.push_back(tmp / 2);
	}

	cout << result.size() << '\n';
	for (auto e : result) {
		cout << e << '\n';
	}
}