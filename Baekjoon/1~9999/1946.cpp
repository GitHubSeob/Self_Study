#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T(0);
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case) {
		int N(0);
		cin >> N;
		vector<pii>grade(N);
		for (int idx = 0; idx < N; ++idx) {
			cin >> grade[idx].first >> grade[idx].second;
		}
		sort(grade.begin(), grade.end());

		int left(0), right(1), answer(N);
		while (right < N) {
			if (grade[left].second < grade[right].second) {
				--answer;
			}
			else if (grade[left].second > grade[right].second) {
				left = right;
			}
			++right;
		}

		cout << answer << '\n';
	}
}

//문제풀이: https://githubseob.tistory.com/341