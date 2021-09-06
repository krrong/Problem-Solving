#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, x, result;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cin >> x;

	// 오름차순 정렬
	sort(v.begin(), v.end());

	// 각 항마다 이분 탐색 -> aj의 j를 찾는다.(inddex)
	for (int i = 0; i < n - 1; i++) {
		int searchNum = x - v[i];	// 찾는 수
		int left = i;
		int right = n - 1;
		int mid = 0;

		while (left <= right) {
			mid = (left + right) / 2;

			if (searchNum < v[mid]) {
				right = mid - 1;
			}
			else if (searchNum > v[mid]) {
				left = mid + 1;
			}
			// 같다면 stop
			else {
				break;
			}
		}
		
		if (mid >= n) {
			continue;
		}

		// mid 와 i가 같으면 같은 항이 두 번 사용될 수 있기 때문에 제외해줘야 한다.
		if (v[mid] == searchNum && mid != i) {
			result++;
		}
	}

	cout << result;
}