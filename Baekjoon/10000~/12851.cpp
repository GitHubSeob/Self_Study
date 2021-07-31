/*
N���� ����Ͽ� K�� �����ϴ� �����̴�.
ans�� ������� ���� ���� �ð�, sec�� x���� �ɸ� �ð��̴�.
queue<pair<int, int>>q�� �����Ѵ�. q(x��ǥ, ��)�� �ǹ��Ѵ�.
BFS�̹Ƿ� ���� ���� ��湮 ���� ���ϵ��� visit �迭�� ����Ѵ�.
x=N���� ť�� ����ְ�, ť�� �� ������ while ���� �ݺ��Ѵ�.
���ʿ��� �۵��� ���� �ʱ� ���� ans>=sec��� ������ �Ǵ�.
x�� K�� �������� ��, ans>sec �̸� ans�� �����ϰ� ������ 1�� �ʱ�ȭ��Ų��.
ans=sec �̸� ������ 1 ������Ų��.
x�� K�� �������� ������ ��, x�� �̵��� ��ġ�� n_x�� �ΰ�, �� ���ǿ� ������ n_x, sec+1 ���·� ť�� ����ִ´�.
BFS�� ����Ǹ� ���� ����Ѵ�.
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