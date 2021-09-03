#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k, start, dest, result, cnt;
vector<int> v[101];
bool visit[101];

// bfs function
void bfs(int start) {
	queue<int> q;
	q.push(start);
	visit[start] = true;

	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		for (int i = 0; i < v[tmp].size(); i++) {
			if (visit[v[tmp][i]] == false) {
				q.push(v[tmp][i]);
				visit[v[tmp][i]] = true;
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	// connect
	for (int i = 1; i <= k; i++) {
		cin >> start >> dest;
		v[start].push_back(dest);
		v[dest].push_back(start);
	}

	bfs(1);

	// count computer of virus
	for (int i = 0; i < 101; i++) {
		if (visit[i] == true) {
			cnt++;
		}
	}

	cout << cnt - 1;	// except 1
}