#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int board[1025][1025];

int solve(int r, int c, int n) {
	// 한 변의 길이가 2라면 4개중 두번째로 큰 수 리턴
	if (n == 2) {
		vector<int> v;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				v.push_back(board[r + i][c + j]);
			}
		}
		sort(v.begin(), v.end());
		return v[2];
	}
	
	// 각 구역에 대해 분할 정복한 뒤 두번째로 큰 수를 리턴한다.
	vector<int> v;
	v.push_back(solve(r, c, n / 2));				// 좌측상단
	v.push_back(solve(r + n / 2, c, n / 2));		// 좌측하단
	v.push_back(solve(r, c + n / 2, n / 2));		// 우측상단
	v.push_back(solve(r + n / 2, c + n / 2, n / 2));// 우측하단

	sort(v.begin(), v.end());
	return v[2];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}

	cout << solve(1, 1, n);

	return 0;
}

