#include <iostream>
#include <map>
using namespace std;

int n, c, val;
map<int, int> fre;
map<int, int> order;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> c;

	int num = 1;

	// make order
	for (int i = 0; i < n; i++) {
		cin >> val;
		fre[val]++;
		
		if (order[val] == 0) {
			order[val] = num++;
		}
	}

	while (true) {
		int maxFre = 0;	// max frequency of number
		int index = 0;	// the index of frequency max

		// find
		for (int i = 1; i <= fre.size(); i++) {
			if (maxFre < fre[i]) {
				maxFre = fre[i];
				index = i;
			}
			// if same of frequency
			else if (maxFre == fre[i]) {
				if (order[index] > order[i]) {
					index = i;
				}
			}
		}

		if (maxFre == 0) {
			break;
		}

		// make zero
		while (fre[index]--) {
			cout << index << ' ';
		}
	}

}