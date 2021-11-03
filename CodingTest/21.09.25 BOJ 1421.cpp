#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c, w;

bool comp(int a, int b) {
	if (a > b)return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> c >> w;
	vector<int> trees(n);
	for (int i = 0; i < n; i++) {
		cin >> trees[i];
	}

	sort(trees.begin(), trees.end());
	long long res = 0;

	// i = 나무의 길이
	for (int i = 1; i <= 10000; i++) {
		// 금액을 담아놓을 벡터
		vector<int> tmp;
		for (int j = 0; j < n; j++) {
			// 나머지가 남으면 그 나무는 뺴고 판다
			if (trees[j] % i) {
				tmp.push_back(w * trees[j] - w * (trees[j] % i) - c * (trees[j] / i));
			}
			// 나머지가 없으면 모든 나무를 판다
			else {
				tmp.push_back(w * trees[j] - c * (trees[j] / i - 1));
			}
		}

		// 내림차순 정렬 -> 음수면 받을 수 있는 금액이 적어져서 더하지 않는다.
		sort(tmp.begin(), tmp.end(), comp);
		long long sum = 0;
		for (int k = 0; k < tmp.size(); k++) {
			if (tmp[k] < 0) break;
			sum = sum + tmp[k];
		}

		res = max(sum, res);
	}

	cout << res;
	return 0;
}
