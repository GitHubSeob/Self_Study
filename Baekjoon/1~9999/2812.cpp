#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), K(0), idx(0), cnt(0);
	string num(""), answer("");
	stack<char>s;
	cin >> N >> K >> num;

	for (idx = 0; idx < N; ++idx) {		
		while (cnt < K && !s.empty() && s.top() < num[idx]) {			
			s.pop();
			cnt++;
		}
		s.push(num[idx]);		
	}
	while (cnt < K) {
		s.pop();
		++cnt;
	}

	while (!s.empty()) {
		answer += s.top();
		s.pop();
	}

	reverse(answer.begin(), answer.end());
	cout << answer;
}

//문제풀이: https://githubseob.tistory.com/277