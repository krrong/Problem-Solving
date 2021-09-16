#include <iostream>
#include <vector>
using namespace std;

int n, l;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> l;
	// n을 l로 나눈 수 부터 오른쪽으로 더해야 함
	while (true) {
		int tmp = n / l;
		int left = tmp - ((l - 1) / 2);
		int right = tmp + (l / 2);

		if (left < 0) {
			break;
		}

		vector<int> result;
		int sum = 0;

		// 합 계산
		for (int i = left; i <= right; i++) {
			sum = sum + i;
		}

		// 합이 같으면 출력
		if (sum == n) {
			for (int i = left; i <= right; i++) {
				result.push_back(i);
			}

			if (result.size() > 100 || result.size() == 0) {
				break;
				return 0;
			}

			for (int i = 0; i < result.size(); i++) {
				cout << result[i] << ' ';
			}
			return 0;
		}
		// 합이 다르면 a늘려서 다시 시작
		else {
			l++;
		}
	}

	cout << -1;
	return 0;
}