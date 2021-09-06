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

	// aj의 j를 이분 탐색
	for (int i = 0; i < n - 1; i++) {
		int fir = v[i];	// ai
		int left = i;
		int right = n;
		int mid = 0;

		while (left <= right) {
			mid = (left + right) / 2;

			if (fir + v[mid] > x) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}

		if (fir + v[left] == x) {
			result++;
		}
	}

	cout << result;
}