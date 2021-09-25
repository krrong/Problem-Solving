#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> friends[51];
bool visit[51];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		// 친구관계정리
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == 'Y') {
				friends[i].push_back(1);
			}
			else {
				friends[i].push_back(0);
			}
		}
	}

	int result = 0;

	for (int i = 0; i < n; i++) {
		int tmp = 0;	// i의 2-친구 수
		for (int j = 0; j < friends[i].size(); j++) {
			// 같은 사람은 확인 안함
			if (i == j) {
				continue;
			}

			// i와 j가 친구인지 확인
			if (friends[i][j] == 1) {
				tmp++;
				continue;
			}

			// i, j와 같이 친구인 친구가 있는지 확인
			for (int k = 0; k < friends[j].size(); k++) {
				if (friends[j][k] == 1 && friends[i][k] == 1) {
					tmp++;
					break;
				}
			}
		}
		result = max(result, tmp);
	}

	cout << result;
	return 0;
}