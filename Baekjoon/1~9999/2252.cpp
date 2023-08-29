#include <bits/stdc++.h>
using namespace std;
vector<int>inDegree;
vector<vector<int>>tree;
queue<int>q;
int N;

void topology_sort() {
	for (int idx = 1; idx <= N; ++idx) {
		int student = q.front();
		cout << student << ' ';
		q.pop();
		for (int idx2 = 0; idx2 < tree[student].size(); ++idx2) {
			int next = tree[student][idx2];
			--inDegree[next];
			if (inDegree[next] == 0) q.push(next);
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

	int student1(0), student2(0);
	for (int idx = 0; idx < M; ++idx) {
		cin >> student1 >> student2;
		tree[student1].push_back(student2);
		++inDegree[student2];
	}

	for (int idx = 1; idx <= N; ++idx) {
		if (inDegree[idx] == 0) {
			q.push(idx);
		}
	}

	topology_sort();
}

//문제풀이: https://githubseob.tistory.com/324