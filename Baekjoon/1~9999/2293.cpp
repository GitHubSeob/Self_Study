#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0;
	int k = 0;
	int x = 0;
	int cnt = 0;
	cin >> n >> k;
	vector<int>DP(k + 1, 0);
	vector<int>coin(n, 0);

	for (x = 0; x < n; ++x) {
		cin >> coin[x];
	}

	DP[0] = 1;
	for (cnt = 0; cnt < n; ++cnt) {
		for (x = coin[cnt]; x <= k; ++x) {
			DP[x] += DP[x - coin[cnt]];
		}
	}

	cout << DP[k];
}

//문제풀이: https://githubseob.tistory.com/12