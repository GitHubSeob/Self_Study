#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T(0), idx(0), n(0);
	int cnt(0);
	string p(""), num("");
	string str("");

	cin >> T;

	while (T--) {
		int start(0), end(0);
		int rev(1);
		vector<int>arr;
		cin >> p >> n;
		cin >> num;
		num.erase(0, 1);
		num.erase(num.size() - 1, 1);

		istringstream istr(num);

		while (getline(istr, str, ',')) {
			arr.push_back(stoi(str));
			end++;
		}
		for (idx = 0; idx < p.size(); ++idx) {
			if (p[idx] == 'R') {
				rev *= -1;
			}
			else {
				if (rev == 1) {
					++start;
				}
				else {
					--end;
				}
			}
		}
		if (start > end) {
			cout << "error\n";
		}
		else if (start == end)
			cout << "[]\n";
		else {
			cout << '[';
			if (rev == 1) {
				for (idx = start; idx + 1 < end; ++idx) {
					cout << arr[idx] << ',';
				}
				cout << arr[idx];
			}
			else {
				for (idx = end - 1; idx > start; --idx) {
					cout << arr[idx] << ',';
				}
				cout << arr[idx];
			}
			cout << "]\n";
		}
	}
}

//문제풀이: https://githubseob.tistory.com/194