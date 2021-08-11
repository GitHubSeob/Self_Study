#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

vector<pair<int, int>>cvs;
vector<bool>visit;
pair<int, int>rock;
int start_y, start_x;
int n;
int i;

void Move() {
	queue<pair<int, int>>q;
	q.push({ start_y, start_x });
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (abs(y - rock.first) + abs(x - rock.second) <= 1000) {
			cout << "happy";
			return;
		}
		else {
			for (i = 0; i < cvs.size(); ++i) {
				if (abs(y - cvs[i].first) + abs(x - cvs[i].second) <= 1000) {
					if (!visit[i]) {
						visit[i] = true;
						q.push({ cvs[i].first, cvs[i].second });
					}
				}
			}
		}
	}
	cout << "sad";
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 0;
	cin >> t;
	while (t--) {
		cin >> n;

		cvs = vector<pair<int, int>>(n, { 0,0 });
		visit = vector<bool>(n, false);

		cin >> start_y >> start_x;

		for (i = 0; i < n; ++i) {
			cin >> cvs[i].first >> cvs[i].second;
		}
		cin >> rock.first >> rock.second;
		Move();
		cout << "\n";
	}
}

//문제풀이: https://githubseob.tistory.com/34