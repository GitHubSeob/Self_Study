#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int idx(0), idx2(0), N(0);
	cin >> N;
	vector<int>won(N + 1, -1);
	vector<int>coin = { 2,5 };

	won[0] = 0;

	for (idx = 0; idx < coin.size(); ++idx) {
		for (idx2 = 1; idx2 <= N; ++idx2) {
			if (idx2 >= coin[idx] && won[idx2 - coin[idx]] != -1) {
				won[idx2] = won[idx2 - coin[idx]] + 1;
			}
		}
	}

	cout << won[N];
}

//문제풀이: https://githubseob.tistory.com/266