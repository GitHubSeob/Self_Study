#include <iostream>
using namespace std;

int Z(int N, int y, int x) {
	int val(0);
	if (N == 1) return 0;
	N /= 2;
	if (y < N && x < N) {
		val += Z(N, y, x);
	}
	else if (y < N && x >= N) {
		val = N * N;
		val += Z(N, y, x - N);
	}
	else if (y >= N && x < N) {
		val = N * N * 2;
		val += Z(N, y - N, x);
	}
	else if (y >= N && x >= N) {
		val = N * N * 3;
		val += Z(N, y - N, x - N);
	}
	return val;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), r(0), c(0);
	cin >> N >> r >> c;
	
	cout << Z(1 << N, r, c);	
}

//문제풀이: https://githubseob.tistory.com/283