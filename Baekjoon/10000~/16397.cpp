#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N(0), T(0), G(0);
	int idx(0);

	cin >> N >> T >> G;

	queue<pair<int, int>>q;
	vector<bool>visit(100000, false);

	q.push({ N,0 });
	visit[N] = true;

	while (!q.empty()) {
		int num = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cnt > T)
			break;
		else if (num == G) {
			cout << cnt;
			return 0;
		}

		if (num + 1 <= 99999 && !visit[num + 1]) {
			q.push({ num + 1,cnt + 1 });
			visit[num + 1] = true;
		}

		num *= 2;
		if (num <= 99999) {
			for (idx = 10000; idx >= 1; idx /= 10) {
				if ((num / idx) != 0) {
					if (!visit[num - idx]) {
						q.push({ num - idx, cnt + 1 });
						visit[num - idx] = true;
					}
					break;
				}
			}
		}
	}
	cout << "ANG";
}

//문제풀이: https://githubseob.tistory.com/150