#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int n, m;
int numofComputer;	// 최대값 저장 위함
vector<vector<int>> graph;
vector<bool> visit;
vector<int> ans;

void dfs(int start) {
	int num = 1;
	visit[start] = true;
	stack<int> s;
	s.push(start);

	while (!s.empty()) {
		int tmp = s.top();
		s.pop();

		for (int i = 0; i < graph[tmp].size(); i++) {
			int cur = graph[tmp][i];
			if (visit[cur] == false) {
				visit[cur] = true;
				num++;
				s.push(cur);
			}
		}
	}

	ans.push_back(num);

	// 해킹 가능한 컴퓨터 최대 수
	if (num > numofComputer) {
		numofComputer = num;
	}
}

// 방문여부 초기화
void reset() {
	int size = visit.size();
	for (int i = 0; i < size; i++) {
		visit[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	// 노드와 방문여부 만들기
	for (int i = 0; i <= n; i++) {
		vector<int> tmp;
		graph.push_back(tmp);
		visit.push_back(false);
	}

	// 간선 연결
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		graph[y].push_back(x);
	}

	// 각 노드마다 dfs -> 방문여부 초기화
	for (int i = 1; i <= n; i++) {
		dfs(i);
		reset();
	}

	// 여러개면 오름차순 출력
	for (int i = 0; i < n; i++) {
		if (ans[i] == numofComputer) {
			cout << i + 1 << ' ';
		}
	}

	return 0;
}