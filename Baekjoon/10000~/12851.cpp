/*
N부터 출발하여 K에 도착하는 문제이다.
ans는 현재까지 가장 빠른 시간, sec는 x까지 걸린 시간이다.
queue<pair<int, int>>q를 선언한다. q(x좌표, 초)를 의미한다.
BFS이므로 같은 곳을 재방문 하지 못하도록 visit 배열을 사용한다.
x=N부터 큐에 집어넣고, 큐가 빌 때까지 while 문을 반복한다.
불필요한 작동을 하지 않기 위해 ans>=sec라는 조건을 건다.
x가 K에 도착했을 때, ans>sec 이면 ans를 갱신하고 개수를 1로 초기화시킨다.
ans=sec 이면 개수를 1 증가시킨다.
x가 K에 도착하지 못했을 때, x가 이동할 위치를 n_x로 두고, 각 조건에 맞으면 n_x, sec+1 상태로 큐에 집어넣는다.
BFS가 종료되면 답을 출력한다.
*/

#include <iostream>
#include <utility>
#include <queue>
#include <vector>
using namespace std;
int N, K;
int x, sec;
int ans = 100000;
int cnt;
vector<bool>visit(100001);

void Hide() {
	queue<pair<int, int>>q;
	q.push({ N, 0 });
	visit[N] = true;
	while (!q.empty()) {
		x = q.front().first;
		sec = q.front().second;
		visit[x] = true;
		q.pop();
		if (ans >= sec) {
			if (x == K) {
				if (ans > sec) {
					ans = sec;
					cnt = 1;
				}
				else cnt++;
			}
			else {
				int n_x = x + 1;
				if (n_x <= 100000 && !visit[n_x])
					q.push({ n_x, sec + 1 });
				n_x = x - 1;
				if (n_x >= 0 && !visit[n_x])
					q.push({ n_x, sec + 1 });
				n_x = x * 2;
				if (n_x <= 100000 && !visit[n_x])
					q.push({ n_x, sec + 1 });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	Hide();
	cout << ans << "\n" << cnt;
}