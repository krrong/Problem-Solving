#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, result;

bool comp(int a, int b) {
	if (a > b)return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	// 내림차순 정렬
	sort(v.begin(), v.end(), comp);

	// 적게 걸리는 시간은 행의 위치만큼 곱해줘서 더해주면 된다.
	for (int i = n - 1; i >=0 ; i--) {
		result = result + v[i] * (i + 1);
	}

	cout << result;
}