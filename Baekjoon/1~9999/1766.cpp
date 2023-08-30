#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>>pq;
vector<vector<int>>tree;
vector<int>inDegree;
int N;

void topology_sort() {
	for (int idx = 1; idx <= N; ++idx) {
		int num = pq.top();
		cout << pq.top() << ' ';
		pq.pop();

		for (int idx2 = 0; idx2 < tree[num].size(); ++idx2) {
			int next = tree[num][idx2];
			--inDegree[next];
			if (inDegree[next] == 0) pq.push(next);
		}		
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int M(0);
	cin >> N >> M;
	tree = vector<vector<int>>(N + 1);
	inDegree = vector<int>(N + 1, 0);
	int node1(0), node2(0);
	for (int idx = 0; idx < M; ++idx) {
		cin >> node1 >> node2;
		tree[node1].push_back(node2);
		++inDegree[node2];
	}
	for (int idx = 1; idx <= N; ++idx) {
		if (inDegree[idx] == 0) pq.push(idx);
	}
	topology_sort();
}

//문제풀이: https://githubseob.tistory.com/325