#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll N(0), idx(0), answer(0);
	cin >> N;
	vector<ll>tip(N, 0);

	for (idx = 0; idx < N; ++idx) {
		cin >> tip[idx];
	}

	sort(tip.begin(), tip.end(), greater<ll>());

	for (idx = 0; idx < N; ++idx) {
		answer += max(tip[idx] - idx, (long long)0);
	}
	cout << answer;
}

//문제풀이: https://githubseob.tistory.com/270