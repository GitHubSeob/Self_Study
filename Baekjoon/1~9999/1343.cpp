#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string board(""), block(""), answer("");
	cin >> board;

	istringstream istr(board);

	while (getline(istr, block, '.')) {
		if (block.size() % 2 == 1) {
			cout << -1;
			return 0;
		}
		else {
			fill(block.begin(), block.end(), 'B');
			fill(block.begin(), block.begin() + block.size() / 4 * 4, 'A');
			answer += block;
		}
		if (answer.size() != board.size()) {
			answer += '.';
		}
	}
	cout << answer;
}

//문제풀이: https://githubseob.tistory.com/267