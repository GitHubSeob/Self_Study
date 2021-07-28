/*
S는 시작 위치, E는 도착 위치, Len은 지름길의 길이 배열이다.
현재 위치를 의미하는 x를 1부터 D까지 반복한다.
DP를 0으로 초기화했기 때문에 min 함수를 이용하기 위해 DP[x]의 값에 DP[x-1]+1의 값을 저장한다.
여러 지름길 중 도착 위치가 x인 지름길을 찾고,
DP[x]의 값과 지름길 시작 지점의 DP 값 + 지름길의 길이 중 더 작은 값을 DP[x]에 저장한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0;
	int D = 0;

	cin >> N >> D;

	vector<int>DP(D + 1, 0);
	vector<int>S(N, 0);
	vector<int>E(N, 0);
	vector<int>Len(N, 0);

	int x = 0;
	for (x = 0; x < N; ++x) {
		cin >> S[x] >> E[x] >> Len[x];
	}
	int y = 0;

	for (x = 1; x <= D; ++x) {
		DP[x] = DP[x - 1] + 1;
		for (y = 0; y < N; ++y) {
			if (x == E[y])
				DP[x] = min(DP[x], DP[S[y]] + Len[y]);
		}
	}
	cout << DP[D];
}