#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int>q;
    int idx(0);
    int num(0);
    int cnt(1);
    
    for (idx = 0; idx < speeds.size(); ++idx) {
        if ((100 - progresses[idx]) % speeds[idx] > 0) {
            q.push((100 - progresses[idx]) / speeds[idx] + 1);
        }
        else
            q.push((100 - progresses[idx]) / speeds[idx]);
    }

    while (!q.empty()) {
        num = q.front();
        q.pop();
        while (!q.empty() && num >= q.front()) {
            cnt++;
            q.pop();
        }
        answer.push_back(cnt);
        cnt = 1;
    }

    return answer;
}