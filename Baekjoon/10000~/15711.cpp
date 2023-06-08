#include <iostream>
#include <vector>
#include <cmath>
using  namespace std;
#define MAX_N 2000000

vector<bool>isPrime(MAX_N + 1, true);
vector<long long>prime;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long T(0), A(0), B(0), C(0), idx(0), idx2(0);
	cin >> T;

	for (idx = 2; idx < sqrt(MAX_N); ++idx) {
		for (idx2 = 2; idx2 * idx < MAX_N; ++idx2) {
			isPrime[idx * idx2] = false;
		}
	}
	for (idx = 2; idx < isPrime.size(); ++idx) {
		if (isPrime[idx] == true)
			prime.push_back(idx);
	}

	while (T--) {
		cin >> A >> B;
		C = A + B;
		if (C <= 3) cout << "NO\n";
		else if (C % 2 == 0) cout << "YES\n";
		else {
			bool answer(true);
			C -= 2;
			for (idx = 0; prime[idx] <= sqrt(C); ++idx) {
				if (C % prime[idx] == 0) {
					answer = false;
					break;
				}
			}
			if (answer == true)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}

//문제풀이: https://githubseob.tistory.com/201