// https://www.acmicpc.net/problem/1515
#include <iostream>
#include <string>
using namespace std;

// 나올 수 있는 최대 자리수는 5자리
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str;
	int answer = 0;

	cin >> str;
	int size = str.size();
	int point = 0;

	while (answer++ <= 30000) {
		string tmp = to_string(answer);

		for (int i = 0; i < tmp.size(); i++) {
			if (str[point] == tmp[i]) {
				point++;
			}
			if (point == size) {
				cout << answer;
				return 0;
			}
		}
	}

	return 0;
}