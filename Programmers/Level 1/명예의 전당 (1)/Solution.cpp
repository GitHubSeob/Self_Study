#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>>rating;
    int idx(0);
    for (idx = 0; idx < score.size(); ++idx) {
        if (rating.size() < k) {
            rating.push(score[idx]);
        }
        else if (rating.top() < score[idx]) {
            rating.push(score[idx]);
            rating.pop();
        }
        answer.push_back(rating.top());

    }
    return answer;
}