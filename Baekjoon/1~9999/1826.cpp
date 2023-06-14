#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long N(0), idx(0), gas(0), loc(0), answer(0);

	cin >> N;

	vector<pair<long long, long long>>gs(N, { 0,0 });
	priority_queue<long long>pq;

	for (idx = 0; idx < N; ++idx) {
		cin >> gs[idx].first >> gs[idx].second;
	}

	sort(gs.begin(), gs.end());

	cin >> loc >> gas;

	idx = 0;

	while (gas < loc) {
		for (idx; idx < N; ++idx) {
			if (gas >= gs[idx].first) {
				pq.push(gs[idx].second);
			}
			else break;
		}
		if (pq.empty()) {
			break;
		}
		else if (!pq.empty()) {
			answer++;
			gas += pq.top();
			pq.pop();
		}

	}
	if (gas >= loc) {
		cout << answer;
		return 0;
	}
	else cout << "-1";
}

//문제풀이: https://githubseob.tistory.com/203