#include <iostream>
#include <stack>
using namespace std;

int n, result=100;
int arr[21][21];
bool visit[21];

// 백트래킹
void func(int k, int idx) {
	// 한팀의 인원이 n/2가 되면 stop
	if (k == n / 2) {
		int sum_star = 0;
		int sum_link = 0;
		// visit[i][j] = true 인 곳을 모두 더하고
		for (int i = 1; i <= n; i++) {
			if (visit[i] == true) {
				for (int j = 1; j <= n; j++) {
					if (visit[j] == true) {
						sum_star = sum_star + arr[i][j];
					}
				}
			}
		// visit[i][j] = false 인 곳을 모두 더하고
			else {
				for (int j = 1; j <= n; j++) {
					if (visit[j] == false) {
						sum_link = sum_link + arr[i][j];
					}
				}
			}
		}

		// 최소값 찾기
		result = min(result, abs(sum_star - sum_link));
		return;
	}

	// 재귀 idx는 실행시간을 줄이기 위함
	for (int i = idx; i <= n; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			func(k + 1, i);
			visit[i] = false;
		}
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	func(0, 1);

	cout << result;
}