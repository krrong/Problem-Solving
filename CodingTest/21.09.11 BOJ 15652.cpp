#include <iostream>
using namespace std;

int n, m;
int arr[9];

// 백트래킹 
// 같은 수를 여러번 고를 수 있기 때문에 visit을 체크하는 배열을 만들 필요가 없다.
void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		// 배열에 이미 어떠한 수가 들어가있다면 비내림차순인지 파악
		if (k > 0) {
			if (arr[k - 1] <= i) {
				arr[k] = i;
				func(k + 1);
			}
		}
		// 배열에 아무 수도 안들어가있으면 일단 넣어준다.
		else {
			arr[k] = i;
			func(k + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	func(0);


}