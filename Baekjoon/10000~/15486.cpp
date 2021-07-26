/*
14501번 문제에서 N, T의 범위가 증가한 문제이다.
이전에 푼 방식으로 하면 시간 초과가 나기 때문에 다른 방법으로 푼다.

1일 날 하루 걸리는 상담을 끝내면 2일 상담 시작 전에 받는다고 가정한다.
그렇기 때문에 x는 1부터 N+1까지 반복한다.
DP[x]는 DP[x-1]보다 작을 경우 DP[x-1] 값으로 바꾼다.
x 일에 상담을 시작하면 상담이 끝나고 돈을 받는 x+T[x] 일에
x 일까지 번 돈 + x 일에 시작하는 상담비와 이미 저장된 DP[x+T[x]] 값 중 더 큰 값을 저장한다.
모든 반복이 종료되면 DP[N+1] 값을 출력한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	int x = 0;
	cin >> N;
	vector<int>DP(N+2, 0);
	vector<int>T(N+2, 0);
	vector<int>P(N+2, 0);

	for (x = 1; x <= N; ++x) {
		cin >> T[x] >> P[x];
	}
	for (x = 1; x <= N + 1; ++x) {
		DP[x] = max(DP[x], DP[x - 1]);
		if (x + T[x] <= N + 1)
			DP[x + T[x]] = max(DP[x] + P[x], DP[x + T[x]]);
	}
	cout << DP[N + 1];
}