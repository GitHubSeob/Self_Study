#include <string>
#include <vector>
#include <queue>
#define MAX 2000000
using namespace std;

vector<vector<int>>fare;
int n1;

struct cmp {
    bool operator()(pair<int, int>a, pair<int, int>b) {
        return a.second > b.second;
    }
};

vector<int> Dijkstra(int start) {
    int idx(0), n_fare(0), next(0), node(0), o_fare(0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>pq;
    vector<int>fare_AB(n1 + 1, MAX);
    fare_AB[start] = 0;
    pq.push({ start, 0 });

    while (!pq.empty()) {
        node = pq.top().first;
        o_fare = pq.top().second;
        pq.pop();
        for (next = 1; next <= n1; ++next) {
            if (fare[node][next] != 0) {
                n_fare = fare[node][next];
                if (fare_AB[next] > o_fare + n_fare) {
                    fare_AB[next] = o_fare + n_fare;
                    pq.push({ next, fare_AB[next] });
                }
            }
        }
    }
    return fare_AB;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer(MAX), idx(0);
    n1 = n;
    fare = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
    vector<int>fare_A;
    vector<int>fare_B;
    vector<int>fare_S;

    for (idx = 0; idx < fares.size(); ++idx) {
        fare[fares[idx][0]][fares[idx][1]] = fares[idx][2];
        fare[fares[idx][1]][fares[idx][0]] = fares[idx][2];
    }

    fare_A = Dijkstra(a);
    fare_B = Dijkstra(b);
    fare_S = Dijkstra(s);

    for (idx = 1; idx <= n; ++idx) {
        answer = min(answer, fare_A[idx] + fare_B[idx] + fare_S[idx]);
    }

    return answer;
}