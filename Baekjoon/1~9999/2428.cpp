#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0);
	cin >> N;
	
	vector<double>files(N, 0);
	int file(0);

	for (int idx = 0; idx < N; ++idx) {
		cin >> file;
		files[idx] = file;
	}

	sort(files.begin(), files.end());

	ll answer(0);

	for (int idx = 0; idx < N; ++idx) {
		file = files[idx];
		int start_idx = lower_bound(files.begin(), files.begin() + idx, file * 0.9) - files.begin();
		answer += idx - start_idx;
	}


	cout << answer;
}

//문제풀이: https://githubseob.tistory.com/367