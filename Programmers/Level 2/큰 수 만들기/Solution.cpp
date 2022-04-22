#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<char>s;
    int idx(0), rest(0);
    int answer_size(number.size() - k);

    s.push(number[0]);
    for (idx = 1; idx < number.size(); ++idx) {
        rest = number.size() - idx;
        if (s.size() + rest == answer_size) {
            s.push(number[idx]);
            continue;
        }
        while (!s.empty() && rest + s.size() > answer_size && s.top() < number[idx]) {
            s.pop();
        }
        if (s.size() < answer_size) {
            s.push(number[idx]);
        }
    }

    while (!s.empty()) {
        answer += s.top();
        s.pop();
    }

    reverse(answer.begin(), answer.end());
    return answer;
}