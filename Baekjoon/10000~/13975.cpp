#include <iostream>
#include <queue>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<ll, vector<ll>, greater<ll>>pq;

	int T(0), K(0), idx(0);
	ll file1(0), file2(0), answer(0);

	cin >> T;
	while (T--) {
		cin >> K;
		answer = 0;
		for (idx = 0; idx < K; ++idx) {
			cin >> file1;
			pq.push(file1);
		}
		while (pq.size() > 1) {
			file1 = pq.top();
			pq.pop();
			file2 = pq.top();
			pq.pop();
			pq.push(file1 + file2);
			answer += (file1 + file2);
		}
		pq.pop();
		cout << answer << '\n';
	}
}

//문제풀이: https://githubseob.tistory.com/284