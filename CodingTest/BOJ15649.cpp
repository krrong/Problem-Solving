//https://www.acmicpc.net/problem/15649
#include <iostream>
using namespace std;

int N, M;			// �Է� ��
int arr[10];		// ��Ƴ��� �迭
bool visit[10];		// ��Ҵ��� Ȯ��

// ��Ʈ��ŷ
void backtrack(int k) {
	if (k == M) {						// M���� ������
		for (int i = 0; i < k; i++) {	// ���� ������� ���
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {		// ������� 
		if (visit[i] == false) {		// �������� ������
			visit[i] = true;			// �̰�
			arr[k] = i;					// ������ ��
			backtrack(k + 1);			// �������� ����
			visit[i] = false;			// ������ �ٽ� �־��ش�.
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