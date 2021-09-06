#include <iostream>
#include <string>
#include <vector>
#define MAX 30+2
using namespace std;

char map[MAX][MAX];
int n;
string str;
int dx[] = { 0,1,1,1 };		// row, rightDiagonal, col, leftDiagonal
int dy[] = { 1,1,0,-1 };

char getNext(int x, int y) {
	if (x<0 || y<0 || x>n || y>n) {
		return '0';
	}
	return map[x][y];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str;

		// make array
		for (int j = 0; j < str.size(); j++) {
			map[i][j] = str[j];
		}
	}

	// find
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// for x, y
			for (int k = 0; k < 4; k++) {
				// count of same thing
				int same = 1;
				// check the three component
				for (int p = 1; p <= 2; p++) {
					if (map[i][j] == getNext(i + p * dx[k], j + p * dy[k])) {
						same++;
					}
					
					if (same == 3 && map[i][j] != '.') {
						cout << map[i][j];
						return 0;
					}
				}
			}
		}
	}

	cout << "ongoing";
	return 0;
}