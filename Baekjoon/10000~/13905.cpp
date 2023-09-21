#include <bits/stdc++.h>
using namespace std;

vector<int>parent;

struct Bridge {
	int island1;
	int island2;
	int limit;
};

bool cmp(Bridge& b1, Bridge& b2) {
	return b1.limit > b2.limit;
}

int find(int node) {
	if (parent[node] == node) return node;
	return parent[node] = find(parent[node]);
}

void Union(int node1, int node2) {
	node1 = find(node1);
	node2 = find(node2);
	if (node1 == node2) return;

	if (node1 > node2) swap(node1, node2);
	parent[node2] = node1;
}

bool isUnion(int node1, int node2) {
	if (find(node1) == find(node2)) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), M(0);
	cin >> N >> M;

	vector<Bridge>bridges(M);

	int start(0), end(0);
	cin >> start >> end;

	int island1(0), island2(0), limit(0);

	parent = vector<int>(N + 1, 0);
	for (int idx = 1; idx <= N; ++idx) parent[idx] = idx;

	for (int idx = 0; idx < M; ++idx) {
		cin >> bridges[idx].island1 >> bridges[idx].island2 >> bridges[idx].limit;
	}

	sort(bridges.begin(), bridges.end(), cmp);

	for (int idx = 0; idx < M; ++idx) {
		island1 = bridges[idx].island1;
		island2 = bridges[idx].island2;
		if (isUnion(island1, island2) == true) continue;
		else {
			Union(island1, island2);
			if (find(start) == find(end)) {
				cout << bridges[idx].limit;
				return 0;
			}
		}
	}
	cout << "0";
}

//문제풀이: https://githubseob.tistory.com/345