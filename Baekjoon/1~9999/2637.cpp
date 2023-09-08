#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

vector<map<int, int>>ingr;
vector<vector<pii>>input;
vector<bool>isBase;
vector<int>indegree;
queue<int>q;
int N;

void topology_sort() {
	for (int i = 1; i <= N; ++i) {
		int num = q.front();
		q.pop();
		for (int idx = 0; idx < input[num].size(); ++idx) {
			int next = input[num][idx].first;
			int cnt = input[num][idx].second;
			if (isBase[num] == true) {
				ingr[next][num] += cnt;
			}
			else {
				for (auto iter = ingr[num].begin(); iter != ingr[num].end(); ++iter) {
					ingr[next][iter->first] += (iter->second * cnt);
				}
			}
			--indegree[next];
			if (indegree[next] == 0) q.push(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int M(0);
	cin >> N >> M;
	isBase = vector<bool>(N + 1, false);
	ingr = vector<map<int, int>>(N + 1);
	input = vector<vector<pii>>(N + 1);
	indegree = vector<int>(N + 1, 0);

	int X(0), Y(0), K(0);

	for (int idx = 0; idx < M; ++idx) {
		cin >> X >> Y >> K;
		input[Y].push_back({ X,K });
		++indegree[X];
	}
	for (int idx = 1; idx < N; ++idx) {
		if (indegree[idx] == 0) {
			q.push(idx);
			isBase[idx] = true;
		}
	}

	topology_sort();

	for (auto iter = ingr[N].begin(); iter != ingr[N].end(); ++iter) {
		cout << iter->first << " " << iter->second << '\n';
	}
}

//문제풀이: https://githubseob.tistory.com/335