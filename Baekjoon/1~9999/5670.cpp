#include <bits/stdc++.h>
using namespace std;

int total;

struct Trie {
	Trie* child[26];
	int cnt;
	bool isEnd;

	Trie() :child(), cnt(0), isEnd(false) {}
	~Trie() {
		for (int idx = 0; idx < 26; ++idx) {
			if (child[idx]) delete child[idx];
		}
	}

	void insert(string& s) {
		Trie* now = this;
		for (int idx = 0; idx < s.size(); ++idx) {
			if (now->child[s[idx] - 'a'] == nullptr) {
				now->child[s[idx] - 'a'] = new Trie();
				++now->cnt;
			}
			now = now->child[s[idx] - 'a'];
			if (idx + 1 == s.size()) now->isEnd = true;
		}
	}

	void search(string& s) {
		Trie* now = this;		
		bool prev(true);		
		for (int idx = 0; idx < s.size(); ++idx) {
			if (prev == false && now->cnt == 1)
				--total;

			if (now->child[s[idx] - 'a'] != nullptr)
				now = now->child[s[idx] - 'a'];
				
			if (now->isEnd == true)	prev = true;
			else prev = false;
		}
	}

};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0);

	while (cin >> N) {
		vector<string>dict(N, "");
		total = 0;
		Trie* trie = new Trie();
		for (int idx = 0; idx < N; ++idx) {
			cin >> dict[idx];
			trie->insert(dict[idx]);
		}

		for (int idx = 0; idx < N; ++idx) {
			trie->search(dict[idx]);
			total += dict[idx].size();
		}

		cout << fixed;
		cout.precision(2);
		cout << (double)total / N << '\n';

		delete trie;
	}
}

//문제풀이: https://githubseob.tistory.com/321