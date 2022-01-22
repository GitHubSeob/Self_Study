#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };

vector<vector<char>>map;
queue<vector<int>>loc;
queue<vector<int>>fire;
vector<vector<bool>>visit;

int pre;
int cnt;
int f_pre;
int f_cnt;

void Init(int w, int h) {
	map = vector<vector<char>>(h, vector<char>(w, ' '));
	loc = queue<vector<int>>();
	fire = queue<vector<int>>();
	visit = vector<vector<bool>>(h, vector<bool>(w, false));
	pre = 0;
	cnt = 0;
	f_pre = 0;
	f_cnt = 0;
}

void burn(int w, int h) {
	int idx(0);
	while (!fire.empty()) {
		int f_y = fire.front()[0];
		int f_x = fire.front()[1];
		f_cnt = fire.front()[2];
		if (f_pre != f_cnt) break;
		fire.pop();
		for (idx = 0; idx < 4; ++idx) {
			int n_y = f_y + dy[idx];
			int n_x = f_x + dx[idx];
			if (n_y >= 0 && n_y < h && n_x >= 0 && n_x < w) {
				if (map[n_y][n_x] == '.') {
					map[n_y][n_x] = '*';
					fire.push({ n_y,n_x,f_cnt + 1 });
				}
			}
		}
	}
	f_pre = f_cnt;
}

bool move(int w, int h) {
	int idx(0);
	int y(0), x(0);
	while (!loc.empty()) { // 이동				
		y = loc.front()[0];
		x = loc.front()[1];
		cnt = loc.front()[2];
		if (pre != cnt) break;
		loc.pop();
		for (idx = 0; idx < 4; ++idx) {
			int n_y(y + dy[idx]);
			int n_x(x + dx[idx]);
			if (n_y >= 0 && n_y < h && n_x >= 0 && n_x < w) {
				if (!visit[n_y][n_x]) {
					if (map[n_y][n_x] == '.') {
						visit[n_y][n_x] = true;
						loc.push({ n_y,n_x,cnt + 1 });
					}
				}
			}
			else {
				cout << cnt + 1 << '\n';
				return true;
			}
		}
	}
	pre = cnt;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int y(0), x(0);
	int T(0);
	int w(0), h(0);

	cin >> T;

	while (T--) {
		bool esc(false);
		cin >> w >> h;
		Init(w, h);

		for (y = 0; y < h; ++y) {
			for (x = 0; x < w; ++x) {
				cin >> map[y][x];
				if (map[y][x] == '@') {
					loc.push({ y,x,0 });
					visit[y][x] = true;
				}
				else if (map[y][x] == '*')
					fire.push({ y,x,0 });
			}
		}

		while (1) {
			burn(w, h);
			esc = move(w, h);
			if (esc) break;
			else if (loc.empty()) {
				cout << "IMPOSSIBLE\n";
				break;
			}
		}
	}
}

//문제풀이: https://githubseob.tistory.com/148