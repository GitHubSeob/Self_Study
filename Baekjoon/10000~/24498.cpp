#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0);
	cin >> N;
	vector<int>tower(N, 0);
	for (int idx = 0; idx < N; ++idx) cin >> tower[idx];

	int answer(max(tower[0],tower.back()));	

	for (int idx = 1; idx + 1 < N; ++idx) {
		answer = max(answer, tower[idx] + min(tower[idx - 1], tower[idx + 1]));
	}
	cout << answer;
}

//문제풀이: https://githubseob.tistory.com/369