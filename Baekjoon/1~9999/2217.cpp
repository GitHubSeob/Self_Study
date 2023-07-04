#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), idx(0), answer(0);

	cin >> N;
	vector<int>rope(N, 0);

	for (idx = 0; idx < N; ++idx) {
		cin >> rope[idx];
	}

	sort(rope.begin(), rope.end(), greater<int>());

	for (idx = 0; idx < N; ++idx) {
		answer = max(answer, rope[idx] * (idx + 1));
	}
	cout << answer;
}

//문제풀이: https://githubseob.tistory.com/268