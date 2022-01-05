// https://www.acmicpc.net/problem/2606
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> computers[101];
bool visit[101];

void bfs() {
	int answer = 0;
	queue<int> q;
	q.push(1);
	visit[1] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < computers[cur].size(); i++) {
			// 방문하지 않았으면
			if (visit[computers[cur][i]] == false) {
				// 방문 여부 체크
				visit[computers[cur][i]] = true;
				// 큐에 추가
				q.push(computers[cur][i]);
				// 1번 컴퓨터를 통해 감염되는 컴퓨터 수 추가
				answer++;
			}
		}
	}
	cout << answer;
}

int n, s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> s;
	for (int i = 0; i < s; i++) {
		int a, b;
		cin >> a >> b;

		// 무향 그래프
		computers[a].push_back(b);
		computers[b].push_back(a);
	}

	bfs();

	return 0;
}