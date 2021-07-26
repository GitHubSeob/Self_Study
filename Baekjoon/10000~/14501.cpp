/*
x �Ͽ� �����ϸ� �ɸ��� �� ��: T[x]
x �Ͽ� �����ϸ� �޴� �ݾ�: P[x]
x���� ���� ���� y�� �д�.
x ���� �� y �Ͽ� ����� �����ϸ� x �� ������ ������ ���
DP[x] = DP[y] + P[y]�� �д�.
y�� 1���� x-1���� ���鼭 ���� ū ���� DP[x]�� �����Ѵ�.
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	int x = 0;
	cin >> N;
	vector<int>DP(N + 2, 0);
	vector<int>T(N + 1, 0);
	vector<int>P(N + 1, 0);

	for (x = 1; x <= N; ++x) {
		cin >> T[x] >> P[x];
	}
	int value = 0;
	for (x = 1; x <= N + 1; ++x) {
		for (int x2 = 1; x2 < x; ++x2) {
			if (x >= T[x2] + x2)
				DP[x] = max(DP[x2] + P[x2], DP[x]);
		}
	}
	cout << DP[N + 1];
}