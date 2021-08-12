#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int>robot(3,0);
vector<vector<int>>Arr;
vector<pair<int, int>>loc = { { 0,-1 }, {1, 0}, {0, 1}, {-1, 0}  };
int clean_cnt;

void Clean() {
	if (Arr[robot[0]][robot[1]] == 0) clean_cnt++;
	Arr[robot[0]][robot[1]] = 2;

	while (1) {
		int dir = robot[2];
		int cnt = 0;
		for (cnt = 0; cnt < 4; ++cnt) {
			dir = robot[2];
			int n_y = robot[0] + loc[dir].first;
			int n_x = robot[1] + loc[dir].second;
			if (n_y >= 0 && n_y < N && n_x >= 0 && n_x < M) {
				if (Arr[n_y][n_x] == 0) {
					Arr[n_y][n_x] = 2;
					robot[0] = n_y;
					robot[1] = n_x;
					robot[2] = (dir + 1) % 4;
					clean_cnt++;
					break;
				}
				else {
					robot[2] = (dir + 1) % 4;
				}
			}
		}
		if (cnt == 4) {
			robot[0] += loc[(dir + 2) % 4].first;
			robot[1] += loc[(dir + 2) % 4].second;
			if (Arr[robot[0]][robot[1]] == 1)
				return;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int y = 0, x = 0;
	cin >> N >> M;
	cin >> robot[0] >> robot[1] >> robot[2];
	Arr = vector<vector<int>>(N, vector<int>(M, 0));
	
	robot[2] = (4 - robot[2]) % 4;	

	for (y = 0; y < N; ++y) {
		for (x = 0; x < M; ++x) {
			cin >> Arr[y][x];
		}
	}
	Clean();
	cout << clean_cnt;
}

//문제풀이: https://githubseob.tistory.com/35