#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int R(0), C(0);
	cin >> R >> C;
	int y(0), x(0);
	vector<vector<char>>map(R, vector<char>(C, ' '));
	vector<vector<bool>>visit(R, vector<bool>(C, false));
	queue<vector<int>>water;
	queue<vector<int>>loc;

	for (y = 0; y < R; ++y) {
		for (x = 0; x < C; ++x) {
			cin >> map[y][x];
			if (map[y][x] == '*')
				water.push({ y,x,0 });
			else if (map[y][x] == 'S') {
				loc.push({ y,x,0 });
				visit[y][x] = true;
			}
		}
	}
	int pre(0), cnt(0);
	int w_pre(0), w_cnt(0);
	int idx(0);
	while (1) {
		while (!water.empty()) {
			y = water.front()[0];
			x = water.front()[1];
			w_cnt = water.front()[2];

			if (w_pre != w_cnt)
				break;
			
			else water.pop();
			for (idx = 0; idx < 4; ++idx) {
				int n_y(y + dy[idx]);
				int n_x(x + dx[idx]);
				if (n_y >= 0 && n_y < R && n_x >= 0 && n_x < C) {
					if (map[n_y][n_x] == '.' && !visit[n_y][n_x]) {
						map[n_y][n_x] = '*';
						water.push({ n_y,n_x,w_cnt + 1 });
					}
				}
			}			
		}
		w_pre = w_cnt;

		while (!loc.empty()) {
			y = loc.front()[0];
			x = loc.front()[1];
			cnt = loc.front()[2];
			if (pre != cnt)
				break;			
			else loc.pop();
			for (idx = 0; idx < 4; ++idx) {
				int n_y(y + dy[idx]);
				int n_x(x + dx[idx]);
				if (n_y >= 0 && n_y < R && n_x >= 0 && n_x < C) {
					if (map[n_y][n_x] == '.' && !visit[n_y][n_x]) {
						visit[n_y][n_x] = true;
						loc.push({ n_y,n_x,cnt + 1 });
					}
					else if (map[n_y][n_x] == 'D') {
						cout << cnt + 1;
						exit(0);
					}
				}
			}
		}
		pre = cnt;
		if (loc.empty()) break;
	}
	cout << "KAKTUS";
}

//문제풀이: https://githubseob.tistory.com/149