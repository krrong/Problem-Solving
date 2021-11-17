//https://www.acmicpc.net/problem/15649
#include <iostream>
using namespace std;

int N, M;			// 입력 값
int arr[10];		// 담아놓을 배열
bool visit[10];		// 담았는지 확인

// 백트래킹
void backtrack(int k) {
	if (k == M) {						// M개를 뽑으면
		for (int i = 0; i < k; i++) {	// 뽑은 순서대로 출력
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {		// 순서대로 
		if (visit[i] == false) {		// 뽑혀있지 않으면
			visit[i] = true;			// 뽑고
			arr[k] = i;					// 저장한 뒤
			backtrack(k + 1);			// 다음으로 진행
			visit[i] = false;			// 끝나면 다시 넣어준다.
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	backtrack(0);

	return 0;
}