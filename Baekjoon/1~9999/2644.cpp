#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
vector<vector<int>>relation;
vector<bool>visit;

int start;
int arrive;

int Bfs() {
    queue<pair<int, int>> q;
    q.push({ start,0 });
    while (!q.empty()) {
        int x = q.front().first;
        int answer = q.front().second;
        visit[x] = true;
        if (x == arrive)
            return answer;
        q.pop();
        for (int cnt = 0; cnt < relation[x].size(); ++cnt) {
            if(!visit[relation[x][cnt]])
            q.push({ relation[x][cnt],answer + 1 });
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 0;
    int num = 0;
    cin >> n;
    cin >> start >> arrive;
    cin >> num;

    relation.resize(n + 1, vector<int>(0, 0));
    visit.resize(n + 1, false);

    for (int i = 0; i < num; ++i) {
        int n1 = 0;
        int n2 = 0;
        cin >> n1 >> n2;
        relation[n1].push_back(n2);
        relation[n2].push_back(n1);
        visit[n1] = visit[n2] = false;
    }

    cout << Bfs();
}

//문제풀이: https://githubseob.tistory.com/13