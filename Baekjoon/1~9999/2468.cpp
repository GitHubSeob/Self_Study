#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>>loc = { {-1,0},{1,0},{0,-1},{0,1} };
vector<vector<int>>land;
vector <vector<bool>>visit;
int y, x;
int N;
int max_high;
int max_safetyzone;

void Rain() {
	int water = 0;
	int safetyzone = 0;
	queue<pair<int, int>>up;
	while (max_high--) {
		safetyzone = 0;
		fill(visit.begin(), visit.end(), vector<bool>(N, false));
		for (y = 0; y < N; ++y) {
			for (x = 0; x < N; ++x) {
				if (land[y][x] > water && !visit[y][x]) {
					visit[y][x] = true;
					up.push({ y,x });
					while (!up.empty()) {
						for (int cnt = 0; cnt < 4; ++cnt) {
							int next_y = up.front().first + loc[cnt][0];
							int next_x = up.front().second + loc[cnt][1];
							if (next_y >= 0 && next_y < N && next_x >= 0 && next_x < N) {
								if (land[next_y][next_x] > water && !visit[next_y][next_x]) {
									visit[next_y][next_x] = true;
									up.push({ next_y,next_x });
								}
							}
						}
						up.pop();
					}
					safetyzone++;
				}
			}
		}
		if (safetyzone >= max_safetyzone)
			max_safetyzone = safetyzone;
		water++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	land = vector<vector<int>>(N, vector<int>(N, 0));
	visit = vector<vector<bool>>(N, vector<bool>(N, false));

	for (y = 0; y < N; ++y) {
		for (x = 0; x < N; ++x) {
			cin >> land[y][x];
			max_high = max(max_high, land[y][x]);
		}
	}
	Rain();

	cout << max_safetyzone << "\n";
}

//문제풀이: https://githubseob.tistory.com/31