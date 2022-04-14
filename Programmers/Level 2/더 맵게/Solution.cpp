#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int idx(0);
    int num1(0), num2(0);

    priority_queue<int, vector<int>, greater<int>> pq;
    for (idx = 0; idx < scoville.size(); ++idx) {
        pq.push(scoville[idx]);
    }

    while (pq.size() > 1) {
        if (pq.top() >= K)
            break;
        num1 = pq.top();
        pq.pop();
        num2 = pq.top();
        pq.pop();
        pq.push(num1 + num2 * 2);
        answer++;
    }

    if (pq.top() < K)
        return -1;

    return answer;
}