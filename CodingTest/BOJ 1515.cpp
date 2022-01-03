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
			// 같으면 pointer 증가
			if (str[point] == tmp[i]) {
				point++;
			}
			// 마지막을 가리키면 출력 후 종료
			if (point == size) {
				cout << answer;
				return 0;
			}
		}
	}

	return 0;
}