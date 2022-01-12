// https://www.acmicpc.net/problem/7569
#include <iostream>
#include <queue>
using namespace std;

int N, M, H;
int tomato[101][101][101];			// 토마토 농장 상태
bool visit[101][101][101];			// 방문여부 저장
int dist[101][101][101];			// 거리저장
int dx[6] = { 0,0,0,0,-1,1 };		// x축 이동
int dy[6] = { 0,0,-1,1,0,0 };		// y축 이동
int dz[6] = { -1,1,0,0,0,0 };		// z축 이동
queue <pair<int, pair<int, int>>> q;	// (z축, (x축, y축))값 저장

void print() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cout << dist[i][j][k] << ' ';
			}
			cout << endl;
		}
	}
}

// 위치가 유효한지 판단
bool valid(int h, int c, int r) {
	return (r >= 0 && r < M && c >= 0 && c < N && h >= 0 && h < H);
}

// bfs
void bfs() {
	while (!q.empty()) {
		pair<int, pair<int, int>> cur = q.front();
		q.pop();

		// 6가지 방향으로 확인
		for (int w = 0; w < 6; w++) {
			// 위치가 유효한지
			if (valid(cur.first + dz[w], cur.second.first + dx[w], cur.second.second + dy[w]) == true) {
				// 방문하지 않았는지
				if (visit[cur.first + dz[w]][cur.second.first + dx[w]][cur.second.second + dy[w]] == false) {
					visit[cur.first + dz[w]][cur.second.first + dx[w]][cur.second.second + dy[w]] = true;		// 방문 여부 표시
					dist[cur.first + dz[w]][cur.second.first + dx[w]][cur.second.second + dy[w]]				// 거리 갱신
						= min(dist[cur.first + dz[w]][cur.second.first + dx[w]][cur.second.second + dy[w]], 
							dist[cur.first][cur.second.first][cur.second.second] + 1);
					tomato[cur.first + dz[w]][cur.second.first + dx[w]][cur.second.second + dy[w]] = 1;			// 익은 상태로 변경
					q.push(make_pair(cur.first + dz[w], make_pair(cur.second.first + dx[w], cur.second.second + dy[w])));	// 큐에 추가
				}
			}
		}
	}
}

// 모든 토마토가 익었는지 판단
bool check() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				// 익지 않은 토마토가 존재하는 경우
				if (tomato[i][j][k] == 0) {
					return false;
				}
			}
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> tomato[i][j][k];
				dist[i][j][k] = 1000000000;

				// 1이면 큐에 추가, 거리 0
				if (tomato[i][j][k] == 1) {
					// z, x, y 
					q.push(make_pair(i, make_pair(j, k)));
					dist[i][j][k] = 0;
				}

				// 토마토가 없으면 방문할 필요 x
				if (tomato[i][j][k] == -1) {
					visit[i][j][k] = -1;
				}
			}
		}
	}

	// bfs 실행
	bfs();

	// 토마토가 있는 자리 중 dist값이 가장 큰 것
	int answer = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (tomato[i][j][k] != -1) {
					answer = max(answer, dist[i][j][k]);
				}
			}
		}
	}

	// 모두 익었으면 answer출력
	if (check() == true) {
		cout << answer;
	}
	else {
		cout << -1;
	}

	return 0;
} 