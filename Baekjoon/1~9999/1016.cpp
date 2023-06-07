#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long idx(0), idx2(0), cnt(0);
	long long min_n(0), max_n(0);	

	cin >> min_n >> max_n;

	vector<bool>answer(max_n - min_n + 1, true);

	for (idx = 2; idx <= sqrt(max_n); ++idx) {
		for (idx2 = min_n / (idx * idx); idx2 <= max_n / (idx * idx); ++idx2) {
			if ((idx * idx * idx2 - min_n) >= 0) {
				answer[idx * idx * idx2 - min_n] = false;
			}
		}
	}

	for (idx = 0; idx < answer.size(); ++idx) {
		if (answer[idx] == true)
			cnt++;
	}

	cout << cnt;
}

//문제풀이: https://githubseob.tistory.com/200