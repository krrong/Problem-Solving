// https://www.acmicpc.net/problem/2667
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int board[26][26];
bool visit[26][26];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<int> answer;

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
}

void bfs(int r, int c) {
	int cnt = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(r, c));
	visit[r][c] = true;

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		// �� �� �� �� Ȯ��
		for (int w = 0; w < 4; w++) {
			// ���� �ְ�
			if (board[cur.first + dx[w]][cur.second + dy[w]] == 1) {
				// �湮���� �ʾ����� �湮 ǥ��, ť���߰�, ���� �߰�
				if (visit[cur.first + dx[w]][cur.second + dy[w]] == false) {
					visit[cur.first + dx[w]][cur.second + dy[w]] = true;
					q.push(make_pair(cur.first + dx[w], cur.second + dy[w]));
					cnt++;
				}
			}
		}
	}
	answer.push_back(cnt);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		
		for (int j = 0; j < s.size(); j++) {
			board[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// 1�ε� �湮���� �ʾ����� bfs�� ���� �� üũ
			if (board[i][j] == 1 && visit[i][j] == false) {
				bfs(i, j);
			}
		}
	}

	// �������� ����
	sort(answer.begin(), answer.end());

	int count = answer.size();
	cout << count << '\n';
	for (int i = 0; i < count; i++) {
		cout << answer[i] << '\n';
	}

	return 0;
}