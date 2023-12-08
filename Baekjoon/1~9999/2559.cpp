#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), K(0);
	cin >> N >> K;

	vector<int>temp(N, 0);
	int answer(0), sum(0);	

	for (int idx = 0; idx < N; ++idx) cin >> temp[idx];
	
	for (int idx = 0; idx < K; ++idx) sum += temp[idx];

	answer = sum;

	for (int idx = K; idx < N; ++idx) {
		sum -= temp[idx - K];
		sum += temp[idx];
		answer = max(answer, sum);		
	}

	cout << answer;
}

//문제풀이: https://githubseob.tistory.com/365