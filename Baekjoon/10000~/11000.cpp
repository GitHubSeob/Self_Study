#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), idx(0), answer(0), cnt(0);
	cin >> N;
	vector<pair<int, int>>course(N);
	priority_queue<int, vector<int>, greater<int>>pq;

	for (idx = 0; idx < N; ++idx) {
		cin >> course[idx].first >> course[idx].second;
	}

	sort(course.begin(), course.end());

	for (idx = 0; idx < N; ++idx) {
		while (!pq.empty() && course[idx].first >= pq.top()) {
			pq.pop();
		}
		if (pq.empty() || course[idx].first < pq.top()) {
			pq.push(course[idx].second);
		}
		cnt = pq.size();
		answer = max(answer, cnt);
	}
	cout << answer;
}

//문제풀이: https://githubseob.tistory.com/272