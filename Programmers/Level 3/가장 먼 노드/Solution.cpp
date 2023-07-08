#include <vector>
#include <queue>
#include <algorithm>
#define MAX 50001
using namespace std;

int node_cnt, answer;
vector<vector<bool>>graph;

void Dijkstra(int start_node) {
    int next(0), node(0), dist(0), n_dist(0), max_dist(0);
    priority_queue<pair<int, int>>pq;
    vector<int>dist_v(node_cnt + 1, MAX);
    dist_v[start_node] = 0;
    pq.push({ 0, start_node });

    while (!pq.empty()) {
        dist = -pq.top().first;
        node = pq.top().second;
        pq.pop();

        for (next = 1; next <= node_cnt; ++next) {
            n_dist = graph[node][next];
            if (n_dist == 0) continue;
            if (dist_v[next] > dist + n_dist) {
                dist_v[next] = dist + n_dist;
                pq.push({ -dist_v[next], next });
            }
        }
    }
    for (next = 1; next <= node_cnt; ++next) {
        if (max_dist < dist_v[next]) {
            answer = 1;
            max_dist = dist_v[next];
        }
        else if (max_dist == dist_v[next]) {
            answer++;
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int idx(0), idx2(0);
    node_cnt = n;
    graph = vector<vector<bool>>(n + 1, vector<bool>(n + 1, false));

    for (idx = 0; idx < edge.size(); ++idx) {
        graph[edge[idx][0]][edge[idx][1]] = 1;
        graph[edge[idx][1]][edge[idx][0]] = 1;
    }

    Dijkstra(1);

    return answer;
}