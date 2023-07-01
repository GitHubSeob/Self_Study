#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>>road;
vector<vector<int>>min_time;

struct cmp {
	bool operator()(pair<int, int>a, pair<int, int>b) {
		return a.second > b.second;
	}
};

void Dijkstra(int start) {
	priority_queue<pair<int, int>,vector<pair<int, int>>, cmp>pq; // 노드,시간
	pq.push({start,0});
	int town(0), time(0), idx(0);
		
	pq.push({start, 0});
	
	while (!pq.empty()) {
		town = pq.top().first;
		time = pq.top().second;
		pq.pop();
		for (idx = 0; idx < road[town].size(); ++idx) {
			int next_town = road[town][idx].first;
			int next_time = road[town][idx].second;
			if (min_time[start][next_town] > next_time + time) {
				min_time[start][next_town] = next_time + time;
				pq.push({ next_town, next_time + time });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), M(0), X(0), idx(0), idx2(0), town1(0), town2(0), time(0), answer(0);
	cin >> N >> M >> X;

	road = vector<vector<pair<int, int>>>(N + 1);
	min_time = vector<vector<int>>(N + 1, vector<int>(N + 1, 99999999));

	for (idx = 0; idx < M; ++idx) {
		cin >> town1 >> town2 >> time;
		road[town1].push_back({ town2, time });
	}

	for (idx = 1; idx <= N; ++idx) {
		Dijkstra(idx);		
	}

	for (idx = 1; idx <= N; ++idx) {
		if (idx != X) {
			answer = max(answer, min_time[idx][X] + min_time[X][idx]);
		}
	}
	cout << answer;
}

//문제풀이: https://githubseob.tistory.com/255