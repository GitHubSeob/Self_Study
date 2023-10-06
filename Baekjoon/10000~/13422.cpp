#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T(0);
	cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		int N(0), M(0), K(0);
		cin >> N >> M >> K;
		vector<int>money(N, 0);
		int sum(0), answer(0);

		for (int idx = 0; idx < N; ++idx) cin >> money[idx];		

		for (int idx = 0; idx < M; ++idx) sum += money[idx];		

		if (sum < K) ++answer;

		for (int idx = 1; idx < N; ++idx) {
			sum -= money[idx - 1];
			sum += money[(idx + M - 1) % N];
			if (idx - 1 == (idx + M - 1) % N) break;
			if (sum < K) ++answer;
		}
		cout << answer << '\n';
	}
}