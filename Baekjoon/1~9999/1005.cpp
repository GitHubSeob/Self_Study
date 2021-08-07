#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>>order;
vector<vector<int>>foundation;
vector<int>answer;
vector<int>building_time;
vector<int>visit;
int goal;

void Build(int start) {
	if (visit[start] == 0&&!visit[goal]) {
		visit[start] = 1;
		int next = 0;
		int done = 0;
		int f_cnt = 0;
		for (int o_cnt = 0; o_cnt < order[start].size(); ++o_cnt) {
			next = order[start][o_cnt];
			int max_time = 0;
			for (f_cnt = 0; f_cnt < foundation[next].size(); ++f_cnt) {
				if (!visit[foundation[next][f_cnt]]) {
					break;
				}
				max_time = max(max_time, answer[foundation[next][f_cnt]]);
			}
			if (f_cnt == foundation[next].size()) {
				answer[next] = max_time + building_time[next];
				Build(next);
			}
		}
	}
}

void Init(int size) {
	order = vector<vector<int>>(size + 1, vector<int>(0, 0));
	foundation = vector<vector<int>>(size + 1, vector<int>(0, 0));
	answer = vector<int>(size + 1, 0);
	building_time = vector<int>(size + 1, 0);
	visit = vector<int>(size + 1, 0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T = 0;
	int N = 0, K = 0;
	int y = 0, x = 0;
	int num1 = 0, num2 = 0;;
	int start = 0;
	
	cin >> T;

	while (T--) {
		cin >> N >> K;

		Init(N);

		for (x = 1; x <= N; ++x) {
			cin >> building_time[x];
		}

		for (y = 1; y <= K; ++y) {
			cin >> num1 >> num2;
			order[num1].push_back(num2);
			foundation[num2].push_back(num1);
		}
		cin >> goal;

		for (x = 1; x <= N; ++x) {
			if (foundation[x].size() == 0) {
				answer[x] = building_time[x];
				Build(x);
			}
		}
		cout << answer[goal] << "\n";
	}
}

//문제풀이: https://githubseob.tistory.com/18