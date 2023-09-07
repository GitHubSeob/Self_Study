#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int max_node(0), target(0);

	while (1) {
		cin >> max_node >> target;
		if (max_node == 0 && target == 0) break;
		
		vector<int>nodes(max_node, 0);
		unordered_map<int, vector<int>>tree;
		unordered_map<int, int>parent_map;

		for (int idx = 0; idx < max_node; ++idx) {
			cin >> nodes[idx];
		}
		
		int parent_idx(-1);
		for (int idx = 1; idx < nodes.size(); ++idx) {
			if (nodes[idx - 1] + 1 < nodes[idx]) {
				++parent_idx;				
			}
			int parent_node = nodes[parent_idx];
			tree[parent_node].push_back(nodes[idx]);
			parent_map[nodes[idx]] = parent_node;
		}

		int ancestor_node(0), answer(0);
		ancestor_node = parent_map[parent_map[target]];
		
		for (int idx = 0; idx < tree[ancestor_node].size(); ++idx) {
			int child_node = tree[ancestor_node][idx];			
			if (child_node == parent_map[target]) continue;			
			answer += tree[child_node].size();
		}
		cout << answer << '\n';
	}
}

//문제풀이: https://githubseob.tistory.com/330