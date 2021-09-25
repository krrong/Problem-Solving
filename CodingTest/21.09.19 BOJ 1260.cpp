#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int n, m, v;
vector<vector<int>> graph;
vector<bool> visit;

void dfs(int start){
	stack<int> s;
	visit[start] = true;
	s.push(start);
	cout << start << ' ';

	while (!s.empty()) {
		int tmp = s.top();
		s.pop();

		for (int i = 0; i < graph[tmp].size(); i++) {
			int cur = graph[tmp][i];
			if (visit[cur] == false) {
				visit[cur] = true;
				s.push(cur);
				dfs(cur);
			}
		}
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visit[start] = true;
	cout << start << ' ';

	while (!q.empty()) {
		int tmp = q.front();
		q.pop();

		for (int i = 0; i < graph[tmp].size(); i++) {
			int cur = graph[tmp][i];
			if (visit[cur] == false) {
				visit[cur] = true;
				q.push(cur);
				cout << cur << ' ';
			}
		}
	}
}

// 방문 여부 0으로 리셋
void reset() {
	cout << '\n';

	int size = visit.size();

	for (int i = 0; i < size; i++) {
		visit[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m >> v;

	// 방문 여부 저장하는 배열 생성
	for (int i = 0; i <= n; i++) {
		vector<int> v;
		graph.push_back(v);
		visit.push_back(false);
	}

	// 간선 연결
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(v);
	reset();
	bfs(v);

	return 0;
}