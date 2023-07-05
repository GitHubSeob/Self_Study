#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define END loss.size() -1
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll N(0), idx(0), answer(0);

	cin >> N;
	vector<ll>loss(N, 0);
	for (idx = 0; idx < N; ++idx) {
		cin >> loss[idx];
	}

	sort(loss.begin(), loss.end());

	if (N % 2 == 0) {
		for (idx = 0; idx < N/2; ++idx) {
			answer = max(answer, loss[idx] + loss[END - idx]);
		}
	}
	else if (N % 2 != 0) {
		answer = loss[END];
		for (idx = 0; idx < N / 2; ++idx) {
			answer = max(answer, loss[idx] + loss[END - 1 - idx]);
		}
	}
	cout << answer;
}

//문제풀이: https://githubseob.tistory.com/275