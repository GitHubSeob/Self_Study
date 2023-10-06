#include <bits/stdc++.h>
using namespace std;

vector<string>gear(4);
vector<string>prev_gear(4);

void rotate(int loc, int dir) {
	if (dir == 1) {
		gear[loc].insert(0, 1, gear[loc].back());
		gear[loc].erase(8, 1);
	}
	else if (dir == -1) {
		gear[loc] += gear[loc][0];
		gear[loc].erase(0, 1);
	}
}

void left_gear(int num, int dir) {
	for (int left = num - 1; left >= 0; --left) {
		if (prev_gear[left][2] == prev_gear[left + 1][6]) break;
		rotate(left, dir);
		dir *= -1;
	}
}

void right_gear(int num, int dir) {
	for (int right = num + 1; right < 4; ++right) {
		if (prev_gear[right - 1][2] == prev_gear[right][6]) break;
		rotate(right, dir);
		dir *= -1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int idx = 0; idx < 4; ++idx) {
		cin >> gear[idx];
		prev_gear[idx] = gear[idx];
	}

	int K(0);
	cin >> K;

	int num(0), dir(0);
	for (int idx = 0; idx < K; ++idx) {
		cin >> num >> dir;
		--num;

		rotate(num, dir);
		left_gear(num, dir * -1);
		right_gear(num, dir * -1);

		for (int idx2 = 0; idx2 < 4; ++idx2) {
			prev_gear[idx2] = gear[idx2];
		}
	}

	int answer(0), score(1);
	for (int idx = 0; idx < 4; ++idx) {
		if (gear[idx][0] != '0') answer += score;
		score *= 2;
	}
	cout << answer;
}