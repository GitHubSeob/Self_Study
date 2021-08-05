#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, M;
vector<vector<int>>matrix;
vector<vector<int>>visit;
vector<int> dx = { -1,1,0,0 };
vector<int> dy = { 0,0,1,-1 };
int dis = 1;

int BFS() {
	queue<vector<int>>q;
	q.push({ 1,1,1,1 });
	while (!q.empty()) {
		int y = q.front()[0];
		int x = q.front()[1];
		int smash = q.front()[2];
		int dis = q.front()[3];
		q.pop();
		if (y == N && x == M)	return dis;
		for (int cnt = 0; cnt < 4; ++cnt) {
			int n_y = y + dy[cnt];
			int n_x = x + dx[cnt];
			if (n_y >= 1 && n_y <= N && n_x >= 1 && n_x <= M) {
				if (visit[n_y][n_x] == 1 && smash == 1) {
					if (matrix[n_y][n_x] == 0) {
						visit[n_y][n_x] = 2;
						q.push({ n_y,n_x,1,dis + 1 });
					}
					else {
						visit[n_y][n_x] = 2;
						q.push({ n_y, n_x, 0, dis + 1 });
					}

				}
				else if (visit[n_y][n_x] == 0) {
					visit[n_y][n_x] = 1;
					if (matrix[n_y][n_x] == 1) {
						if (smash == 1)
							q.push({ n_y,n_x,0,dis + 1 });
					}
					else {
						q.push({ n_y,n_x,smash,dis + 1 });
					}
				}

			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	bool smash = true;
	string number = "";
	int y = 0, x = 0;
	cin >> N >> M;

	matrix.resize(N + 1, vector<int>(M + 1, 0));
	visit.resize(N + 1, vector<int>(M + 1, 0));

	for (y = 1; y <= N; ++y) {
		cin >> number;
		for (x = 1; x <= M; ++x) {
			matrix[y][x] = number[x - 1] - '0';
		}
	}
	cout << BFS();
}
//문제풀이: https://githubseob.tistory.com/14