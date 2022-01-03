// https://www.acmicpc.net/problem/1012
#include <iostream>
#include <queue>
using namespace std;

int land[50][50];
bool visit[50][50];
int n, m, k;

// 하, 상, 좌, 우
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

// 출력함수
void print() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << land[i][j] << ' ';
		}
		cout << endl;
	}
}

// 초기화
void reset() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			land[i][j] = 0;
			visit[i][j] = 0;
		}
	}
}

// 범위 안에 들어가는지 확인
bool valid(int r, int c) {
	return (r >= 0 && r < m && c >= 0 && c < n);
}

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visit[x][y] = true;

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		// 상 하 좌 우에 배추가 있는지, 벌레가 방문했는지 확인
		for (int w = 0; w < 4; w++) {
			// 범위에 들어가고
			if (valid(cur.first + dx[w], cur.second + dy[w])) {
				// 배추가 심어져 있고
				if (land[cur.first + dx[w]][cur.second + dy[w]] == 1) {
					// 방문하지 않았으면 
					if (visit[cur.first + dx[w]][cur.second + dy[w]] == false) {
						// 방문 표시
						visit[cur.first + dx[w]][cur.second + dy[w]] = true;
						// 큐에 추가
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

	int t;
	cin >> t;
	while (t--) {
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			land[x][y] = 1;
		}

		//print();
		int answer = 0;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (land[i][j] == 1 && visit[i][j] == false) {
					answer++;
					bfs(i, j);
				}
			}
		}
		cout << answer << '\n';
		reset();
	}

	return 0;
}