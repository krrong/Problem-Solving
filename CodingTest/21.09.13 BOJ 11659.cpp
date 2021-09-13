#include <iostream>
#include <vector>
using namespace std;

int n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	vector<int> v(n + 1);
	vector<int> sum(n + 1);	// 1항부터 N항까지의 누적 합 저장


	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		sum[i] = v[i] + sum[i - 1];
	}

	while (m--) {
		int a, b;
		cin >> a >> b;
		// b번째 항까지 누적합에서 모두 더한 값에서 a-1번째 항까지 누적합을 빼준다.
		int result = sum[b] - sum[a - 1];

		cout << result << "\n";
	}

	return 0;
}