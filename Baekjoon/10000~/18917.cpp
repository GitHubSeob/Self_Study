#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int M(0);
	cin >> M;

	ll cmd(0), num(0);
	ll sum(0), XOR(0);

	for (int idx = 0; idx < M; ++idx) {
		cin >> cmd;
		if (cmd == 1) {
			cin >> num;
			XOR ^= num;
			sum += num;
		}
		else if (cmd == 2) {
			cin >> num;
			sum -= num;
			XOR ^= num;
		}
		else if (cmd == 3) {
			cout << sum << '\n';
		}
		else if (cmd == 4) {
			cout << XOR << '\n';
		}
	}
}

//문제풀이: https://githubseob.tistory.com/341