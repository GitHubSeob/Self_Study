#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

vector<vector<pii>>tree;
vector<bool>visited;
vector<int>remain_node;
int wood_strut, longest;
bool isFound;

void DFS(int node, int dist) {
	if (remain_node[node] > 1 && isFound == false) {
		wood_strut = dist;
		dist = 0;
		isFound = true;
	}
	if (remain_node[node] == 0) {
		if (isFound == false) wood_strut = dist;
		else longest = max(longest, dist);
	}
	else {
		for (int idx = 0; idx < tree[node].size(); ++idx) {
			int next_node = tree[node][idx].first;
			int next_dist = tree[node][idx].second;			
			--remain_node[next_node];
			if (visited[next_node] == true)	continue;
			visited[next_node] = true;
			DFS(next_node, dist + next_dist);
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), root_node(0);
	cin >> N >> root_node;

	isFound = false;
	tree = vector<vector<pii>>(N + 1);
	visited = vector<bool>(N + 1, false);
	remain_node = vector<int>(N + 1, 0);

	int node1(0), node2(0), dist(0);
	for (int idx = 1; idx < N; ++idx) {
		cin >> node1 >> node2 >> dist;
		tree[node1].push_back({ node2, dist });
		tree[node2].push_back({ node1, dist });
		++remain_node[node1];
		++remain_node[node2];
	}

	visited[root_node] = true;
	DFS(root_node, 0);

	cout << wood_strut << " " << longest;
}

//문제풀이: https://githubseob.tistory.com/333