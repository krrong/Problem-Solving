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
			if (visit[computers[cur][i]] == false) {
				visit[computers[cur][i]] = true;
				q.push(computers[cur][i]);
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

		computers[a].push_back(b);
		computers[b].push_back(a);
	}

	bfs();

	return 0;
}