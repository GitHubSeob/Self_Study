#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>>virus;
vector<bool>visit;
int answer = 0;

void DFS(int start) {
	visit[start] = true;
	for (int cnt = 0; cnt < virus[start].size(); ++cnt) {
		if (!visit[virus[start][cnt]]) {
			DFS(virus[start][cnt]);
			answer++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int computer = 0;
	int pair = 0;
	int y = 0, x = 0;
	int num1 = 0, num2;
	cin >> computer;
	cin >> pair;
	virus = vector<vector<int>>(computer + 1, vector<int>(0, 0));
	visit = vector<bool>(computer + 1, false);

	for (y = 0; y < pair; ++y) {
		cin >> num1 >> num2;
		virus[num1].push_back(num2);
		virus[num2].push_back(num1);
	}

	DFS(1);

	cout << answer;
}

//문제풀이: https://githubseob.tistory.com/25