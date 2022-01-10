// https://www.acmicpc.net/problem/2178
#include <iostream>
#include <queue>
using namespace std;

int n, m;
int board[101][101];	// 미로
bool visit[101][101];	// 방문 여부
int dist[101][101];		// 거리
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

// 위치가 유효한지 판단
bool valid(int r, int c) {
	return (r >= 1 && r <= n && c >= 1 && c <= m);
}

void bfs(int r, int c) {
	queue<pair<int, int>> q;
	q.push(make_pair(r, c));
	visit[r][c] = true;

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		
		if (cur.first == n && cur.second == m) {
			cout << dist[n][m];
		}

		// 상 하 좌 우 확인
		for (int w = 0; w < 4; w++) {
			// 위치가 유효할 때
			if (valid(cur.first + dx[w], cur.second + dy[w])) {
				// 방문하지 않았을 때
				if (visit[cur.first + dx[w]][cur.second + dy[w]] == false) {
					// 1일 때 -> 방문여부 표시, 거리 갱신, 큐에 추가
					if (board[cur.first + dx[w]][cur.second + dy[w]] == 1) {
						visit[cur.first + dx[w]][cur.second + dy[w]] = true;
						dist[cur.first + dx[w]][cur.second + dy[w]] = dist[cur.first][cur.second] + 1;
						q.push(make_pair(cur.first + dx[w], cur.second + dy[w]));
					}
				}
			}
		}
	}
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= s.size(); j++) {
			board[i][j] = s[j - 1] - '0';
		}
	}

	dist[1][1] = 1;
	bfs(1, 1);

	return 0;
}