#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int arr[9];
int visit[9];
vector<int> v(9);

// 백트래킹
void fucn(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (visit[i] == false) {
			// v의 인덱스는 0부터 시작해서 -1해줘야 한다.
			arr[k] = v[i - 1];
			visit[i] = true;
			fucn(k + 1);
			visit[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	// 오름차순 정렬 -> 사전 순 출력을 위함
	sort(v.begin(), v.end());

	// 오름차순 정렬하면 앞에 0이 생기기 때문에 삭제
	while (v[0] == 0) {
		v.erase(v.begin());
	}

	fucn(0);

	return 0;
}