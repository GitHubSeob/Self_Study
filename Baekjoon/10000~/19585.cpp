#include <bits/stdc++.h>
using namespace std;

struct Color {
	map<char, Color*> child;
	bool isEnd;

	Color() : child(), isEnd(false) {}
	~Color() {
		child.clear();
	}

	void insert(string& str) {
		Color* color = this;
		for (int idx = 0; idx < str.size(); ++idx) {
			if (color->child.find(str[idx]) == color->child.end()) {
				color->child[str[idx]] = new Color();
			}
			color = color->child[str[idx]];
			if (idx + 1 == str.size()) color->isEnd = true;
		}
	}
	int search(char& c);
};

Color* ptr;

int Color::search(char& c) {
	if (ptr->child.find(c) == ptr->child.end()) return -1;
	else {
		if (ptr->child[c]->isEnd == true) {
			ptr = ptr->child[c];
			return 1;
		}
		else {
			ptr = ptr->child[c];
			return 0;
		}
	}
}

unordered_set<string>names;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int C(0), N(0);
	cin >> C >> N;

	Color* color = new Color();
	string input("");
	for (int idx = 0; idx < C; ++idx) {
		cin >> input;
		color->insert(input);
	}
	for (int idx = 0; idx < N; ++idx) {
		cin >> input;
		names.insert(input);
	}

	int Q(0), ret(0);
	cin >> Q;

	for (int idx = 0; idx < Q; ++idx) {
		cin >> input;
		ptr = color;
		bool flag(false);
		for (int idx2 = 0; idx2 < input.size(); ++idx2) {
			ret = color->search(input[idx2]);
			if (ret == 1) {
				string name = input.substr(idx2 + 1);
				if (names.find(name) != names.end()) {
					flag = true;
					break;
				}
			}
			else if (ret == -1) {
				break;
			}
		}
		if (flag == true) cout << "Yes\n";
		else cout << "No\n";
	}
}

//문제풀이: https://githubseob.tistory.com/323