#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T(0), idx(0), idx2(0), K(0);
	string W("");
	cin >> T;
	while (T--) {
		cin >> W >> K;
		int answer1(10000), answer2(0);
		vector<vector<int>>alp(26, vector<int>(0, 0));
		vector<int>cnt(26, 0);

		for (idx = 0; idx < W.size(); ++idx) {
			cnt[W[idx] - 'a']++;
			alp[W[idx] - 'a'].push_back(idx);
		}

		for (idx = 0; idx < 26; ++idx) {
			if (cnt[idx] >= K) {
				for (idx2 = K - 1; idx2 < alp[idx].size(); ++idx2) {
					answer1 = min(answer1, alp[idx][idx2] - alp[idx][idx2 - K + 1] + 1);
					answer2 = max(answer2, alp[idx][idx2] - alp[idx][idx2 - K + 1] + 1);
				}

			}
		}

		if (answer1 == 10000 || answer2 == 0)
			cout << "-1\n";
		else
			cout << answer1 << " " << answer2 << '\n';
	}
}

//문제풀이: https://githubseob.tistory.com/208