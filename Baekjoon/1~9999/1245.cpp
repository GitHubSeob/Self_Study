#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
vector<vector<int>>board;
vector<vector<bool>>visited;
int N, M;

struct compare {
	bool operator()(pii& c1, pii& c2) {
		return board[c1.first][c1.second] < board[c2.first][c2.second];
	}
};

priority_queue<pii, vector<pii>, compare>peak;

void BFS(int y, int x) {
	int max = board[y][x];
	queue<pii>q;
	q.push({ y,x });

	visited[y][x] = true;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int idx = 0; idx < 8; ++idx) {
			int ny = y + dy[idx];
			int nx = x + dx[idx];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if (visited[ny][nx] == true) continue;
			if (board[ny][nx] > max) continue;
			if (board[ny][nx] == 0) continue;
			if (board[ny][nx] > board[y][x]) continue;
			visited[ny][nx] = true;
			q.push({ ny,nx });
		}
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
			if (board[y][x] > 0) peak.push({ y,x });
		}
	}

	int answer(0);

	while (!peak.empty()) {
		int y = peak.top().first;
		int x = peak.top().second;
		peak.pop();
		if (visited[y][x] == true) continue;
		++answer;
		BFS(y, x);
	}

	cout << answer;
}

//문제풀이: https://githubseob.tistory.com/357