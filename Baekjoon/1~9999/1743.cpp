/*
입력받은 좌표의 배열 값을 1로 설정한다.
범위 안에 있는 배열을 돌면서 배열 값이 1이면 음식물 쓰레기 개수인 cnt를 0으로 초기화하고 Garbage 함수를 실행한다.
방문할 때마다 cnt++ 하고 방문한 배열 값을 0으로 바꾼다.
이동할 수 있는 칸이 있으면 (범위 안에 들고 값이 1인 칸) 함수를 실행시켜 이동한다.
상하좌우에 쓰레기가 없으면 Garbage 함수를 종료한다.
방문하지 않은 칸에 1이 있으면 반복하고 cnt의 최댓값인 ans를 출력한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, K;
int ans;
int cnt;
vector<vector<int>>loc = { {-1,0},{1,0},{0,-1},{0,1} };
vector<vector<int>>Arr(101, vector<int>(101, 0));

void Garbage(int y, int x) {
	cnt++;
	Arr[y][x] = 0;
	for (int mv = 0; mv < 4; ++mv) {
		int n_y = y + loc[mv][0];
		int n_x = x + loc[mv][1];
		if (n_y >= 1 && n_y <= N && n_x >= 1 && n_x <= M) {
			if (Arr[n_y][n_x] == 1) {
				Garbage(n_y, n_x);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int y, x;

	cin >> N >> M >> K;

	while (K--) {
		cin >> y >> x;
		Arr[y][x] = 1;
	}

	for (y = 1; y <= N; ++y) {
		for (x = 1; x <= M; ++x) {
			if (Arr[y][x] == 1) {
				cnt = 0;
				Garbage(y, x);
				ans = max(ans, cnt);
			}
		}
	}
	cout << ans;
}