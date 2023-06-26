#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer(0), sum(0);
    int idx(0);
    priority_queue<int>pq;

    for (idx = 0; idx < works.size(); ++idx) {
        pq.push(works[idx]);
        sum += works[idx];
    }

    if (sum <= n)
        return 0;

    while (n--) {
        pq.push(pq.top() - 1);
        pq.pop();
    }
    while (!pq.empty()) {
        answer += (pow(pq.top(), 2));
        pq.pop();
    }

    return answer;
}