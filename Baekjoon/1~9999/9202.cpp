#include <bits/stdc++.h>
using namespace std;

unordered_set<string>dict;
unordered_set<string>target;
int max_score;
string max_str;

vector<vector<char>>board;
vector<vector<bool>>visited;

int dy[8] = { -1,-1,-1,0,0,1,1,1 };
int dx[8] = { -1,0,1,-1,1,-1,0,1 };
int score[9] = { 0,0,0,1,1,2,3,5,11 };

struct Trie {
	Trie* child[26];
	bool isEnd;

	Trie() : child(), isEnd(false) {}

	~Trie() {
		for (int idx = 0; idx < 26; ++idx)
			if (child[idx]) delete child[idx];
	}

	void insert(string& str) {
		Trie* now = this;
		for (int idx = 0; idx < str.size(); ++idx) {			
			if (now->child[str[idx] - 'A'] == nullptr) {
				now->child[str[idx] - 'A'] = new Trie();
			}
			now = now->child[str[idx] - 'A'];
			if (idx == str.size() - 1) 	now->isEnd = true;
		}
	}
};

void findWord(int y, int x, Trie* trie, string str) {
	for (int idx = 0; idx < 8; ++idx) {		
		int ny = y + dy[idx];
		int nx = x + dx[idx];
		if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4) continue;
		if (visited[ny][nx] == true) continue;
		if (trie->child[board[ny][nx]-'A'] != nullptr) {
			string nstr = str;
			nstr += board[ny][nx];			
			Trie* ntrie = trie->child[board[ny][nx] - 'A'];			
			if (ntrie->isEnd == true) {
				if (target.find(nstr) != target.end() && dict.find(nstr) == dict.end()) {
					dict.insert(nstr);
					max_score += score[nstr.size()];
					if (max_str.size() == nstr.size()) {
						if (max_str > nstr) max_str = nstr;
					}
					else if (max_str.size() < nstr.size()) max_str = nstr;
				}
			}
			visited[ny][nx] = true;			
			findWord(ny, nx, ntrie, nstr);
			visited[ny][nx] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int w(0);
	cin >> w;
	Trie* trie = new Trie();	
	string word("");

	for (int idx = 0; idx < w; ++idx) {
		cin >> word;
		target.insert(word);
		trie->insert(word);
	}		
	
	int T(0);	
	
	cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		board = vector<vector<char>>(4, vector<char>(4, ' '));
		visited = vector<vector<bool>>(4, vector<bool>(4, false));
		dict.clear();
		max_score = 0;
		max_str.clear();

		for (int y = 0; y < 4; ++y) {
			for (int x = 0; x < 4; ++x) {
				cin >> board[y][x];
			}
		}

		for (int y = 0; y < 4; ++y) {
			for (int x = 0; x < 4; ++x) {
				string str("");
				str += board[y][x];
				visited[y][x] = true;
				if (trie->child[board[y][x] - 'A'] != nullptr) {					
					Trie* ntrie = trie->child[board[y][x] - 'A'];					
					findWord(y, x, ntrie, str);
				}
				visited[y][x] = false;
			}
		}
		cout << max_score << " " << max_str << " " << dict.size() << '\n';
	}
}

//문제풀이: https://githubseob.tistory.com/322