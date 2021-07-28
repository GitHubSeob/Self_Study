/*
S�� ���� ��ġ, E�� ���� ��ġ, Len�� �������� ���� �迭�̴�.
���� ��ġ�� �ǹ��ϴ� x�� 1���� D���� �ݺ��Ѵ�.
DP�� 0���� �ʱ�ȭ�߱� ������ min �Լ��� �̿��ϱ� ���� DP[x]�� ���� DP[x-1]+1�� ���� �����Ѵ�.
���� ������ �� ���� ��ġ�� x�� �������� ã��,
DP[x]�� ���� ������ ���� ������ DP �� + �������� ���� �� �� ���� ���� DP[x]�� �����Ѵ�.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0;
	int D = 0;

	cin >> N >> D;

	vector<int>DP(D + 1, 0);
	vector<int>S(N, 0);
	vector<int>E(N, 0);
	vector<int>Len(N, 0);

	int x = 0;
	for (x = 0; x < N; ++x) {
		cin >> S[x] >> E[x] >> Len[x];
	}
	int y = 0;

	for (x = 1; x <= D; ++x) {
		DP[x] = DP[x - 1] + 1;
		for (y = 0; y < N; ++y) {
			if (x == E[y])
				DP[x] = min(DP[x], DP[S[y]] + Len[y]);
		}
	}
	cout << DP[D];
}