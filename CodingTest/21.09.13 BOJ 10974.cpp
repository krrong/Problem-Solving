#include <iostream>
using namespace std;

int n;
int arr[9];
bool visit[9];

// 백트래킹
void func(int k) {
	if (k == n) {
		for (int i = 0; i < n; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (visit[i] == false) {
			arr[k] = i;
			visit[i] = true;
			func(k + 1);
			visit[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	func(0);

	return 0;
}