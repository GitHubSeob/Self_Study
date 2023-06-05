#include <iostream>
#include <vector>
using namespace std;
int N, answer;
vector<int>board;

void DFS(int y) {
	int idx(0), prev(0);
	if (y >= N) {
		answer++;
		return;
	}
	for (idx = 0; idx < N; ++idx) {
		board[y] = idx;
		for (prev = 0; prev < y; ++prev) {
			if (board[prev] == board[y]) {
				board[y] = -1;
				break;
			}
			if ((y - prev) == board[y] - board[prev]) {
				board[y] = -1;
				break;
			}
			if ((y + board[y]) == (prev + board[prev])) {
				board[y] = -1;
					break;
			}
		}
		if (board[y] != -1) {
			DFS(y + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;

	board = vector<int>(N, -1);

	DFS(0);

	cout << answer;
}

//문제풀이: https://githubseob.tistory.com/199