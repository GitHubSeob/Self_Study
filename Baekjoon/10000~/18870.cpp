#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0;
	int idx = 0;
	cin >> N;
	vector<int>X(N, 0);
	vector<int>X2(N, 0);

	for (idx = 0; idx < N; ++idx) {
		cin >> X[idx];
		X2[idx] = X[idx];
	}
	sort(X.begin(), X.end());
	X.erase(unique(X.begin(), X.end()), X.end());

	for (int idx = 0; idx < X2.size(); ++idx)
		cout << upper_bound(X.begin(), X.end(), X2[idx]) -
		(X.begin() + 1) << ' ';
}

//문제풀이: https://githubseob.tistory.com/65