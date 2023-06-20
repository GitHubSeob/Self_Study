#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

bool cmp(string s1, string s2) {
	int idx(0), idx2(0);
	string n1(""), r1(""), n2(""), r2("");
	while (1) {
		if (idx >= s1.size() || idx >= s2.size()) {
			return s1.size() < s2.size();
		}
		else if (isdigit(s1[idx]) || isdigit(s2[idx])) {
			n1 = "", r1 = "", n2 = "", r2 = "";
			idx2 = idx;
			while (isdigit(s1[idx2])) {
				if (s1[idx2] == '0' && !r1.empty()) {
					r1 += s1[idx2];
				}
				else if (s1[idx2] != '0') {
					r1 += s1[idx2];
				}
				n1 += s1[idx2];
				++idx2;
			}
			idx2 = idx;

			while (isdigit(s2[idx2])) {
				if (s2[idx2] == '0' && !r2.empty()) {
					r2 += s2[idx2];
				}
				else if (s2[idx2] != '0') {
					r2 += s2[idx2];
				}
				n2 += s2[idx2];
				++idx2;
			}
			if (n1.empty()) {
				return false;
			}
			else if (n2.empty()) {
				return true;
			}
			else {
				if (n1 == n2);
				else if (r1 == r2) {
					return n1.size() < n2.size();
				}
				else if (r1.size() == r2.size()) {
					return r1 < r2;
				}
				else {
					return r1.size() < r2.size();
				}
			}
		}
		else if (!isdigit(s1[idx]) && !isdigit(s2[idx])) {
			if (s1[idx] == s2[idx]);
			else if (tolower(s1[idx]) == tolower(s2[idx])) {
				return s1[idx] < s2[idx];
			}
			else {
				return tolower(s1[idx]) < tolower(s2[idx]);
			}
		}
		++idx;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), idx(0);
	cin >> N;
	vector<string>words(N, "");

	for (idx = 0; idx < N; ++idx) {
		cin >> words[idx];
	}

	sort(words.begin(), words.end(), cmp);

	for (idx = 0; idx < N; ++idx) {
		cout << words[idx] << '\n';
	}
}

//문제풀이: https://githubseob.tistory.com/211