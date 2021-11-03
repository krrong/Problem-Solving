#include <iostream>
using namespace std;

int n, white, blue;
bool board[129][129];

// x좌표, y좌표, 변의 길이 를 인자로 받음
void rec(int r, int c, int n) {
	if (n == 1) {
		if (board[r][c] == 1) {
			blue++;
		}
		else if (board[r][c] == 0) {
			white++;
		}
		return;
	}

	bool w = true;		// 모두 흰색인지 체크하는 flag
	bool b = true;		// 모두 파란색인지 체크하는 flag

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// 하나라도 흰색이 아니면 탐색 stop -> 흰색종이 X
			if (board[r + i][c + j] != 0) {
				w = false;
				break;
			}
		}
		if (w == false) {
			break;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// 하나라도 파란색이 아니면 탐색 stop -> 파란종이 X
			if (board[r + i][c + j] != 1) {
				b = false;
				break;
			}
		}
		if (b == false) {
			break;
		}
	}

	// b == true 이면 탐색한 면 모두 파란색임
	if (b == true) {
		blue++;
		return;
	}
	// w == true 이면 탐색한 면 모두 파란색임
	else if (w == true) {
		white++;
		return;
	}
	// 아니라면 4분할 하여 재탐색
	else {
		rec(r, c, n / 2);					// 1사분면
		rec(r + n / 2, c, n/2);				// 3사분면
		rec(r, c + n / 2, n/2);				// 2사분면
		rec(r + n / 2, c + n / 2, n/2);		// 4사분면
	}

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
	
	rec(1, 1, n);
	cout << white << '\n';
	cout << blue << '\n';
	return 0;
}