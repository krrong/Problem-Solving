#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string x;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> x;
	int size = x.size();
	int* arr = new int[size];

	// make string to char array
	for (int i = 0; i < size; i++) { 
		arr[i] = x[i] - '0';
	}

	// find the descending index
	int index = 0;
	int num = 0;
	for (int i = size-1; i >= 1 ; i--) {
		if (arr[i - 1] < arr[i]) {
			index = i;
			num = arr[i - 1];
			break;
		}
	}

	// end condition
	if (index == 0) {
		cout << 0;
		return 0;
	}

	// find the number a little big than num for to change
	int changeNum = 9;
	int changeIndex = index;
	for (int i = index; i < size; i++) {
		if (arr[i] > num && arr[i] < changeNum) {
			changeNum = arr[i];
			changeIndex = i;
		}
	}

	// change 
	int tmp = arr[index - 1];
	arr[index - 1] = arr[changeIndex];
	arr[changeIndex] = tmp;

	// sort
	sort(arr + index, arr + size);

	// output
	for (int i = 0; i < size; i++) {
		cout << arr[i];
	}

}