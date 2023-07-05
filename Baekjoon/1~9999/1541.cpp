#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int idx(0), sum(0);
	string expression("");
	string s_num("");
	bool minus(false);

	cin >> expression;
	expression += '+';

	for (idx = 0; idx < expression.size(); ++idx) {
		if (expression[idx] == '-' || expression[idx] == '+') {
			minus == true ? sum -= stoi(s_num) : sum += stoi(s_num);

			if (expression[idx] == '-') {
				minus = true;
			}
			s_num = "";
		}
		else {
			s_num += expression[idx];
		}
	}

	cout << sum;
}

//문제풀이: https://githubseob.tistory.com/276