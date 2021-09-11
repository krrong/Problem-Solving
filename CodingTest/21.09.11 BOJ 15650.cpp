#include <iostream>
using namespace std;

int n, m;
int arr[10];
bool visit[10];

// 백트래킹
void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (k >= 1) {
			// 전에 저장된 수보다 클 떄만 수를 저장 
			if (arr[k - 1] < i) {
				if (visit[i] == false) {
					arr[k] = i;
					visit[i] = true;
					func(k + 1);
					visit[i] = false;
				}
			}
		}
		// 수가 하나도 저장되어 있지 않다면 저장
		else {
			if (visit[i] == false) {
				arr[k] = i;
				visit[i] = true;
				func(k + 1);
				visit[i] = false;
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

 	cin >> n >> m;
	func(0);

	return 0;
}