#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int L(1), R, C;

int dz[6] = { 0,0,0,0,1,-1 };
int dy[6] = { 1,-1,0,0,0,0 };
int dx[6] = { 0,0,1,-1,0,0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int z(0), y(0), x(0);
	int idx(0);
	while (!(L == 0 && R == 0 && C == 0)) {
		bool esc(false);
		queue<vector<int>>loc;
		cin >> L >> R >> C;
		vector<vector<vector<char>>>map(L, vector<vector<char>>(R, vector<char>(C, ' ')));
		vector<vector<vector<bool>>>visit(L, vector<vector<bool>>(R, vector<bool>(C, false)));
		for (z = 0; z < L; ++z) {
			for (y = 0; y < R; ++y) {
				for (x = 0; x < C; ++x) {
					cin >> map[z][y][x];
					if (map[z][y][x] == 'S')
						loc.push({ z,y,x,0 });
				}
			}
		}
		while (!loc.empty() && !esc) {
			z = loc.front()[0];
			y = loc.front()[1];
			x = loc.front()[2];
			int cnt(loc.front()[3]);
			loc.pop();

			visit[z][y][x] = true;

			for (idx = 0; idx < 6; ++idx) {
				int n_z(z + dz[idx]);
				int n_y(y + dy[idx]);
				int n_x(x + dx[idx]);
				if (n_z >= 0 && n_z < L && n_y >= 0 && n_y < R && n_x >= 0 && n_x < C) {
					if (!visit[n_z][n_y][n_x]) {
						if (map[n_z][n_y][n_x] == '.') {
							visit[n_z][n_y][n_x] = true;
							loc.push({ n_z,n_y,n_x,cnt + 1 });
						}
						else if (map[n_z][n_y][n_x] == 'E') {
							cout << "Escaped in " << cnt + 1 << " minute(s).";
							esc = true;
							break;
						}
					}
				}
			}
		}
		if (!esc && !(L == 0 && R == 0 && C == 0))
			cout << "Trapped!";
		cout << '\n';
	}
}

//문제풀이: https://githubseob.tistory.com/147