#include <iostream>
typedef long long ll;
using namespace std;

ll k;
ll cnt;

int rec(ll k) {
	if (k == 1) return 0;
	ll i;
	for (i = 1; i + i < k; i += i);
	return !rec(k - i);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> k;
	cout << rec(k);

	return 0;
}

