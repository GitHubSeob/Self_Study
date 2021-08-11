#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>>iceberg;
vector<vector<int>>sub;
vector<vector<int>>near = { {-1,0},{1,0},{0,-1},{0,1} };
queue<pair<pair<int, int>, int>>q;
vector<vector<bool>>visit;

int N, M;

void Mass(int i, int j) {
	visit[i][j] = true;
	for (int cnt = 0; cnt < 4; ++cnt) {
		int n_i = i + near[cnt][0];
		int n_j = j + near[cnt][1];
		if (n_i >= 0 && n_i < N && n_j >= 0 && n_j < M) {
			if (iceberg[n_i][n_j] != 0 && !visit[n_i][n_j]) {
				Mass(n_i, n_j);
			}
		}
	}
}

void Subtract() {
	int y = 0, x = 0;
	for (y = 0; y < N; ++y) {
		for (x = 0; x < M; ++x) {
			iceberg[y][x] -= sub[y][x];
			if (iceberg[y][x] <= 0)
				iceberg[y][x] = 0;			
		}
	}
	fill(sub.begin(), sub.end(), vector<int>(M,0));
}

int Melt() {
	int last_year = 0;
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int year = q.front().second;
		q.pop();
		if (last_year == year - 1) {
			int mass_cnt = 0;
			Subtract();
			fill(visit.begin(), visit.end(), vector<bool>(M, false));
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < M; ++j) {
					if (iceberg[i][j] != 0 && !visit[i][j]) {
						Mass(i, j);
						mass_cnt++;
					}
				}
			}
			if (mass_cnt >= 2)
				return year;
		}
		for (int cnt = 0; cnt < 4; cnt++) {
			int n_y = y + near[cnt][0];
			int n_x = x + near[cnt][1];
			if (n_y >= 0 && n_y < N && n_x >= 0 && n_x < M) {
				if (iceberg[n_y][n_x] == 0)
					sub[y][x]++;
			}
		}
		if (iceberg[y][x] - sub[y][x] > 0) {
			q.push({ {y,x},year + 1 });
		}
		last_year = year;

	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	iceberg = vector<vector<int>>(N, vector<int>(M, 0));
	sub = vector<vector<int>>(N, vector<int>(M, 0));
	visit = vector<vector<bool>>(N, vector<bool>(M, false));

	int y = 0, x = 0;
	for (y = 0; y < N; ++y) {
		for (x = 0; x < M; ++x) {
			cin >> iceberg[y][x];
			if (iceberg[y][x] != 0)
				q.push({ { y,x },0 });
		}
	}

	cout << Melt();

}

//문제풀이: https://githubseob.tistory.com/32