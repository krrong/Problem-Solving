#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int n, m, result;
// binary search
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	vector<int> tree(n);	// the height of trees
	for (int i = 0; i < n; i++) {
		cin >> tree[i];
	}

	sort(tree.begin(), tree.end());

	// find the answer using binary search
	ll left = 0;
	ll right = tree[n - 1];
	ll mid = 0;
	while (left <= right) {
		mid = (left + right) / 2;

		// the length of cut tree
		ll tmp = 0;
		for (int i = 0; i < n; i++) {
			if (tree[i] - mid > 0) {
				tmp = tmp + tree[i] - mid;
			}
		}

		if (tmp >= m) {
			if (result < mid) {
				result = mid;
			}
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << result;
}