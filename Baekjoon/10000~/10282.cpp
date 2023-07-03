#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 10000001
using namespace std;

int N;
vector<vector<pair<int, int>>>network;

struct cmp {
	bool operator()(pair<int, int>a, pair<int, int>b) {
		return a.second > b.second;
	}
};

void Dijkstra(int start) {
	int idx(0), com(0), time(0), cnt(0), max_time(0), next(0), ntime(0);
	priority_queue<pair<int, int>,vector<pair<int, int>>, cmp>pq;

	vector<int>log(N + 1, INF);
	log[start] = 0;

	pq.push({ start,0 });

	while (!pq.empty()) {
		com = pq.top().first;
		time = pq.top().second;
		pq.pop();
		for (idx = 0; idx < network[com].size(); ++idx) {
			next = network[com][idx].first;
			ntime = network[com][idx].second;
			if (log[next] > time + ntime) {
				log[next] = time + ntime;
				pq.push({ next, log[next] });
			}
		}
	}

	for (idx = 1; idx <= N; ++idx) {
		if (log[idx] != INF) {
			cnt++;
			max_time = max(max_time, log[idx]);
		}
	}
	cout << cnt << " " << max_time << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T(0), D(0), C(0), C1(0), C2(0),S(0), idx(0);
	cin >> T;

	while (T--) {
		cin >> N >> D >> C;
		network = vector<vector<pair<int, int>>>(N+1);
		for (idx = 0; idx < D; ++idx) {
			cin >> C1 >> C2 >> S;
			network[C2].push_back({ C1,S });
		}
		Dijkstra(C);
	}
}

//문제풀이: https://githubseob.tistory.com/263