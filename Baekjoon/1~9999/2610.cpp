#include <iostream>
#include <vector>
#include <algorithm>
#define X -1
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), M(0), idx(0), P1(0), P2(0), mid(0);
	int rep(0), cnt(0), max_cnt(0);
	cin >> N >> M;
	vector<vector<int>>cmte(N + 1, vector<int>(N + 1, X));
	vector<bool>visited(N + 1, false);
	vector<int>answer;

	for (idx = 0; idx < M; ++idx) {
		cin >> P1 >> P2;
		cmte[P1][P2] = 1;
		cmte[P2][P1] = 1;
	}

	for (idx = 1; idx <= N; ++idx) {
		cmte[idx][idx] = 0;
	}

	for (mid = 1; mid <= N; ++mid) {
		for (P1 = 1; P1 <= N; ++P1) {
			for (P2 = 1; P2 <= N; ++P2) {
				if (cmte[P1][mid] == X || cmte[mid][P2] == X) {
					continue;
				}
				if (cmte[P1][P2] == X) {
					cmte[P1][P2] = cmte[P1][mid] + cmte[mid][P2];
				}
				else {
					cmte[P1][P2] = min(cmte[P1][P2], cmte[P1][mid] + cmte[mid][P2]);
				}
			}
		}
	}

	for (P1 = 1; P1 <= N; ++P1) {
		if (visited[P1] == false) {
			max_cnt = 10001;
			for (P2 = P1; P2 <= N; ++P2) {
				if (cmte[P1][P2] != X && visited[P2] == false) {
					visited[P2] = true;
					cnt = *max_element(cmte[P2].begin(), cmte[P2].end());
					if (max_cnt > cnt) {
						rep = P2;
						max_cnt = cnt;
					}
				}
			}
			answer.push_back(rep);
		}
	}

	sort(answer.begin(), answer.end());
	cout << answer.size() << '\n';
	for (idx = 0; idx < answer.size(); ++idx) {
		cout << answer[idx] << '\n';
	}
}

//문제풀이: https://githubseob.tistory.com/262