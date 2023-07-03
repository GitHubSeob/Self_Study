#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), K(0), S(0), idx(0);
	int history1(0), history2(0), mid(0);
	cin >> N >> K;
	vector<vector<int>>history(N + 1, vector<int>(N + 1, 0));

	for (idx = 0; idx < K; ++idx) {
		cin >> history1 >> history2;
		history[history1][history2] = -1;
		history[history2][history1] = 1;
	}

	for (mid = 1; mid <= N; ++mid) {
		for (history1 = 1; history1 <= N; ++history1) {
			for (history2 = 1; history2 <= N; ++history2) {
				if (history[history1][mid] == 1 && history[mid][history2] == 1) {
					history[history1][history2] = 1;
				}
				else if (history[history1][mid] == -1 && history[mid][history2] == -1) {
					history[history1][history2] = -1;
				}
			}
		}
	}

	cin >> S;

	for (idx = 0; idx < S; ++idx) {
		cin >> history1 >> history2;
		cout << history[history1][history2] << '\n';
	}
}

//문제풀이: https://githubseob.tistory.com/261