// https://www.acmicpc.net/problem/16918
#include <iostream>
using namespace std;

char board[200][200];
int _time[200][200];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int R, C, N;

bool valid(int r, int c) {
	return (r >= 0 && r < R&& c >= 0 && c < C);
}

void print() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << board[i][j];
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> R >> C >> N;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];

			// 폭탄이면 시간 설정
			if (board[i][j] == 'O') {
				_time[i][j] = 3;
			}
		}
	}

	int t = 2;
	while (t != N + 1) {
		// 짝수 시간이면 폭탄 설치
		if (t % 2 == 0) {
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					if (board[i][j] == '.') {
						board[i][j] = 'O';		// 폭탄 설치
						_time[i][j] = t + 3;	// 현재 시간부터 3초 이후에 폭발
					}
				}
			}
		}
		// 홀수 시간이면 폭탄 폭발
		else {
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					// 폭탄이 폭발할 시간이면
					if (_time[i][j] == t) {
						board[i][j] = '.';		// 폭탄 폭발

						// 위치가 유효한 상 하 좌 우 함께 폭발
						for (int w = 0; w < 4; w++) {
							if (valid(i + dx[w], j + dy[w]) == true) {
								board[i + dx[w]][j + dy[w]] = '.';

							}
						}
					}
				}
			}
		}
		// 시간 증가
		t++;
	}

	print();

	return 0;
}