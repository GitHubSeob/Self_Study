#include <iostream>
using namespace std;

int main() {
	int T(0);
	int idx(0);
	cin >> T;
	string number("");

	while (T--) {
		int answer(0);
		cin >> number;
		for (idx = number.size() - 1; idx >= 0; --idx) {
			if (idx % 2 == 0) {
				int mul((number[idx] - '0') * 2);
				if (mul >= 10)	answer += (mul / 10 + mul % 10);
				else answer += mul;
			}
			else answer += number[idx]-'0';
		}
		if (answer % 10 == 0) cout << 'T';
		else cout << 'F';
		cout << '\n';
	}
}

//문제풀이: https://githubseob.tistory.com/124