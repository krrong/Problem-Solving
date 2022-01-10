// https://www.acmicpc.net/problem/7576
#include <iostream>
#include <queue>
using namespace std;

int tomato[1001][1001];		// 토마토 농장 상태
bool visit[1001][1001];		// 방문 여부 저장
int dist[1001][1001];		// 일 수 저장
int dx[4] = { -1,1,0,0 };	// x좌표 이동
int dy[4] = { 0,0,-1,1 };	// y좌표 이동
int n, m, answer;
queue<pair<int, int>> q;	// bfs에서 사용할 큐

// 위치가 유효한지 체크
bool valid(int r, int c) {
	return (r >= 0 && r < n && c >= 0 && c < m);
}

// 모두 익었는지 체크
bool check() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// 익지 않았으면
			if (dist[i][j] == 10000000) {
				if (tomato[i][j] == 0) {
					return false;
				}
			}
		}
	}
	return true;
}

// bfs
void bfs() {
	while (!q.empty()) {
		// 전역변수로 선언한 큐 사용 -> 처음에 익은 토마토가 여러개 있을 수 있기 때문
		pair<int, int> cur = q.front();
		q.pop();

		// 상 하 좌 우 확인
		for (int w = 0; w < 4; w++) {
			int mr = cur.first + dx[w];
			int mc = cur.second + dy[w];

			// 위치가 유효하고 
 			if (valid(mr, mc) == true) {
				// 익지 않은 토마토가 있고 방문하지 않았을 경우
				if (tomato[mr][mc] == 0 && visit[mr][mc] == false) {
					visit[mr][mc] = true;		// 방문 체크
					q.push(make_pair(mr, mc));	
					dist[mr][mc] = min(dist[mr][mc], dist[cur.first][cur.second] + 1);	// 거리 갱신
					tomato[mr][mc] = 1;			// 익은 토마토로 변경
				}
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tomato[i][j];
			
			// 익은 토마토이면
			if (tomato[i][j] == 1) {
				q.push(make_pair(i, j));	// 큐에 추가
				dist[i][j] = 0;				// 거리 0
			}
			else {
				dist[i][j] = 10000000;		// 익지 않은 토마토면 거리 최대
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// 익은 토마토면 해당 위치부터 bfs
			if (tomato[i][j] == 1 && visit[i][j] == false) {
				bfs();
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// 토마토가 없는 자리가 아니면 answer에 최대 일 수 저장
			if (tomato[i][j] != -1) {
				answer = max(answer, dist[i][j]);
			}
		}
	}
	
	// 모두 익은 상태
	if (check() == true) {
		cout << answer;
	}
	// 모두 익지 않은 상태
	else {
		cout << -1;
	}

	return 0;
}