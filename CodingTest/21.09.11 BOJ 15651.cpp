#include <iostream>
using namespace std;

int n, m;
int arr[8];

// 백트래킹 -> 방문을 표시하지 않아도 된다.
void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		arr[k] = i;
		func(k + 1);
	}
		
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	func(0);
}