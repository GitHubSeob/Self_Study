#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10000001
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n(0), m(0), idx(0), city1(0), city2(0), mid(0), cost(0);
	cin >> n >> m;
	vector<vector<int>>bus(n + 1, vector<int>(n + 1, MAX));
	for (idx = 0; idx < m; ++idx) {
		cin >> city1 >> city2 >> cost;
		bus[city1][city2] = min(bus[city1][city2], cost);
	}



	for (city1 = 1; city1 <= n; ++city1) {
		bus[city1][city1] = 0;
	}

	for (mid = 1; mid <= n; ++mid) {
		for (city1 = 1; city1 <= n; ++city1) {
			for (city2 = 1; city2 <= n; ++city2) {
				bus[city1][city2] = min(bus[city1][city2], bus[city1][mid] + bus[mid][city2]);
			}
		}
	}

	for (city1 = 1; city1 <= n; ++city1) {
		for (city2 = 1; city2 <= n; ++city2) {
			if (bus[city1][city2] == MAX) {
				bus[city1][city2] = 0;
			}
			cout << bus[city1][city2] << ' ';
		}
		cout << '\n';
	}
}

//문제풀이: https://githubseob.tistory.com/260