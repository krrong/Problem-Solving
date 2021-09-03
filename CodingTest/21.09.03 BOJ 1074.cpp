#include <iostream>
using namespace std;

int n, r, c, res;

// divide and conquer
int check(int size, int r, int c) {
	if (size == 0) {
		return 0;
	}

	// half length
	int half = 1 << (size - 1);

	// Quadrant 1
	if (r < half && c < half) {
		return check(size - 1, r, c);
	}
	// Quadrant 2
	if (r < half && c >= half) {
		return half * half + check(size - 1, r, c - half);
	}
	// Quadrant 4
	if (r >= half && c < half) {
		return 2 * half * half + check(size - 1, r - half, c);
	}
	// Quadrant 3
	else{
		return 3 * half * half + check(size - 1, r - half, c - half);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> r >> c;
	cout << check(n, r, c);
}