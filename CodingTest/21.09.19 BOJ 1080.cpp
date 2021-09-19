#include <iostream>
using namespace std;

int n, m;
bool A[51][51];
bool B[51][51];

// 3X3 행렬 뒤집어주는 함수
void change(int x, int y) {
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			if (A[i][j] == 0) {
				A[i][j] = 1;
			}
			else {
				A[i][j] = 0;
			}
		}
	}
}

// A와 B가 같은지 체크하는 함수
bool check() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (A[i][j] != B[i][j]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			if (str[j] == '0') {
				A[i][j] = 0;
			}
			else {
				A[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			if (str[j] == '0') {
				B[i][j] = 0;
			}
			else {
				B[i][j] = 1;
			}
		}
	}

	int result = 0;

	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			// 만약 다르면 그 위치에서 3X3행렬 변환, 개수 증가
			if (A[i][j] != B[i][j]) {
				change(i, j);
				result++;
			}
		}
	}

	if (check() == true) {
		cout << result;
	}
	else {
		cout << -1;
	}

	return 0;
}