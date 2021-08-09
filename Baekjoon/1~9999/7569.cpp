#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<vector<int>>>tomato;
queue<vector<int>>ripen;
vector<vector<vector<int>>>spread = { {{0,-1,0}},{{0,1,0}},{{0,0,1}},{{0,0,-1}},{{1,0,0}},{{-1,0,0}} };
int M, N, H;
int z, y, x;
int day;
int total;
int now;

int Storage() {
	while (!ripen.empty()) {
		z = ripen.front()[0];
		y = ripen.front()[1];
		x = ripen.front()[2];
		day = ripen.front()[3];
		ripen.pop();
		for (int cnt = 0; cnt < 6; ++cnt) {
			int n_z = z + spread[cnt][0][0];
			int n_y = y + spread[cnt][0][1];
			int n_x = x + spread[cnt][0][2];
			int n_day = day + 1;
			if (n_z >= 0 && n_z < H && n_y >= 0 && n_y < N && n_x >= 0 && n_x < M) {
				if (tomato[n_z][n_y][n_x] == 0) {
					ripen.push({ n_z, n_y, n_x, n_day });
					tomato[n_z][n_y][n_x] = 1;
					now++;
				}
			}
		}
	}
	if (now == total) {
		return day;
	}
	else  return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> M >> N >> H;
	tomato = vector<vector<vector<int>>>(H, vector<vector<int>>(N, vector<int>(M, 0)));

	for (z = 0; z < H; ++z) {
		for (y = 0; y < N; ++y) {
			for (x = 0; x < M; ++x) {
				cin >> tomato[z][y][x];
				if (tomato[z][y][x] == 1) ripen.push({ z,y,x,0 });
				if (tomato[z][y][x] == 0 || tomato[z][y][x] == 1) total++;
				if (tomato[z][y][x] == 1) now++;
			}
		}
	}
	cout << Storage();
}

//문제풀이: https://githubseob.tistory.com/26