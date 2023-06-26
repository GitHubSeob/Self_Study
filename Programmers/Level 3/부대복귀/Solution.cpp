#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    int idx(0), num(0), cnt(0);
    queue<vector<int>>q;
    vector<int>visit(n + 1, -1);
    vector<int>answer(sources.size(), 0);    
    vector<vector<int>>road(n + 1, vector<int>(0, 0));

    for (idx = 0; idx < roads.size(); ++idx) {
        road[roads[idx][0]].push_back(roads[idx][1]);
        road[roads[idx][1]].push_back(roads[idx][0]);
    }

    q.push({ destination,0 });
    visit[destination] = 0;

    while (!q.empty()) {
        num = q.front()[0];
        cnt = q.front()[1];
        q.pop();

        for (idx = 0; idx < road[num].size(); ++idx) {
            int next = road[num][idx];
            if (visit[next] == -1) {
                visit[next] = cnt + 1;
                q.push({ next, cnt + 1 });
            }
        }
    }
    for (idx = 0; idx < sources.size(); ++idx) {
        answer[idx] = visit[sources[idx]];
    }

    return answer;
}