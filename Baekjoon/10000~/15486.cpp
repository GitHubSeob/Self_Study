/*
14501�� �������� N, T�� ������ ������ �����̴�.
������ Ǭ ������� �ϸ� �ð� �ʰ��� ���� ������ �ٸ� ������� Ǭ��.

1�� �� �Ϸ� �ɸ��� ����� ������ 2�� ��� ���� ���� �޴´ٰ� �����Ѵ�.
�׷��� ������ x�� 1���� N+1���� �ݺ��Ѵ�.
DP[x]�� DP[x-1]���� ���� ��� DP[x-1] ������ �ٲ۴�.
x �Ͽ� ����� �����ϸ� ����� ������ ���� �޴� x+T[x] �Ͽ�
x �ϱ��� �� �� + x �Ͽ� �����ϴ� ����� �̹� ����� DP[x+T[x]] �� �� �� ū ���� �����Ѵ�.
��� �ݺ��� ����Ǹ� DP[N+1] ���� ����Ѵ�.
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
	vector<int>DP(N+2, 0);
	vector<int>T(N+2, 0);
	vector<int>P(N+2, 0);

	for (x = 1; x <= N; ++x) {
		cin >> T[x] >> P[x];
	}
	for (x = 1; x <= N + 1; ++x) {
		DP[x] = max(DP[x], DP[x - 1]);
		if (x + T[x] <= N + 1)
			DP[x + T[x]] = max(DP[x] + P[x], DP[x + T[x]]);
	}
	cout << DP[N + 1];
}