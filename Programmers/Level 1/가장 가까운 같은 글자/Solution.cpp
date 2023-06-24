#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    int idx(0);
    vector<int> answer;
    vector<int>alp(26, -1);
    for (idx = 0; idx < s.size(); ++idx) {
        if (alp[s[idx] - 'a'] == -1) {
            answer.push_back(-1);
        }
        else {
            answer.push_back(idx - alp[s[idx] - 'a']);
        }
        alp[s[idx] - 'a'] = idx;
    }
    return answer;
}