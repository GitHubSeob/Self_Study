#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


bool cmp(string a, string b) {
	return a + b > b + a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int K(0), N(0), idx(0), big(0);

	cin >> K >> N;
	vector<string>num(N, "");

	for (idx = 0; idx < K; ++idx) {
		cin >> num[idx];
		big = max(big, stoi(num[idx]));
	}

	for (idx; idx < N; ++idx) {
		num[idx] = to_string(big);
	}
	sort(num.begin(), num.end(), cmp);

	for (idx = 0; idx < N; ++idx) {
		cout << num[idx];
	}
}

//문제풀이: https://githubseob.tistory.com/204