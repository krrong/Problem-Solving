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

	// �������� ����
	sort(v.begin(), v.end(), comp);

	// ���� �ɸ��� �ð��� ���� ��ġ��ŭ �����༭ �����ָ� �ȴ�.
	for (int i = n - 1; i >=0 ; i--) {
		result = result + v[i] * (i + 1);
	}

	cout << result;
}