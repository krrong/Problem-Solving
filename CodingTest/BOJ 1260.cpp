// https://www.acmicpc.net/problem/1260
#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

int n, m, v;
int graph[1001][1001];
bool visit[1001];

void bfs(int v) {
	queue<int> q;
	q.push(v);
	visit[v] = true;
	cout << v << ' ';

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < 1001; i++) {
			// 간선이 있고
			if (graph[cur][i] == true) {
				// 방문하지 않았다면
				if (visit[i] == false) {
					// 방문표시
					visit[i] = true;
					// 큐에 추가
					q.push(i);
					// 출력
					cout << i << ' ';
				}
			}
		}
	}
}

// 방문여부 초기화
void reset() {
	for (int i = 0; i < 1001; i++) {
		visit[i] = false;
	}
}

void dfs(int v) {
	stack<int> s;
	s.push(v);
	visit[v] = true;
	cout << v << ' ';

	while (!s.empty()) {
		int cur = s.top();
		s.pop();

		for (int i = 0; i < 1001; i++) {
			// 간선이 있고
			if (graph[cur][i] == true) {
				// 방문하지 않았다면
				if (visit[i] == false) {
					// 방문 표시
					visit[i] = true;
					// 스택에 추가
					s.push(i);
					// dfs 재호출
					dfs(i);
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		// 무향 그래프 생성
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	dfs(v);
	cout << '\n';
	reset();
	bfs(v);

	return 0;
}