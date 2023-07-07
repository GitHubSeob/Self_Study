#include <iostream>
#include <string>
using namespace std;

string largest(string num) {
	int idx(0), idx2(0), m_cnt(0);
	string answer("");

	for (idx = 0; idx < num.size(); ++idx) {
		if (num[idx] == 'M') {
			++m_cnt;
		}
		else if (num[idx] == 'K') {
			answer += '5';
			answer.insert(answer.size(), m_cnt, '0');
			m_cnt = 0;

		}
		if (idx + 1 == num.size()) {
			answer.insert(answer.size(), m_cnt, '1');
		}
	}
	return answer;
}

string smallest(string num) {
	int idx(0), idx2(0), m_cnt(0);
	string answer("");

	for (idx = 0; idx < num.size(); ++idx) {
		if (num[idx] == 'M') {
			(idx == 0 || num[idx - 1] == 'K') ? answer += '1' : answer += '0';
		}
		else if (num[idx] == 'K') {
			answer += '5';
		}
	}
	return answer;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int idx(0);
	string num("");
	cin >> num;

	cout << largest(num) << '\n';
	cout << smallest(num);
}

//문제풀이: https://githubseob.tistory.com/283