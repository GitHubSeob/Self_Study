#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct cmp {
    bool operator()(vector<int>a, vector<int>b) {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer(0), idx(0), prev(0);
    sort(jobs.begin(), jobs.end());
    priority_queue<vector<int>, vector<vector<int>>, cmp>pq;

    for (idx = 0; idx < jobs.size();) {
        if (jobs[idx][0] <= prev) {
            pq.push(jobs[idx]);
            idx++;
        }
        else {
            if (pq.empty()) {
                prev = jobs[idx][0];
            }
            else {
                answer += (prev + pq.top()[1] - pq.top()[0]);
                prev += pq.top()[1];
                pq.pop();
            }
        }
    }
    while (!pq.empty()) {
        answer += (prev + pq.top()[1] - pq.top()[0]);
        prev += pq.top()[1];
        pq.pop();
    }

    return answer / jobs.size();
}