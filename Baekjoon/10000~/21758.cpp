#include <iostream>
#include <vector>
#include <algorithm>
#define MAX honey.size() -1
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int  N(0), idx(0), sum(0), answer(0);
	int left(0), right(0), wasted_honey(0), bee1(0), bee2(0);
	cin >> N;

	vector<int>honey(N, 0);

	for (idx = 0; idx < N; ++idx) {
		cin >> honey[idx];
		sum += honey[idx];
	}

	for (idx = 1; idx < MAX; ++idx) {
		answer = max(answer, sum - (honey[0] + honey[MAX]) + honey[idx]);
	}

	wasted_honey = honey[0];
	for (right = 1; right < MAX; ++right) {
		bee1 = sum - (honey[0] + honey[right]);
		wasted_honey += honey[right];
		bee2 = sum - wasted_honey;

		answer = max(answer, bee1 + bee2);
	}

	wasted_honey = honey[MAX];
	for (left = MAX - 1; left > 0; --left) {
		bee2 = sum - (honey[MAX] + honey[left]);
		wasted_honey += honey[left];
		bee1 = sum - wasted_honey;

		answer = max(answer, bee1 + bee2);
	}

	cout << answer;
}

//문제풀이: https://githubseob.tistory.com/271