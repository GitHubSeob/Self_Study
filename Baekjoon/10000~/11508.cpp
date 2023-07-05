#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), idx(0), answer(0);

	cin >> N;
	vector<int>cost(N, 0);

	for (idx = 0; idx < N; ++idx) {
		cin >> cost[idx];
	}
	sort(cost.begin(), cost.end(), greater<int>());

	for (idx = 0; idx < N; ++idx) {
		if ((idx + 1) % 3 != 0) {
			answer += cost[idx];
		}
	}
	cout << answer;
}

//문제풀이: https://githubseob.tistory.com/274