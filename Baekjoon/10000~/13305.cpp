#include <iostream>
#include <vector>
#define MAX 1000000000
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll idx(0), N(0), min_price(MAX), answer(0);
	cin >> N;
	vector<ll>road(N - 1, 0);
	vector<ll>price(N, 0);

	for (idx = 0; idx < N - 1; ++idx) {
		cin >> road[idx];
	}
	for (idx = 0; idx < N; ++idx) {
		cin >> price[idx];
	}

	for (idx = 0; idx < N - 1; ++idx) {
		min_price = min(min_price, price[idx]);
		answer += min_price * road[idx];
	}

	cout << answer;
}

//문제풀이: https://githubseob.tistory.com/269