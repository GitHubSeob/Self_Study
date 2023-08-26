#include <bits/stdc++.h>
using namespace std;

struct Trie {
	map<string, Trie*> child;
	int depth;
	bool isEnd;

	Trie() : child(), depth(0), isEnd(false) {}

	void insert(vector<string>& v) {
		Trie* now = this;
		for (int idx = 0; idx < v.size(); ++idx) {
			if (now->child.find(v[idx]) == now->child.end()) {
				now->child[v[idx]] = new Trie();
			}
			now->child[v[idx]]->depth = now->depth + 1;
			now = now->child[v[idx]];

			if (idx + 1 == v.size()) now->isEnd = true;
		}
	}
	void print() {
		Trie* now = this;
		for (auto iter = now->child.begin(); iter != now->child.end(); ++iter) {
			for (int idx = 0; idx < now->depth; ++idx) cout << "--";
			cout << iter->first << '\n';
			iter->second->print();
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), K(0);
	cin >> N;
	Trie* trie = new Trie();
	for (int idx = 0; idx < N; ++idx) {
		cin >> K;
		vector<string>words(K, "");
		for (int idx2 = 0; idx2 < K; ++idx2) {
			cin >> words[idx2];
		}
		trie->insert(words);
	}
	trie->print();
}

//문제풀이: https://githubseob.tistory.com/320