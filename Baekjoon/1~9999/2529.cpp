#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int k, idx;
vector<char>input;
vector<int>num(10, 0);

void biggest() {
	do {
		for (idx = 1; idx <= k; ++idx) {
			char sign = input[idx - 1];
			if (sign == '<') {
				if (num[idx - 1] >= num[idx]) {
					break;
				}
			}
			else if (sign == '>') {
				if (num[idx - 1] <= num[idx]) {
					break;
				}
			}
		}
		if (idx == k + 1) {
			for (idx = 0; idx <= k; ++idx) {
				cout << num[idx];
			}
			cout << '\n';
			return;
		}
	} while (prev_permutation(num.begin(), num.end()));
}

void smallest() {
	sort(num.begin(), num.end());
	do {
		for (idx = 1; idx <= k; ++idx) {
			char sign = input[idx - 1];
			if (sign == '<') {
				if (num[idx - 1] >= num[idx]) {
					break;
				}
			}
			else if (sign == '>') {
				if (num[idx - 1] <= num[idx]) {
					break;
				}
			}
		}
		if (idx == k + 1) {
			for (idx = 0; idx <= k; ++idx) {
				cout << num[idx];
			}
			return;
		}
	} while (next_permutation(num.begin(), num.end()));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> k;

	input = vector<char>(k, ' ');

	for (idx = 0; idx < k; ++idx)
		cin >> input[idx];

	for (idx = 0; idx < 10; ++idx)
		num[9 - idx] = idx;

	biggest();
	smallest();
}

//문제풀이: https://githubseob.tistory.com/202