#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), K(0), idx(0), idx2(0);
	int weight(0), price(0);
	long long answer(0);
	cin >> N >> K;

	priority_queue<int, vector<int>>pq;
	vector<pair<int, int>>jewel(N, { 0,0 });
	vector<int>bag(K, 0);

	for (idx = 0; idx < N; ++idx) {
		cin >> weight >> price;
		jewel[idx] = { weight,price };
	}
	for (idx = 0; idx < K; ++idx) {
		cin >> bag[idx];
	}

	sort(bag.begin(), bag.end());
	sort(jewel.begin(), jewel.end());

	for (idx = 0; idx < K; ++idx) {
		while (idx2 < N && bag[idx] >= jewel[idx2].first) {
			pq.push(jewel[idx2].second);
			++idx2;
		}
		if (!pq.empty()) {
			answer += pq.top();
			pq.pop();
		}
	}
	cout << answer;
}

//문제풀이: https://www.acmicpc.net/problem/1202