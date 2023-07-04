#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), M(0), idx(0), idx2(0);
	int cnt(0), prev(0), max_cnt(0), sum(0);

	cin >> N;
	vector<int>crane(N + 1);

	for (idx = 0; idx < N; ++idx) {
		cin >> crane[idx];
	}

	cin >> M;

	vector<int>box(M, 0);
	for (idx = 0; idx < M; ++idx) {
		cin >> box[idx];
	}

	sort(crane.begin(), crane.end(), greater<int>());
	sort(box.begin(), box.end());

	if (crane[0] < box.back()) {
		cout << -1;
		return 0;
	}

	for (idx = 0; idx < N; ++idx) {
		idx2 = lower_bound(box.begin(), box.end(), crane[idx + 1] + 1) - box.begin();
		sum = box.size() - idx2;
		cnt = sum - prev;
		max_cnt = max(max_cnt, (sum + idx) / (idx + 1));
		prev = sum;
	}
	cout << max_cnt;
}

//문제풀이: https://githubseob.tistory.com/273