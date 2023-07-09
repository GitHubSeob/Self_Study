#include <string>
#include <vector>
#define MAX 1000000
using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

vector<vector<int>>road;
vector<vector<vector<int>>>visited;
int answer(MAX);

void DFS(int y, int x, int cost, int prev) {
    int idx(0), ny(0), nx(0), n_cost(0);
    if (y == road.size() - 1 && x == road[0].size() - 1) {
        answer = min(answer, cost);
        return;
    }
    for (idx = 0; idx < 4; ++idx) {
        ny = y + dy[idx];
        nx = x + dx[idx];
        n_cost = cost + 100;
        if (0 <= ny && ny < road.size() && 0 <= nx && nx < road[0].size()) {
            if (road[ny][nx] == 1) continue;
            if ((prev == 0 || prev == 1) && (idx == 2 || idx == 3)) {
                n_cost += 500;
            }
            else if ((prev == 2 || prev == 3) && (idx == 0 || idx == 1)) {
                n_cost += 500;
            }

            if (visited[idx][ny][nx] > n_cost) {
                visited[idx][ny][nx] = n_cost;
                DFS(ny, nx, n_cost, idx);
            }
        }
    }
}


int solution(vector<vector<int>> board) {
    int idx(0);
    road = board;
    visited = vector<vector<vector<int>>>(4, vector<vector<int>>(road.size(), vector<int>(road[0].size(), MAX)));

    for (idx = 0; idx < 4; ++idx) {
        visited[idx][0][0] = 0;
    }

    DFS(0, 0, 0, -1);

    return answer;
}