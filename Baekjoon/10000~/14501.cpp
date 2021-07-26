/*
x 일에 시작하면 걸리는 일 수: T[x]
x 일에 시작하면 받는 금액: P[x]
x보다 작은 값을 y라 둔다.
x 일일 때 y 일에 상담을 시작하면 x 일 이전에 끝나는 경우
DP[x] = DP[y] + P[y]라 둔다.
y는 1부터 x-1까지 돌면서 가장 큰 값을 DP[x]에 저장한다.
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