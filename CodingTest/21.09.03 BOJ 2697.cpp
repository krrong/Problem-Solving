#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int t;
string a;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	
	while (t--) {
		cin >> a;

		int arr[82] = { 0 };

		int size = a.size();

		int index = 0;	// decreasing index
		string str = "";

		for (int i = 0; i < size; i++) {
			arr[i] = a[i] - '0';
		}

		int cnt = size;

		// find decreasing index
		for (int i = size - 1; i >= 1; i--) {
			if (arr[i] > arr[i - 1]) {
				index = i;
				break;
			}
		}


		// BIGGEST
		if (index == 0) {
			cout << "BIGGEST" << '\n';
		}
		else {
			int minNum = 9;
			int changeIndex = 0;

			// find minimun number under a[index]
			for (int i = index; i < size; i++) {
				if (arr[index - 1] < arr[i]) {
					if (minNum >= arr[i]) {
						minNum = arr[i];
						changeIndex = i;
					}
				}
			}

			//change
			arr[81] = arr[index - 1];
			arr[index - 1] = arr[changeIndex];
			arr[changeIndex] = arr[81];

			//sort
			sort(arr + index, arr + size);

			// output
			for (int i = 0; i < size; i++) {
				cout << arr[i];
			}
			cout << '\n';
		}
	}
	return 0;
}

