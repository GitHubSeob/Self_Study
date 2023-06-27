#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


struct cmp {
    bool operator()(pair<int, int>a, pair<int, int>b) {
        if (a.first == b.first)
            return a.second > b.second;
        else
            return a.first < b.first;
    }
};

vector<int> solution(int e, vector<int> starts) {
    int start(0), idx(0), idx2(0);
    vector<int>order(e + 1, 0);
    vector<int>num(e + 1, 0);
    vector<int> answer(starts.size(), 0);        
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>pq;

    for (idx = 0; idx < starts.size(); ++idx) {
        order[starts[idx]] = idx;
    }

    sort(starts.begin(), starts.end());

    for (idx = 1; idx * idx <= e; ++idx) {
        num[idx * idx] = 1;
        for (idx2 = idx + 1; idx * idx2 <= e; ++idx2) {
            num[idx * idx2] += 2;
        }
    }
    
    for (idx = 1; idx <= e; ++idx) {
        pq.push({ num[idx],idx });
    }

    for (idx = 0; idx < starts.size(); ++idx) {
        while (1) {
            if (starts[idx] <= pq.top().second) {
                answer[order[starts[idx]]] = pq.top().second;
                break;
            }
            else {
                pq.pop();
            }
        }
    }
    return answer;
}