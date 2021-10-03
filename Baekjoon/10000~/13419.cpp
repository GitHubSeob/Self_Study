#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int T(0);
	string data("");

	int idx(0);
	cin >> T;
	while (T--) {
		cin >> data;
		string first("");
		string second("");
		for (idx = 0; idx < data.size(); ++idx) {
			if (idx % 2 == 0) first += data[idx];
			else second += data[idx];
		}
		if (data.size() % 2 == 1) {
			string copy(first);
			first += second;
			second += copy;
		}
		cout << first << '\n' << second << '\n';
	}
}

//문제풀이: https://githubseob.tistory.com/123