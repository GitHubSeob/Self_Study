#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0;
	int y = 0, x = 0;
	cin >> N;

	vector<int>Arr(N, 0);
	vector<vector<int>>DP(N, vector<int>(2, 1));
	stack<int>seq;
	
	for (x = 0; x < N; ++x) {
		cin >> Arr[x];
	}

	for (y = 0; y < N; ++y) {
		for (x = 0; x < y; ++x) {
			if (Arr[x] < Arr[y]) {
				if (DP[y][0] <= DP[x][0]) {
					DP[y][0] = DP[x][0] + 1;
					DP[y][1] = x;
				}
			}
		}
	}

	int big = 0;
	int big_x = 0;
	for (x = 0; x < N; ++x) {
		if (big < DP[x][0]) {
			big = DP[x][0];
			big_x = x;
		}
	}
	cout << DP[big_x][0] << "\n";

	for (big; big > 0; --big) {
		seq.push(Arr[big_x]);
		big_x = DP[big_x][1];
	}
	while (!seq.empty()) {
		cout << seq.top() << " ";
		seq.pop();
	}
}

//문제풀이: https://githubseob.tistory.com/20