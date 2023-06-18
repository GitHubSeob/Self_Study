#include <iostream>
#include <string>
using namespace std;
string s;
int answer;

void DFS(int left, int right, int cnt) {
	if (left >= right) {
		answer = min(answer, cnt);
		return;
	}
	else if (cnt >= 2) {
		return;
	}
	else if (s[left] != s[right]) {
		if (s[left + 1] == s[right])
			DFS(left + 1, right, cnt + 1);
		if (s[left] == s[right - 1])
			DFS(left, right - 1, cnt + 1);
	}
	else {
		DFS(left + 1, right - 1, cnt);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T(0);
	cin >> T;
	while (T--) {
		cin >> s;
		answer = 2;
		DFS(0, s.size() - 1, 0);
		cout << answer << '\n';
	}
}

//문제풀이: https://githubseob.tistory.com/207