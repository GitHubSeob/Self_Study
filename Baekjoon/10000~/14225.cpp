#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N = 0;
	int i = 0, j = 0;
	int sum = 0;
	cin >> N;
	vector<int>seq(N, 0);
	int seq_sum;
	for (i = 0; i < N; ++i) {
		cin >> seq[i];
	}

	sort(seq.begin(), seq.end());
	seq_sum = 0;
	for (i = 1; i < (1 << N); ++i) {
		sum = 0;
		for (j = 0; j < N; ++j) {
			if (i & (1 << j)) sum += seq[j];
		}
		if (seq_sum + 1 < sum) {
			cout << seq_sum + 1;
			return 0;
		}
		else if (seq_sum + 1 == sum)seq_sum = sum;
	}

	cout << seq_sum + 1;
}

//문제풀이: https://githubseob.tistory.com/36