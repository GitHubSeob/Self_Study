#include <bits/stdc++.h>
#define pii pair<int, int> 
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), M(0);
	cin >> N >> M;

	priority_queue<pii, vector<pii>, greater<pii>>remain;
	int fee(0);
	for (int idx = 0; idx < N; ++idx) {
		cin >> fee;
		remain.push({ idx,fee });
	}

	vector<int>weight(M + 1, 0);
	for (int idx = 1; idx <= M; ++idx) {
		cin >> weight[idx];
	}

	vector<pii>parking(M + 1);
	queue<int>waiting;
	int answer(0), car(0);

	for (int idx = 0; idx < 2 * M; ++idx) {
		cin >> car;
		if (car < 0) {
			car *= -1;
			answer += parking[car].second * weight[car];
			remain.push(parking[car]);
			if (!waiting.empty()) {
				car = waiting.front();
				waiting.pop();
				parking[car] = remain.top();
				remain.pop();
			}
		}
		else if (car > 0) {
			if (remain.empty()) waiting.push(car);
			else {
				parking[car] = remain.top();
				remain.pop();
			}
		}
	}
	cout << answer;
}