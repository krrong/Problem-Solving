#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, s, res, sum;
bool visit[21];

// idx는 이전에 확인한 것을 넣지 않기 위함
void func(int k, vector<int> v, int idx) {

	if (k > 0 && sum == s) {
		res++;
	}

	for (int i = idx; i < n; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			sum = sum + v[i];
			func(k + 1, v, i + 1);
			visit[i] = false;
			sum = sum - v[i];
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> s;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	func(0, v, 0);
	cout << res;

	return 0;
}