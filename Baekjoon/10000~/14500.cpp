#include <bits/stdc++.h>
using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int answer, N, M;

vector<vector<int>>board;
vector<vector<bool>>visited;

void DFS(int y, int x, int cnt, int val) {
	if (cnt == 4) {
		answer = max(answer, val);
		return;
	}
	for (int idx = 0; idx < 4; ++idx) {
		int ny = y + dy[idx];
		int nx = x + dx[idx];
		if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
		if (visited[ny][nx] == true) continue;
		visited[ny][nx] = true;
		DFS(ny, nx, cnt + 1, val + board[ny][nx]);
		visited[ny][nx] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	board = vector<vector<int>>(N, vector<int>(M, 0));
	visited = vector<vector<bool>>(N, vector<bool>(M, false));

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> board[y][x];
		}
	}

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			visited[y][x] = true;
			DFS(y, x, 1, board[y][x]);
			visited[y][x] = false;
		}
	}

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			int sum(0);
			sum += board[y][x];

			if (y - 1 >= 0)	sum += board[y - 1][x];
			if (y + 1 < N)	sum += board[y + 1][x];
			if (x - 1 >= 0)	sum += board[y][x - 1];
			if (x + 1 < M)	sum += board[y][x + 1];

			if (y - 1 >= 0) answer = max(answer, sum - board[y - 1][x]);
			else answer = max(answer, sum);

			if (y + 1 < N) answer = max(answer, sum - board[y + 1][x]);
			else answer = max(answer, sum);

			if (x - 1 >= 0) answer = max(answer, sum - board[y][x - 1]);
			else answer = max(answer, sum);

			if (x + 1 < M) answer = max(answer, sum - board[y][x + 1]);
			else answer = max(answer, sum);
		}
	}
	cout << answer;
}

//문제풀이: https://githubseob.tistory.com/346