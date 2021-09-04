#include <iostream>
#include <string>
using namespace std;
// greedy algorithm -> find and paste the largest number that can divide origin number
int n, t;

int main() {
	
	cin >> t;

	while (t--) {
		cin >> n;

		string ans = "";

		bool possible = true;	// bigger flag
		while (n >= 10 && possible == true) {
			bool poss = false;	// small flag
			for (int i = 9; i >= 2; i--) {
				if (n % i == 0) {
					ans.insert(ans.begin(), '0' + i);
					n = n / i;
					poss = true;
					break;
				}
			}
			if (poss == false) {
				possible = false;
			}
		}

		if (possible == false) {
			cout << -1 << "\n";
		}
		else {
			ans.insert(ans.begin(), '0' + n);
			cout << ans.size() << '\n';
		}
	}


	
}